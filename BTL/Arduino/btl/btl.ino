
int RSpin = 7;
int ENpin = 6;
uint8_t DATApin[] = {5,4,3,2};
char rows_pin[6] = {A0,A1,A2,A3,A4,A5};
char cols_pin[4] = {13,12,11,10};
char keypad[6][4] = {
          {'a', 'b', 'c', 'd'},
          {'C', 'e', '%', 'f'},
          {'7', '8', '9', '/'},
          {'4', '5', '6', '*'},
          {'1', '2', '3', '-'},
          {'0', '.', '=', '+'}};
float num[10];
char op[10];
float result;
char num1[100];
char key_str[100];
char re_str[10];
bool isReal;
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
  char key;
  key = getkey();
  if (key >= '0' && key <= '9' )
    {   
      char_to_string(key, key_str);
      add_to_string(key, num1);
      LCD_str(key_str);
    }
    else 
    {
      switch (key)
      {
      case '+':
        char_to_string(key, key_str);
        add_to_string(key, num1);
        LCD_str(key_str);
        break;
      case '-':
        char_to_string(key, key_str);
        add_to_string(key, num1);
        LCD_str(key_str);
        break;
      case '*':
        char_to_string(key, key_str);
        add_to_string(key, num1);
        LCD_str(key_str);
        break;
      case '/':
        char_to_string(key, key_str);
        add_to_string(key, num1);
        LCD_str(key_str);
        isReal = 1;
        break;
      case '.':
        isReal = 1;
        char_to_string(key, key_str);
        add_to_string(key, num1);
        LCD_str(key_str);
        break;
     case '=':
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
        break;
     case 'c':
        if(isReal == 0)
        {
          result--;
          int_to_string(result, re_str);
          LCD_str(re_str);
        }
        if(isReal == 1)
        {
          result--;
          db_to_string(result, re_str);
          LCD_str(re_str);
        }
        isReal = 0;    
        break;
     case 'd':
        if(isReal == 0)
        {
          result++;
          int_to_string(result, re_str);
          LCD_str(re_str);
        }
        if(isReal == 1)
        {
          result++;
          db_to_string(result, re_str);
          LCD_str(re_str);
        }
        isReal = 0;    
        break;
      }
    }
}

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
  while (num != 0) 
        {
            int rem = (int)num % 10; 
            str[i++] = rem + '0';
            num = num / 10;
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

void LCD_Init()
{
  command2LCD(0x03);
  command2LCD(0x02);
  command2LCD(0x28); 
  command2LCD(0x0E);
  command2LCD(0x80);
}
