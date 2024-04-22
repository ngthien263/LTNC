#include <lib.h>
char rows_pin[6] = {0, 1, 2, 3, 4, 5};
char cols_pin[4] = {0, 1, 2, 3};
int keypad[6][4] = {{'0', '1', '2', '3'},{'0', '1', '2', '3'},{'0', '1', '2', '3'},{'0', '1', '2', '3'},{'0', '1', '2', '3'},{'0', '1', '2', '3'}};

void LCD_command(unsigned char command) {
	LCD_CONTROL_PORTD &= ~(1 << LCD_RS);//RS xuong 0 de ghi lenh
	LCD_CONTROL_PORTD &= ~(1 << LCD_RW);//RW xuong 0 de ghi lenh
	_delay_ms(1);
	LCD_DATA_PORTC = command;
	LCD_CONTROL_PORTD |= (1 << LCD_E);
	_delay_ms(1);
	LCD_CONTROL_PORTD &= ~(1 << LCD_E);
	_delay_ms(3);
}

void LCD_data(unsigned char data) {
	LCD_CONTROL_PORTD |= (1 << LCD_RS);
	LCD_CONTROL_PORTD &= ~(1 << LCD_RW);
	_delay_ms(1);
	LCD_DATA_PORTC = data;
	LCD_CONTROL_PORTD |= (1 << LCD_E);
	_delay_ms(1);
	LCD_CONTROL_PORTD &= ~(1 << LCD_E);
	_delay_ms(1);
}

void LCD_init() {
	LCD_DATA_DDRC = 0xFF;
	LCD_CONTROL_DDRD |= (1 << LCD_RS) | (1 << LCD_RW) | (1 << LCD_E);
	_delay_ms(1);
	LCD_command(0x38);
	LCD_command(0x0C);
	_delay_ms(1);
	
}

void LCD_clear() {
	LCD_command(0x01);
	_delay_ms(2);
}

void LCD_gotoxy(unsigned char x, unsigned char y) {
	unsigned char address;
	if(y != 1)
	address = 0xC0 + x - 1;
	else
	address = 0x80 + x - 1;
	LCD_command(address);
}

void LCD_print(const char *str) {
	while(*str) {
		LCD_data(*str++);
	}
}
char getkey()
{
	char key = '\0';
	OUT_dir = 0x0F;
	IN_dir = 0x00;
	unsigned char i = 0, j = 0;
	for(i = 0; i < 4; i++)
	{
		OUT_port |= (1<<cols_pin[i]);
		for(j = 0; j < 6; j++)
		{
			if((PINA & (1<<rows_pin[j])))
			{
				key = keypad[j][i] ;
				while(PINA & (1<<rows_pin[j]));
			}
		}
		OUT_port &= ~(1<<cols_pin[i]);
	}
	return key;
}


void char_to_string(char c, char *str) {
	str[0] = c;
	str[1] = '\0';
}
