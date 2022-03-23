/*
 * GccApplication2.c
 *
 * Created: 2022-03-23 오후 2:20:27
 * Author : 오민진
 */ 

// 스위치가 눌리면 LED가 한칸씩 이동

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

char circlar_shift_left(char pattern)
{
	return ((pattern << 1) | (pattern >> 7));
}

int main()
{
	DDRE = 0xFF; // 포트B 핀 모두 출력으로 설정
	DDRC &= ~0x04; // 포트C의 2번째 핀을 입력으로 설정
	
	char pattern = 0x01; // 초기패턴
	PORTE = pattern;
	
	char state_previous = 1, state_current; // 버튼의 현재상태와 과거 상태
	
	while(1)
	{
		state_current = (PINC & 0x04) >> 2;  
		if(state_current == 0 && state_previous == 1) // 갑자기 눌린 상태 // 눌리기 시작된 상태
		{
			_delay_ms(30); // 디바운스
			pattern = circlar_shift_left(pattern);
			PORTE = pattern;
		}
		state_previous = state_current; // 버튼 상태 업데이트
	}
	
	return 0;
}
