import math
import numpy as np
import time
import numpy as np
def dec2bin(x):
    x = list(map(int,bin(x)[2:]))
    y = list(np.zeros(7 - np.size(x),int))
    y.extend(x)
    return y
port = [7, 11, 12, 13, 15, 16, 18]
num_list = [126,48,109,51,91,95,112,127,123]
y =  dec2bin(48)
print(np.size(y))
