from npClassSample import *
import numpy as np
import matplotlib.pyplot as plt

A = npClassSample()

K = 3*np.ones((3,3),dtype=int)

print(A.dot(None))
print(K@K.T@K)
A.print()
plt.plot(np.linspace(0,np.pi,100),A.returnZeroZero(np.linspace(0,np.pi*5,100)))
plt.show()