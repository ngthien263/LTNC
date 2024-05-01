#include "mystr.h"
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
void reverse(char* str) {
    unsigned char start = 0;
    unsigned char end1 = 0;
    while(str[end1] != '\0')
    {
      end1++;
  }
  end1--;
    while (start<end1) {
        char temp = str[start];
        str[start] = str[end1];
        str[end1] = temp;
        start++;
        end1--;
    }
}
void int_to_string(int num, char *str)
{
  bool isNegative = 0;
  unsigned char i = 0;
  if(num < 0)
  {
    isNegative = 1;
    num = -num;
  }
  if(num == 0)
  {
    str[i++] = '0';
  }
  else
  {
    while (num != 0) 
    {
      int rem = (int)num % 10; 
      str[i++] = rem + '0';
      num = num / 10;
    }
  }
  if(isNegative)
    str[i++] = '-';
  reverse(str);
}

void db_to_string(float num, char *str)
{   
    bool isNegative = 0;
      unsigned char i = 0;
      if(num < 0)
        {
            isNegative = 1;
            num = -num;
        }
        int int_part = (int)num;
        while(int_part != 0)
        {
            int rem = int_part % 10;
            str[i++] = rem + '0';
            int_part = int_part / 10;
        }
        if(num < 1)
        {
            str[i++] = '0';
        }
        if(isNegative)
          str[i++] = '-';
        reverse(str);
        str[i++] = '.';
        float decimal_part = num - (int)num;
        for(unsigned char k = 0; k < 6; k++)
        {
            decimal_part *= 10;
            int rem = (int)(decimal_part + 0.001);
            str[i++] = rem + '0';
            decimal_part -= rem;
        }
        for(unsigned char j = i - 1; j >= 0; j--)
      {
          if(str[j] == '0')
              str[j] = '\0';
          else
              break;
      }
    str[i] = '\0'; 
}
