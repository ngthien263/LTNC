#include "lib.h"

int main(void)
{
	LCD_init();
	char key_str[4] = {};
	char key;
    while (1) 
    {
		key = getkey();
		char_to_string(key, key_str);
		LCD_print(key_str);
    }
}

