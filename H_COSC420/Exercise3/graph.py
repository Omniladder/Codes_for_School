from matplotlib import pyplot as plt 

fp = [.95, .9, .75, .5]
fs = []
p = [5,10,100,1000,10000]
s = []

'''ys.append(yn)
ts.append(tn)
err
or.append(yn - 3 * np.exp(-tn) + tn - 1)'''

#fig=plt.figure() 
#ax=fig.add_axes ([0,0,1,1]) 

Ss = []

for i in fp:
    s = []
    for j in p:
        s.append(1 / (1 - i + i / j))

    Ss.append(s)
    plt.plot (p,s, label=f"fp = {i}") 
    plt.scatter (p,s) 

plt.xscale('log')


plt.legend()

plt.title("Speedup for # of Processes") 
plt.xlabel('p')
plt.ylabel ('s')

print(Ss)

plt.show()