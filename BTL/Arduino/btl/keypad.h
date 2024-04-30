#ifndef KEYPAD_H
#define KEYPAD_H

#include <Arduino.h>
#include "lcd.h"
#include "mystr.h"
extern char cols_pin[4];
extern char rows_pin[6];
extern char keypad[6][4];
extern float num[5];
extern char op[5];
extern float result;
extern char num1[100];
extern char key_str[100];
extern char re_str[10];
extern bool isReal;
char getkey();
float calculate(char *str);
void addkey(char key);
void equal();
#endif 
