#include "lib.h"
char num1[100];
char* separate(uint32_t n)
{
	int length = 0;
	for (int temp = n; temp != 0; temp /= 10)
		length++;
	static char str[100]; 

	for (int i = 0; n != 0; n /= 10, i++)
	str[i] = '0' + n % 10;

	for (int i = 0; i < length / 2; i++)
	{
		char temp = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temp;
	}

	str[length] = '\0';

	return str;
}

int main(void)
{
	LCD_init();
	char key_str[4] = {};
	char key;
	int result;
    while (1) 
    {
		key = getkey();
		if (key >= '0' && key <= '9' )
		{		
			char_to_string(key, key_str);
			add_to_string(key, num1);
			LCD_print(key_str);
		}
		else 
		{
			switch (key)
			{
			case '+':
				char_to_string(key, key_str);
				add_to_string(key, num1);
				LCD_print(key_str);
				break;
			case 'a':
				LCD_command(0xC0);
				result = calculate(num1);
				LCD_print(separate(result));
				break;
			}
		}
    }
}

