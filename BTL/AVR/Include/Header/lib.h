#ifndef LIB_H_
#define LIB_H_

#include <avr/io.h>
#define F_CPU 16000000ul
#include <util/delay.h>
#define IN_dir DDRA
#define OUT_dir DDRB
#define IN_port PINA
#define OUT_port PORTB
#define LCD_DATA_PORTC			PORTC
#define LCD_DATA_DDRC			DDRC
#define LCD_CONTROL_PORTD		PORTD
#define LCD_CONTROL_DDRD			DDRD
#define LCD_RS	0
#define LCD_RW	1
#define LCD_E	2
extern char rows_pin[6];
extern char cols_pin[4];
extern char keypad[6][4];
extern int num[10];
extern char op[10];
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init() ;
void LCD_clear();
void LCD_gotoxy(unsigned char x, unsigned char y);
void LCD_print(const char *str);
char getkey();
void char_to_string(char c, char *str);
int string_to_int(char *str);
void add_to_string(char a, char *str);
uint32_t calculate(char *str);
#endif /* LIB_H_ */