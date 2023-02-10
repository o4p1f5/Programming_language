12. PWM
// 하나의 LED의 밝기만 변화
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  int dim = 0; // 현재 LED 밝기
	int direction = 1;

  DDRB |= (1 << PB4); // PB4 = 파형출력핀(OC0) / LED와 연결
	TCCR0 |= (1<<WGM01) | (1<<WGM00); // 타이머카운터 0번 // 고속 PWM 모드
	TCCR0 |= (1<<COM01); // 비반전모드
	TCCR0 |= (1<<CS02) | (1<<CS01) | (1<<CS00); // 분주비 1024설정
	// 16ms 마다 오버플로 반복 // T = (1024 * 255) / 16M = 0.01632s

    while (1) 
    {
		OCR0 = dim; // 듀티 사이클 설정
		_delay_ms(10);
		dim += direction;
		if(dim==0) direction = 1; // 밝기 증가
		if(dim==255) direction = -1; // 밝기 감소 // 오버플로우
    }
	return 0;
}

13. PWM2
// 두개의 LED의 밝기가 번갈아가며 변화
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int dim = 0; // 현재 LED 밝기
	int direction = 1;

	DDRB |= (1 << PB5) | (1 << PB6); // PB5,PB6 = 파형출력핀(OC1A, OC1B) // LED와 연결
	TCCR1A |= (1<<WGM10); // 타이머카운터 1번 // 8비트 위상 교정 PWM 모드
	TCCR1A |= (1<<COM1A1); // 비교일치 A -> 비반전모드
	TCCR1A |= (1<<COM1B1) | (1<<COM1B0); // 비교일치 B -> 반전모드
	TCCR1A |= (1<<CS12); // 분주비 256설정
	// 16ms 마다 오버플로 반복 // T = (256 * (dim+1)) / 16M = 0.01632s

	while (1)
	{
		OCR1A = dim; // 듀티 사이클 설정
		OCR1B = dim; // 듀티 사이클 설정
		_delay_ms(10);

		dim += direction;
		if(dim==0) direction = 1; // 밝기 증가
		if(dim==255) direction = -1; // 밝기 감소 // 오버플로우
	}
	return 0;
}

14. DC모터
// 보드에 선을 연결하면 잘 빠져나오는 경우가 생기므로, 선을 낀 후 나사를 조여준다
// 모터에 연결하는 선은 살짝 구부리면 빠지지않는다
// VCC가 두개인 이유는 하나는 보드, 하나는 dc모터 전원이다
// PE0~4를 소켓에 연결 // PE4 = OC3B -> 인에이블에 연결
// 스위치 0 -> 정방향 회전
// 스위치 1 -> 역방향 회전
// 스위치 2 -> 정지
#define  F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define OCR_MAX 255;

void InitializeTimer3()
{
	TCCR3A |= (1<<WGM30); // 8비트 고속 PWM모드
	TCCR3A |= (1<<WGM32);
	TCCR3A |= (1<<COM3B1); // 비반전 // TOP : 0xFF, 비교일치값 : OCR3B
	TCCR3B |= (1<<CS31) | (1<<CS30); // 분주비 64
	OCR3B = 0;
}

unsigned char read_switch(unsigned char sw_id) // 해당 번호의 스위치가 눌렸는지 확인
{
	static unsigned char pin_bef = 0xff;
	unsigned char sw_bef = pin_bef & (1<<sw_id);
	unsigned char sw_cur = PINC & (1<<sw_id);
	pin_bef = (pin_bef& ~(1<<sw_id)) | sw_cur;
	if(sw_bef > 0 && sw_cur == 0) // 스위치가 눌렀다면
	{
		_delay_ms(10);
		sw_cur = PINC & (1<<sw_id);
		if(sw_cur == 0)
		return 1; // 1 반환
	}
	return 0; // 스위기가 눌리지않았다면 0 반환
}

void control_motor(float vel_ratio, int dir)
{
	OCR3B = (int)(OCR_MAX * vel_ratio); 
	if(dir > 0) // 정방향
	{
		PORTE |= 0x01;
		PORTE &= ~0x02;
	}
	else if(dir < 0) // 역방향
	{
		PORTE &= ~0x01;
		PORTE |= 0x02;
	}
	else // 정지
	{
		PORTE &= ~0x01;
		PORTE &= ~0x02;
	}
}

int main(void)
{
	DDRC = 0x00; // PC0, PC1, PC2 입력
  DDRE |= (1<<PE0) | (1<<PE2) | (1<<PE4); // 모터 제어핀 출력 설정
	PORTE = 0x00;
	InitializeTimer3(); // 타이머카운터 3번 설정
  while (1) 
    {
		if(read_switch(0)) // 스위치 0번
		control_motor(0.7f, 1); // 70% PWM // 정방향
		if(read_switch(1)) // 스위치 1번
		control_motor(0.3f, -1); // 30% PWM // 역방향
		if(read_switch(2)) // 스위치 2번
		control_motor(0.f, 0); // 정지
		_delay_ms(50);
    }
	return 0;
}
 
15. 서브모터
// 갈색 - GND 빨강 - VCC 주황 - PWM신호(PB6 - OC1B)
// 서브모터의 각도는 0,90,180로 변경
#define  F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#define  ROTATION_DELAY 1000 // 1초 대기
// D = (8*OCR1B) / 16M
#define  PULSE_MIN 1300 // 0도 // 최소 펄스
#define  PULSE_MID 3000
#define  PULSE_MAX 4700 // 180 // 최대 펄스

void InitializeTimer1()
{
	TCCR1A |= (1<<WGM11) | (1<<WGM10); // 모드 15,고속 PWM 모드
	TCCR1B |= (1<<WGM12) | (1<<WGM13); // TOP : OCR1A
	TCCR1A |= (1<<COM1B1); // 비반전
	TCCR1B |= (1<<CS11); // 분주율 8, 2MHz
	OCR1A = 39999; // T = (8*(TOP+1)) / 16M // 20ms 주기
}

int main(void)
{
  DDRB |= (1<<PB6); // PB6 = OC1B 출력 설정
	InitializeTimer1(); // 타이머카운터 1 설정
    while (1) 
    {
		OCR1B = PULSE_MIN; // 0
		_delay_ms(ROTATION_DELAY);
		OCR1B = PULSE_MID; // 90
		_delay_ms(ROTATION_DELAY);
		OCR1B = PULSE_MAX; // 180
		_delay_ms(ROTATION_DELAY);
    }
	return 0;
}

16. 스텝모터
// 스탭모터 
#define  F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
// 모터를 1스탭 회전시키기 위한 데이터
uint8_t step_data[] = {0x01, 0x02, 0x04, 0x08}; // 1상 여자 방식
int step_index = -1;
uint8_t stepForward() // 시계 방향 회전
{
	step_index++;
	if(step_index >= 4)
	step_index =0;
	return step_data[step_index];
}

uint8_t stepBackward() // 반시계 방향 회전
{
	step_index--;
	if(step_index < 0)
	step_index =3;
	return step_data[step_index];
}

int main(void)
{
    DDRC = 0x0F; // 모터 제어핀 출력으로 설정

    while (1) 
    {
		for(int i = 0; i<2000 ; i++) // 2000 스탭 진행
		{
			PORTC = stepForward(); // 시계방향
			_delay_ms(5); // 스탭 간격 5ms
		}
		_delay_ms(1000);
		for(int i = 0; i<2000 ; i++)
		{
			PORTC = stepBackward(); // 반시계방향
			_delay_ms(5); // 스탭 간격 5ms
		}
		_delay_ms(1000);
    }
	return 0;
}
