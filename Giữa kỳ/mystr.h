#ifndef MYSTR_H
#define MYSTR_H
#include <stdlib.h>
#include<stdint.h>
void char_to_string(char c, char *str);
void add_to_string(char a, char *str);
int string_to_int(char *str);
float string_to_float(char* str);
void reverse(char* str) ;
void int_to_string(int32_t num, char *str);
void db_to_string(double num, char *str);
void clearCharArray(char* str);
#endif
