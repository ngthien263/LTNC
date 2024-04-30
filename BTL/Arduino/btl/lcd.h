#ifndef LCD_H
#define LCD_H
#include <stdint.h>
#include <Arduino.h>
extern uint8_t RSpin;
extern uint8_t ENpin;
extern uint8_t DATApin[];
void write2LCD(uint8_t bytes);
void command2LCD(uint8_t cmd);
void data2LCD(uint8_t data);
void LCD_str(char *str);
void LCD_Init();

#endif 
