/*
 * GccApplication6.c
 *
 * Created: 2022-03-29 오후 12:47:10
 * Author : 오민진
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>

// 라이브러리를 따로 만들지않음
void UART_init(void);
void UART_transmit(char data);
unsigned char UART_receive(void);
void UART_print_string(char *str);

int main(void)
{
    UART_init(); // UART 초기화
	char test_str[] = "Test using UART Library: ";
	// UART를 이용해 아트메가에서 PC로 출력
	char number_str[4] = "0"; // 숫자도 출력
	uint8_t num = 0;
    while (1) 
    {
		UART_print_string(test_str); // 문자열 출력
		sprintf(number_str, "%d\n\r", num); 
		// number_str에 "%d\n\r" 형식으로 문자열 넣기
		UART_print_string(number_str); // 문자열 출력
		num++; 
		_delay_ms(500);
    }
	return 0;
}

// 라이브러리 구현
void UART_init(void)
{
	UBRR1H = 0x00; // 1배속
	UBRR1L = 103;
	UCSR1A = 0x00; // 1배속
	UCSR1C = 0x06; // 8비트 데이터를 보낼 수 있게 설정
	UCSR1B = 0x18; // 송수신 가능 0001(보내기 활성화) 1(받기 활성화)000 
}

void UART_transmit(char data)
{
	while( !(UCSR1A & (1 << UDRE1)) ) // 값을 보내기 전에 값을 보낼 수 있는 상태인지 확인 // 데이터 송신 받음
		;
	// 1이 되면 while문 빠져나옴
	UDR1 = data; // data 송신
}

unsigned char UART_receive(void)
{
	while( !(UCSR1A & (1 << RXC1))) // 값을 받았는지 확인 // 데이터 수신 받음
		;
	// 1이 되면 while문 빠져나옴
	return UDR1; // 받은 data 출력
}

void UART_print_string(char *str)
{
	for(int i = 0; str[i]; i++)
		UART_transmit(str[i]); // 바이트 단위 출력
}
