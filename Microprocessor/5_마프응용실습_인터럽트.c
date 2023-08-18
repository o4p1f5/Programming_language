#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile int state = 0;

ISR(INT0_vect)
{
	state = (state + 1) % 2; // 0 1 반복
	_delay_ms(100);
}

void INIT_PORT(void)
{
	DDRE = 0x01; // PE0 핀을 출력으로 설정
	PORTE = 0x00; // LED 꺼진 상태
	
	DDRD = 0x00; // PD0(INT0) 핀을 입력으로 설정
	PORTD = 0x01; // PD0 핀의 내부 풀업 저항 사용 
	// 그냥 스위치 연결해도 작동하도록 내부 풀업 저항 사용
}

void INIT_INT0(void)
{
	EIMSK |= (1 << INT0); // 인터럽트 활성화
	EICRA |= (1 << ISC01); // 하강엣지에서 인터럽트 발생
	sei(); // 모든 인터럽트 허용
} 

int main(void)
{
    INIT_PORT();
	INIT_INT0();
    while (1) 
    {
		PORTE = state;
    }
	return 0;
}
