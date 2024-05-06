#ifndef KEYPAD_H
#define KEYPAD_H

#include <Arduino.h>
#include "lcd.h"
#include "mystr.h"
#include "math.h"
extern char cols_pin[4];
extern char rows_pin[6];
extern char keypad[6][4];
extern float num[5];
extern char op;
extern float result;
extern char num1[100];
extern char key_str[16];
extern char re_str[10];
extern bool isReal;
extern bool flag;
char getkey();
float calculate(char *str);
void addkey(char key);
void equal();
void memory_add();
void memory_sub();
void square_root();
void changeSign();
void Percentage();
void memory_recall();
void memory_clear();
void memory_sub();
#endif 
