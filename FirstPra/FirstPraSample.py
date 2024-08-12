from sample import SampleClass
import time
import numpy as np

def fibpy(num):
    if num <= 1:
        return 1
    return fibpy(num-1)+fibpy(num-2)

def Leibnizpy(Num):
    n = 0
    for i in range(Num):
        if i % 2 == 0:
            n += 1.0/(2*i+1)
        else:
            n -= 1.0/(2*i+1)
    return n

sample = SampleClass()

print('-'*10)

fibLim = 30

st = time.perf_counter()
fibpy(fibLim)
print('fib\t python\t time :\t{}s'.format(time.perf_counter()-st))

st = time.perf_counter()
sample.fib(fibLim)
print('fib\t cpp\t time :\t{}s'.format(time.perf_counter()-st))

print('-'*10)

LeiLim = 10000000

st = time.perf_counter()
Leibnizpy(LeiLim)
print('Leibniz\t python\t time :\t{}s'.format(time.perf_counter()-st))

st = time.perf_counter()
sample.Leibniz(LeiLim)
print('Leibniz\t cpp\t time :\t{}s'.format(time.perf_counter()-st))

print('-'*10)

size = 1024

A = np.random.rand(size,16)

st = time.perf_counter()
A@A.T
print('dot\t python\t time :\t{}s'.format(time.perf_counter()-st))

st = time.perf_counter()
sample.dot(A)
print('dot\t cpp\t time :\t{}s'.format(time.perf_counter()-st))

print('-'*10)