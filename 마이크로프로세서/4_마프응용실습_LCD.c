// Text_LCD.h
/*
#ifndef TEXT_LCD_H_
#define TEXT_LCD_H_

#ifndef F_CPU
#define F_CPU 16000000
#endif

#include <avr/io.h>
#include <util/delay.h>

#define PORT_DATA		PORTA // 제어핀이랑 데이터 핀이랑 한 포트에 연결
#define PORT_CONTROL		PORTA // 제어핀 - 012 데이터핀 - 4567
#define DDR_DATA		DDRA
#define DDR_CONTROL		DDRA

#define RS_PIN		0
#define RW_PIN		1
#define E_PIN		2

#define COMMAND_CLEAR_DISPLAY		0x01
#define COMMAND_8_BIT_MODE			0x38
#define COMMAND_4_BIT_MODE			0x28

#define COMMAND_DISPLAY_ON_OFF_BIT		2
#define COMMAND_CURSOR_ON_OFF_BIT		1
#define COMMAND_BLINK_ON_OFF_BIT		0

extern uint8_t MODE;

void LCD_pulse_enable(void);
void LCD_write_data(uint8_t data);
void LCD_write_command(uint8_t command);
void LCD_set_data(uint8_t data);
void LCD_clear(void);
void LCD_init(void);
void LCD_write_string(char* string);
void LCD_goto_XY(uint8_t row, uint8_t col);

#endif
*/

// Text_LCD.c
/*
#include "Text_LCD.h"

void LCD_pulse_enable(void)
{
	PORT_CONTROL |= (1 << E_PIN);
	_delay_ms(1);
	PORT_CONTROL &= ~(1 << E_PIN);
	_delay_ms(1);
}

void LCD_write_data(uint8_t data)
{
	PORT_CONTROL |= (1 << RS_PIN);
	LCD_set_data(data);
}

void LCD_write_command(uint8_t command)
{
	PORT_CONTROL &= ~(1 << RS_PIN);
	LCD_set_data(command);
}

void LCD_set_data(uint8_t data)
{
	if(MODE == 8)
	{
		PORT_DATA = data;
		LCD_pulse_enable();
	}
	else
	{
		PORT_DATA = (PORT_DATA & 0x0f) + (data & 0xf0);
		LCD_pulse_enable();
		
		PORT_DATA = (PORT_DATA & 0x0f) + ((data << 4) & 0xf0);
		LCD_pulse_enable();
	}
	_delay_ms(2);
}

void LCD_clear(void)
{
	LCD_write_command(COMMAND_CLEAR_DISPLAY);
	_delay_ms(2);
}

void LCD_init(void)
{
	_delay_ms(50);
	
	if(MODE == 8)
	{
		DDR_DATA = 0xff;
	}
	else
	{
		DDR_DATA |= 0xf0;
	}
	DDR_CONTROL |= (1 << RS_PIN) | (1 << RW_PIN) | (1 << E_PIN);
	
	PORT_DATA = 0x00;
	
	PORT_CONTROL &= ~(1 << RW_PIN);
	
	if(MODE == 8)
	{
		LCD_write_command(COMMAND_8_BIT_MODE);
	}
	else
	{
		LCD_write_command(0x02);
		LCD_write_command(COMMAND_4_BIT_MODE);
	}
	
	uint8_t command = 0x08 | (1 << COMMAND_DISPLAY_ON_OFF_BIT);
	LCD_write_command(command);
	
	LCD_clear();
	
	LCD_write_command(0x06);
}

void LCD_write_string(char* string)
{
	uint8_t i;
	for(i =0 ; string[i]; i++)
	{
		LCD_write_data(string[i]);
	}
}

void LCD_goto_XY(uint8_t row, uint8_t col)
{
	col %= 16;
	row %= 2;
	
	uint8_t address = (0x40 * row) + col;
	uint8_t command = 0x80 + address;
	
	LCD_write_command(command);
}
*/

#define F_CPU 16000000
#include "Text_LCD.h"
#include <avr/io.h>
#include <util/delay.h>

uint8_t MODE = 4; // 헤더파일에 선언된 모드 설정

int main(void)
{
	LCD_init(); // LCD 초기화
	
	LCD_write_string("Hello LCD!"); // 문자열 출력
	
	_delay_ms(1000);
	
	LCD_clear(); // 화면 지움
	
	// 문자단위로 출력
	LCD_goto_XY(0, 0);
	LCD_write_data('1');
	LCD_goto_XY(0, 5);
	LCD_write_data('2');
	LCD_goto_XY(1, 0);
	LCD_write_data('3');
	LCD_goto_XY(1, 5);
	LCD_write_data('4');
	
	while(1)
	{
		_delay_ms(1);
	}
	return 0;
}
