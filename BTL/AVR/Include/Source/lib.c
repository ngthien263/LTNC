#include <lib.h>
char rows_pin[6] = {0, 1, 2, 3, 4, 5};
char cols_pin[4] = {0, 1, 2, 3};
char keypad[6][4] = {
					{'a', 'b', 'c', 'd'},
					{'C', 'e', '%', 'f'},
					{'7', '8', '9', '/'},
					{'4', '5', '6', '*'},
					{'1', '2', '3', '-'},
					{'0', '.', '=', '+'}};
int num[10];
char op[10];
void LCD_command(unsigned char command) {
	LCD_CONTROL_PORTD &= ~(1 << LCD_RS);
	LCD_CONTROL_PORTD &= ~(1 << LCD_RW);
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
		_delay_ms(1);  // Add a small delay after each character
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
int string_to_int(char *str)
{
	int result = 0;
	for (unsigned char i = 0; str[i] != '\0'; i++)
	{
		unsigned char digit = str[i] - '0';
		result = result * 10 + digit;
	}
	return result;
}

void add_to_string(char a, char *str)
{
	unsigned char i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	str[i] = a;
	str[i+1] = '\0';
}

uint32_t calculate(char *str)
{
	uint32_t result = 0;
	unsigned char i = 0;
	unsigned char j = 0;
	while(str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		else
		{
			num[j] = result;
			op[j] = str[i];
			j++;
			result = 0;
		}
		i++;
	}
	num[j] = result;
	result = num[0];
	for(int k = 0; k < j; k++)
	{
		switch(op[k])
		{
			case '+':
				result += num[k+1];
				break;
			case '-':
				result -= num[k+1];
				break;
			case '*':
				result *= num[k+1];
				break;
			case '/':
				if (num[k+1] != 0)
				result /= num[k+1];
			break;
		}
	}
	return result;
}
