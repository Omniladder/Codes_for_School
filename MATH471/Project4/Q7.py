import math as m
import numpy as np
from matplotlib import pyplot as plt 

ys = []
ts = []
error = []

yn = 2
h = .0625
tn = 0

'''ys.append(yn)
ts.append(tn)
error.append(yn - 3 * np.exp(-tn) + tn - 1)'''

for i in range(16):
    
    yn = yn + h * (tn - yn)
    ys.append(yn)
    ts.append(tn)
    error.append(yn - (3 * np.exp(-tn) + tn - 1))
    tn = tn + h


t=np.arange(0, 1, 0.05) 
y= 3 * np.exp(-t) + t - 1
fig=plt.figure() 
ax=fig.add_axes ([0,0,1,1]) 


ax.plot (t,y, label="Actual Solution") 

ax.plot (ts,ys, linestyle=':', label="Approximation") 

ax.plot (ts,error, linestyle='-', label="Error") 
ax.scatter (ts,ys) 

plt.legend()

ax. set_title("Eulers Function Example") 
ax. set_xlabel('t')
ax. set_ylabel ('y')

plt.show()