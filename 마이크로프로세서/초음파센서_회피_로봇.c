/*
 * Stepmotor Robot.c
 *
 * Created: 2022-06-11 오후 2:54:50
 * Author : 오민진
 */ 
#define F_CPU 16000000L
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Text_LCD.h"

// 모터를 1스탭 회전시키기 위한 데이터
uint8_t step_data[] = {0x01, 0x02, 0x04, 0x08}; // 1상 여자 방식(바퀴1)
uint8_t step_data2[] = {0x01, 0x02, 0x04, 0x08}; // 1상 여자 방식(바퀴2)
uint8_t MODE = 4; // LCD 4비트 모드
#define PRESCALER 1024 // 초음파 에코핀 펄스폭 계산 분주비
typedef unsigned char uchar;
volatile int dir = 0; // 스텝모터의 진행방향 설정
volatile int step_index = -1; // 현재 상태(바퀴1)
volatile int step_index2 = -1; // 현재 상태(바퀴2)
int distance = 0; // 초음파 센서의 계산된 거리를 받을 전역변수
int count = 0; // 좌회전했을 시, 좌회전 각도조절을 위한 변수
int count2 = 0; // 딜레이 함수 대신 400ms마다 LCD에 distance값을 출력하기 위한 변수

uint8_t stepForward() // 시계 방향 회전(바퀴1)
{
	step_index++; // 0,1,2,3 반복
	if(step_index >= 4)
	step_index = 0;
	return step_data[step_index];
}

uint8_t stepForward2() // 시계 방향 회전(바퀴2)
{
	step_index2++; // 0,1,2,3 반복
	if(step_index2 >= 4)
	step_index2 = 0;
	return step_data2[step_index2];
}

uint8_t stepBackward() // 반시계 방향 회전(바퀴1)
{
	step_index--; // 3,2,1,0 반복
	if(step_index < 0)
	step_index = 3;
	return step_data[step_index];
}

uint8_t stepBackward2() // 반시계 방향 회전(바퀴2)
{
	step_index2--; // 3,2,1,0 반복
	if(step_index2 < 0)
	step_index2 = 3;
	return step_data2[step_index2];
}

void print_LCD(int distance) // LCD에 distance값 출력
{
	static char data[10];
	LCD_clear();
	sprintf(data, "distance: %d", distance);
	LCD_write_string(data);
}

ISR(TIMER1_COMPA_vect) // 스텝모터 진행방향
{
	if(dir == 2) // 좌회전
	{
		if(count == 70) // count가 70이 되면 회전그만
		{
			dir = 1; // 직진 신호로 변경
		}
		// count가 70이 아니라면 좌회전 계속
		PORTB = stepForward();
		PORTD = stepForward2();
		count += 1;
	}
	if(dir == 1) // 직진
	{
		count = 0; // 좌회전에서 직진신호가 되었을 때 초기화를 위한 식
		if(distance < 10) // 거리가 10미만이 되면
		{
			dir = 2; // 좌회전 신호로 변경
		}
		// 거리가 10이상이면 직진 계속
		PORTB = stepForward();
		PORTD = stepBackward2();
	}
	if(dir == 0) // 정지
	{
		count = 0; // 혹시 모를 중복 방지
	}
}

uchar read_switch(uchar sw_id)
{
	static uchar state_prev[] = {1, 1, 1, 1, 1, 1, 1, 1};
	// sw_id 버튼의 현재 상태 읽기
	uchar state_curr = (PINC >> sw_id) & 0x01;
	uchar result = 0;
	// 1: 안눌림, 0: 눌림, 스위치가 눌리기 시작했을 때 (하강에지)
	if(state_curr == 0 && state_prev[sw_id] == 1)
	{
		_delay_ms(20);        // 디바운스
		state_curr = (PINC >> sw_id) & 0x01;
		if(state_curr == 0)    // 스위치 눌림 한번 더 확인
		result = 1;
	}
	// 현재 상태를 과거 상태에 저장
	state_prev[sw_id] = state_curr;
	return result;
}

void DDR_init(void)
{
	DDRB = 0x0F; // 모터 제어핀 출력으로 설정(바퀴1)
	DDRD = 0x0F; // 모터 제어핀 출력으로 설정(바퀴2)
	DDRG |= 0x02; // PG1, 트리거 핀 출력으로 설정
	DDRG &= 0xFE; // PG0, 에코핀 입력을 설정
	DDRC = 0x00; // 스위치 5,6,7 사용을 위해 입력으로 설정
	DDRE = 0xFF; // LED 출력을 설정
	DDRA = 0xFF; // LCD 출력을 설정
}

void Timer1_init(void) // 스텝모터에 사용될 1번 타이머/카운터 설정
{
	// 4번 CTC모드 // 분주비 1024 // 비교일치인터럽트 활성화
	TIMSK |= (1<<OCIE1A);
	sei(); // 전역 인터럽트 활성화
	TCCR1B |= (1<<WGM12) | (1<<CS12) | (1<<CS10);
	// 2ms 마다 비교일치 인터럽트 발생
	OCR1A = 31; // T = 2ms = (N * OCR1A + 1) / 16M // OCR1A = 31.25 =: 31
}

void Timer3_init(void) // 초음파에 사용될 3번 타이머/카운터 설정
{
	// 분주비 1024
	TCCR3B |= (1<<CS32) | (1<<CS30);
	// 노멀모드에 파형출력과 인터럽트를 안하기 때문에 분주비만 설정
}

uint8_t measure_distance() // 초음파 센서의 거리 계산 함수
{
	// 트리거핀으로 펄스 출력
	PORTG &= ~(1<<PG1); // LOW 값 출력
	_delay_us(1);
	PORTG |= (1<<PG1); // High 값 출력
	_delay_us(10);
	PORTG &= ~(1<<PG1); // LOW 값 출력
	
	// 에코핀이 high가 될 때까지 대기
	TCNT3 = 0;
	while(!(PING & 0x01)) // PORTG의 0번 핀이 high가 될때까지 대기
	if(TCNT3 > 65000) // 장애물이 없는 경우
	return 0;
	
	// 에코핀이 LOW가 될 때까지의 시간 측정
	TCNT3 = 0;
	while(PING & 0x01) // PORTG의 0번 핀이 low가 될때까지 대기
	if(TCNT3 > 65000) // 측정 불가능
	return 0;
	
	// 에코핀의 펄스 폭을 마이크로초 단위로 계산
	double pulse_width = 1000000.0 * TCNT3 * PRESCALER / F_CPU;
	// (( N * TCNT3 ) * 10^6 ) / 16M
	
	return ((pulse_width / 58)); // 센티미터 단위로 거리 반환
	// 340m/s * 100s * (pulse_width / 2) * 10^-6 = pulse_width / 58.8
	// 58.8를 대강 58로 사용
}

int main(void)
{
	DDR_init(); // DDR 설정
	LCD_init(); // LCD 초기 설정
	Timer3_init(); // 초음파에 사용될 3번 타이머/카운터 설정
	Timer1_init(); // 스텝모터에 사용될 1번 타이머/카운터 설정
	while (1)
	{
		distance = measure_distance(); // 거리 측정
		if(count2 == 175) // 350ms마다 LCD 출력을 위한 if문 
		{
			print_LCD(distance); // LCD에 거리 출력
			count2 = 0;
		}
		else
		{
			count2 += 1;
		}
		uint8_t pattern = 0; // LED 계산을 위한 변수
		// distance만큼 LED 값 증가 
		// distance가 클수록 LED가 많이 켜짐
		int LED_count = (distance >> 3);
		for(int i = 0; i < LED_count; i++)
		{
			pattern |= (0x01 << i);
		}
		PORTE = pattern; // 계산된 패턴값 LED에 출력
		
		if(read_switch(0)) // 스위치 0번이 눌리면
		{
			dir = 1; // 직진 모드 설정
		}
		if(read_switch(7)) // 스위치 7번이 눌리면
		{
			dir = 0; // 정지 모드 설정
		}
	}
	return 0;
}
