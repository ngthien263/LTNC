#include "lcd.h"

uint8_t RSpin = 7;
uint8_t ENpin = 6;
uint8_t DATApin[] = {5,4,3,2};
void write2LCD(uint8_t bytes) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(DATApin[i], (bytes >> i) & 0x01);
  }
  digitalWrite(ENpin, HIGH);
  delayMicroseconds(50);
  digitalWrite(ENpin, LOW); 
}

void command2LCD(uint8_t cmd) {
  digitalWrite(RSpin, LOW); 
  write2LCD(cmd >> 4);
  write2LCD(cmd);
}

void data2LCD(uint8_t data) {
  digitalWrite(RSpin, HIGH); // Ghi dữ liệu
  write2LCD(data >> 4);
  write2LCD(data);
}

void LCD_str(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    data2LCD(str[i]);
    i++;
  }
}

void LCD_gotoxy(unsigned char x, unsigned char y) {
  unsigned char address;
  if(y != 1)
  address = 0xC0 + x - 1;
  else
  address = 0x80 + x - 1;
  command2LCD(address);
  _delay_ms(2);
}
void LCD_clear() {
 command2LCD(0x01); // xoa man hinh
  _delay_ms(2);
}
void LCD_Init()
{
  command2LCD(0x03);
  command2LCD(0x02);
  command2LCD(0x28); 
  command2LCD(0x0E);
  command2LCD(0x80);
}
