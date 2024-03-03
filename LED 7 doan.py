import math
import numpy as np
import RPi.GPIO as GPIO
import time
def dec2bin(x):
    x = list(map(int,bin(x)[2:]))
    a = list(map(int, np.zeros(7 - len(x))))
    a.extend(x)
    return a
GPIO.setmode(GPIO.BOARD)
port = [7, 11, 12, 13, 15, 16, 18]
num_list = [126,48,109,51,91,95,112,127,123]
for i in range (len(port)):
    GPIO.setup(port[i], GPIO.OUT)
while(1):
   num =  num_list[2]
   y = dec2bin(num)
   for i in range (len(y)):
       GPIO.output(port[i], y[i])
       time.sleep(0.1)
