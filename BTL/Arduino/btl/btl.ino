#include "lcd.h"
#include "mystr.h"
#include "keypad.h"

char keypad[6][4] = {
          {'a', 'b', 'c', 'd'},
          {'C', 'e', '%', 'f'},
          {'7', '8', '9', '/'},
          {'4', '5', '6', '*'},
          {'1', '2', '3', '-'},
          {'0', '.', '=', '+'}};

void setup() {
  Serial.begin(9600);
  pinMode(RSpin, OUTPUT);
  pinMode(ENpin, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(DATApin[i], OUTPUT);
  }
  LCD_Init();
}

void loop() {
  char key = getkey();
  if (key >= '0' && key <= '9' )
    {   
      addkey(key);
      
    }
    else 
    {
      switch (key)
      {
      case '+':
        addkey(key);
        break;
      case '-':
        addkey(key);
        break;
      case '*':
        addkey(key);
        break;
      case '/':
        isReal = 1;
        addkey(key);
        break;
      case '.':
        isReal = 1;
        addkey(key);
        break;
     case '=':
        equal();
        break;
     case 'c': 
        memory_sub();    
        break;
     case 'd':
        break;
     case 232:
        addkey(key);
        break;
      }
    }
}
