import numpy as np
from numpy import random
import time

input = random.randint(100,500,size=(500,500))
vector = random.randint(100,500,size=(500,1))
output = np.zeros((500,1))

np.savetxt("input.txt",input)
np.savetxt("vector.txt",vector)

start_time = time.time()

for m in range(1):
    for i in range(500):
        for j in range(1):
            for k in range(500):
                output[i][j] += input[i][k]*vector[k][j]

finish_time = time.time()

np.savetxt("output.txt",output)
print("计算结束，结果存入输出文件中!")

result=1000*(finish_time-start_time)

print("本次处理所用时间:%f ms"%(result))


