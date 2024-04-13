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
ports = [11, 12, 13, 15, 16, 18,22]
num_list = [63,6,91,79,102,109,125,7,127,111]
gnd = [21,23, 24, 26]
st = list(map(int, np.ones(len(gnd)))) 
keypin = [29, 31, 32, 33, 36, 35, 38, 37]
for i in range (len(ports)):
    GPIO.setup(ports[i], GPIO.OUT)
for i in range (len(gnd)):
    GPIO.setup(gnd[i], GPIO.OUT)
    
def singleLed(x):
    num = num_list[x]      
    y = dec2bin(num)       
    for i in range (len(ports)):  
        GPIO.output(ports[i], y[i])
        time.sleep(0.0001)
        
def tachso(num):   
    num_arr = []
    while (num != 0):
        num_arr =  [num%10] + num_arr
        num = int(num/10)
    return num_arr

def multiLed(num):
    num = tachso(num)
    if (len(num) < len(gnd)):     
        num [:0] = np.zeros(len(gnd) - len(num))
        num = list(map(int, num))
    for i in range (len(gnd)):      
        st[i] = 0
        for j in range (len(gnd)):
            GPIO.output(gnd[j], st[j])
            time.sleep(0.01)
        singleLed(num[i])
        st[i] = 1
        

while(1):
    multiLed(6456)
    
