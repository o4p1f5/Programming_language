// LED에 패턴을 계속해서 오른쪽으로 쉬프트

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

char circular_shift_right(char pattern)
{
char LSB = pattern & 0x01;
char MSB = LSB << 7;
char new_pattern = pattern >> 1;
new_pattern |= MSB;
return new_pattern;
}

int main()
{
char pattern = 0xA0; // 초기 패턴
DDRE = 0xFF; // LED 8개를 포트 E에 모두 연결함

while(1)
{
PORTE = pattern; // 출력
pattern = circular_shift_right(pattern); // 쉬프트
_delay_ms(500);
}
return 0;
}
