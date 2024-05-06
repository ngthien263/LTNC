#include "keypad.h"
char rows_pin[6] = {A0,A1,A2,A3,A4,A5};
char cols_pin[4] = {13,12,11,10};
extern char keypad[6][4];
float num[5];
char op;
float result = 0.0;
char num1[100];
char key_str[16];
bool newkey = 0;
bool isReal = 0;
bool isEqual = 0;
bool flag = 0;
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
    unsigned char i = 0;
    unsigned char j = 0;
    bool isDecimal = 0;
    float decimal = 1.0;
    float result = 0.0;
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
            op = str[i];
            j++;
            result = 0.0;
            isDecimal = 0;
            decimal = 1.0;
        }
        i++;
    }
    num[j] = result;
    switch(op)
    {
       case '+':
           result = num[0] + num[1];
           break;
       case '-':
           result = num[0] - num[1];
           break;
       case '*':
           result = num[0] * num[1];
           break;
       case '/':
           if (num[1] != 0)
               result = num[0] / num[1];
           break;
    }
    return result;
}



void addkey(char key)
{
  char_to_string(key, key_str);
  add_to_string(key, num1);
  LCD_str(key_str);
}

void equal()
{
  LCD_clear();
  char re_str[10];
  if(isReal == 0)
  {
    result = calculate(num1);
    clearCharArray(num1);
    int_to_string(result, num1);
    LCD_str(num1);
  }
  if(isReal == 1)
  { 
    result = calculate(num1);
    clearCharArray(num1);
    db_to_string(result, num1);
    LCD_str(num1);
  }
  isEqual = 1;
}

void memory_sub()
{ 
  float memory = result;
  float addNumb = string_to_float(num1);
  clearCharArray(num1);
  result = memory - addNumb;
  db_to_string(result, num1);
  LCD_clear();
  LCD_str(num1);
  flag = 1;
}

void memory_add()
{
  float memory = result;
  float addNumb = string_to_float(num1);
  clearCharArray(num1);
  result = memory + addNumb;
  db_to_string(result, num1);
  LCD_clear();
  LCD_str(num1);
  flag = 1;
}
void square_root()
{
  result = string_to_float(num1);
  if(string_to_float(num1) >= 0){
    result = sqrt(result);
    clearCharArray(num1);
    db_to_string(result, num1);
    LCD_clear();
    LCD_str(num1);
  }
  else
  {
    LCD_clear();
    LCD_str("Error");
  }
  flag = 1;
}
void changeSign()
{
  if(!isReal)
  {
    result = string_to_int(num1);
    Serial.print(result);
    result = -result;
    Serial.print(result);
    clearCharArray(num1);
    int_to_string(result, num1);
    LCD_clear();
    LCD_str(num1);
  }
  else
  {
    result = string_to_float(num1);
    result = -result;
    clearCharArray(num1);
    db_to_string(result, num1);
    LCD_clear();
    LCD_str(num1);
  }
  flag = 1;
}
void Percentage()
{
  result = string_to_float(num1);
  result = result/100;
  clearCharArray(num1);
  db_to_string(result, num1);
  LCD_clear();
  LCD_str(num1);
  flag = 1;
}
void memory_recall()
{
  LCD_clear();
  float memory = result;
  clearCharArray(num1);
  db_to_string(result, num1);
  LCD_str(num1);
  flag = 1;
}
void memory_clear()
{
  LCD_clear();
  result = 0;
  clearCharArray(num1);
  LCD_str("Memory Cleared");
  flag = 1;
}
void cls()
{
  command2LCD(0x01);
  for(int i = 0; i < 5; i++) {
    num[i] = 0.0;
  }
  result = 0.0;
  clearCharArray(num1);
  clearCharArray(key_str);
  clearCharArray(re_str);
  isReal = 0;
}
