/*
 * GccApplication3.c
 *
 * Created: 2022-03-23 오후 2:45:14
 * Author : 오민진
 */ 

// 저항 - 주주갈, 빨빨갈 사용

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	uint8_t numbers[] = {0x3F, 0x06, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
		// 0~9 패턴 저장
	int count = 0; 
	DDRB = 0xFF; // 제어핀 8개를 출력으로 설정
	
	while(1)
	{
		PORTB = numbers[count]; // 배열에서 숫자 추출
		count = (count + 1) % 10; // 다음 숫자
		
		_delay_ms(1000);
	}
	return 0;
}
