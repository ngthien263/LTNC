#include "keypad.h"
char rows_pin[6] = {A0,A1,A2,A3,A4,A5};
char cols_pin[4] = {13,12,11,10};
extern char keypad[6][4];
float num[5];
char op[5];
float result = 0.0;
char num1[100];
char key_str[100];
bool newkey = 0;
bool isReal = 0;
float last_res = 0.0;
char getkey()
{
  char key = '\0';
  for(int i = 0; i < 4; i++)
  {
    pinMode(cols_pin[i], OUTPUT);
    digitalWrite(cols_pin[i], 1);
    for(int j = 0; j < 6; j++)
    {
      pinMode(rows_pin[j], INPUT);
      if((digitalRead(rows_pin[j])))
      {
        key = keypad[j][i];
        while((digitalRead(rows_pin[j])));
      }
    }
    digitalWrite(cols_pin[i], LOW);
  }
  return key;
}



float calculate(char *str)
{
    float result = 0;
    unsigned char i = 0;
    unsigned char j = 0;
    bool isDecimal = 0;
    float decimal = 1.0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if(!isDecimal)
                result = result * 10 + (str[i] - '0');
            else
            {
                decimal /= 10.0;
                result += (str[i] - '0') * decimal;
            }   
        }
        else if(str[i] == '.')
        {
            isDecimal = 1;
        }
        else
        {
            num[j] = result;
            op[j] = str[i];
            j++;
            result = 0.0;
            isDecimal = 0;
            decimal = 1.0;
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

void addkey(char key)
{
  char_to_string(key, key_str);
  add_to_string(key, num1);
  LCD_str(key_str);
  newkey = 1;
}

void equal()
{
  char re_str[10];
  command2LCD(0xC0);
  if(isReal == 0)
  {
    result = calculate(num1);
    int_to_string(result, re_str);
    LCD_str(re_str);
  }
  if(isReal == 1)
  {
    result = calculate(num1);
    db_to_string(result, re_str);
    LCD_str(re_str);
  }
  isReal = 0;
  num1[0] = '\0';
}

void memory_sub()
{ 
  LCD_clear();
  char re_str[10];
  last_res = result;
  last_res -= calculate(num1);
  LCD_gotoxy(1,0);   
  if(isReal == 0)
  {
    int_to_string((int)last_res, re_str);
    LCD_str(re_str);
  }
  if(isReal == 1)
  {
    db_to_string((int)last_res, re_str);
    LCD_str(re_str);
  }
  result = last_res;
  command2LCD(0x80);
  delay(1); 
}

void memory_add()
{
  LCD_clear();
  char re_str[10];
  last_res = result;
  last_res += calculate(num1);
  command2LCD(0xC0);   
  if(isReal == 0)
  {
    int_to_string((int)last_res, re_str);
    LCD_str(re_str);
  }
  if(isReal == 1)
  {
    db_to_string((int)last_res, re_str);
    LCD_str(re_str);
  }
  result = last_res;
  command2LCD(0x80);
  delay(1); 
}

void cls()
{
  command2LCD(0x01);
  for(int i = 0; i < 5; i++) {
    num[i] = 0.0;
  }
  op[0] = '\0';
  result = 0.0;
  num1[0] = '\0';
  key_str[0] = '\0';
  re_str[0] = '\0';
  isReal = 0;
}
