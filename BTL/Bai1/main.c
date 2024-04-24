#include "lib.h"
char num1[8];
char num2[8];

int main(void)
{
	LCD_init();
	char key_str[4] = {};
	char key;
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
				LCD_print(key_str);
			}
		}
		
		
    }
}

