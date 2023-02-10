/*
 * ohminjin_20204306.c
 *
 * Created: 2022-05-18 오후 2:02:17
 * Author : EI
 */ 

#define F_CPU 16000000L
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include "Text_LCD.h"

uint8_t MODE = 4;
typedef unsigned char uchar;

uchar read_switch(uchar sw_id)
{
	static uchar pin_bef = 0xff;
	uchar sw_bef = pin_bef & (1<<sw_id);
	uchar sw_cur = PINC & (1<<sw_id);
	
	pin_bef = (pin_bef & ~(1<<sw_id)) | sw_cur;
	
	if(sw_bef > 0 && sw_cur == 0)
	{
		_delay_ms(10);
		sw_cur = PINC & (1<<sw_id);
		if(sw_cur == 0)
		return 1;
	}
	return 0;
}

int main(void)
{
    DDRC = 0x00;
	DDRA = 0xFF;
	DDRB = 0xFF;
	
	uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
	
	int n1 =0;
	int n2 =0;
	int n3 =0;
	char op;
	
	LCD_init();
	
	char text[17];
	char text_er[20];
	
	while(1)
	{
		// 숫자1
		while(1)
		{
			if(read_switch(0))
			{
				LCD_clear();
				PORTB = numbers[1];
				n1 = 1;
				break;
			}
			else if(read_switch(1))
			{
				LCD_clear();
				PORTB = numbers[2];
				n1 = 2;
				break;
			}
			else if(read_switch(2))
			{
				LCD_clear();
				PORTB = numbers[3];
				n1 = 3;
				break;
			}
			else if(read_switch(3))
			{
				LCD_clear();
				PORTB = numbers[4];
				n1 = 4;
				break;
			}
			else if(read_switch(4))
			{
				LCD_clear();
				PORTB = numbers[5];
				n1 = 5;
				break;
			}
			else if(read_switch(5))
			{
				LCD_clear();
				PORTB = numbers[6];
				n1 = 6;
				break;
			}
			else if(read_switch(6))
			{
				LCD_clear();
				PORTB = numbers[7];
				n1 = 7;
				break;
			}
			else if(read_switch(7))
			{
				LCD_clear();
				PORTB = numbers[8];
				n1 = 8;
				break;
			}
		}
		
		// 연산자
		while(1)
		{
			if(read_switch(1))
			{
				LCD_clear();
				PORTB = numbers[2];
				op = '+';
				break;
			}
			else if(read_switch(2))
			{
				LCD_clear();
				PORTB = numbers[3];
				op = '-';
				break;
			}
			else if(read_switch(3))
			{
				LCD_clear();
				PORTB = numbers[4];
				op = '%';
				break;
			}
			else if(read_switch(4))
			{
				LCD_clear();
				PORTB = numbers[5];
				op = '*';
				break;
			}
			else if(read_switch(5))
			{
				LCD_clear();
				PORTB = numbers[6];
				op = '/';
				break;
			}
			else if(read_switch(0) || read_switch(6) || read_switch(7))
			{
				LCD_clear();
				sprintf(text_er, "Wrong Operator");
				LCD_write_string(text_er);
			}
		}
		
		// 숫자 2
		while(1)
		{
			if(read_switch(0))
			{
				LCD_clear();
				PORTB = numbers[1];
				n2 = 1;
				break;
			}
			else if(read_switch(1))
			{
				LCD_clear();
				PORTB = numbers[2];
				n2 = 2;
				break;
			}
			else if(read_switch(2))
			{
				LCD_clear();
				PORTB = numbers[3];
				n2 = 3;
				break;
			}
			else if(read_switch(3))
			{
				LCD_clear();
				PORTB = numbers[4];
				n2 = 4;
				break;
			}
			else if(read_switch(4))
			{
				LCD_clear();
				PORTB = numbers[5];
				n2 = 5;
				break;
			}
			else if(read_switch(5))
			{
				LCD_clear();
				PORTB = numbers[6];
				n2 = 6;
				break;
			}
			else if(read_switch(6))
			{
				LCD_clear();
				PORTB = numbers[7];
				n2 = 7;
				break;
			}
			else if(read_switch(7))
			{
				LCD_clear();
				PORTB = numbers[8];
				n2 = 8;
				break;
			}
		}
		if(op == '+')
		{
			n3 = n1 + n2;
		}
		else if(op == '-')
		{
			n3 = n1 - n2;
		}
		else if(op == '%')
		{
			n3 = n1 % n2;
		}
		else if(op == '*')
		{
			n3 = n1 * n2;
		}
		else if(op == '/')
		{
			n3 = n1 / n2;
		}
		
		// = 누르기
		while(1)
		{
			if(read_switch(0))
			{
				LCD_clear();
				sprintf(text, "%d %c %d = %d", n1, op, n2, n3);
				LCD_write_string(text);
				break;
			}
			else if(read_switch(1) || read_switch(2) || read_switch(3) || read_switch(4) || read_switch(5) || read_switch(6) || read_switch(7))
			{
				LCD_clear();
				sprintf(text_er, "Push switch 0");
				LCD_write_string(text_er);
			}
		}
	}
}

