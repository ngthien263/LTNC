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
  if ((key >= '0' && key <= '9') && (flag == 0) )
  {   
      addkey(key);
  }
  else if ((key >= '0' && key <= '9') || (key == '-') && (flag == 1) )
  {   
      clearCharArray(num1);
      LCD_clear();
      addkey(key);
      flag = 0;
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
     case 'a': 
        memory_clear();    
        break;
     case 'b':
        memory_recall();
        break;
     case 'c':
        memory_sub();
        break;
     case 'e':
        changeSign();
        break;
     case '%':
        Percentage();
        break;
     case 'f':
        LCD_clear();
        square_root();
        break;
      }
    }
}
