import math as m

def hornersrule(A,x):
    px=0
    for a in A:
        px=a+px*x
    return px
#print(hornersrule([1,-5,6],3))

def DurandKerner(A,I,N):
    if len(A)-1 !=len(I):
        return "It's broken"
    n=len(A)-1
    for k in range(0,N):
        for i in range(0,n):
            p=[0 for a in A]
            I2=I.copy()
            p[i]=hornersrule(A,I2[i])
            #print(p[i],i,k)
            #product=[(I[i]-I[n-1-j]) for j in range(0,n) if n-1-j!=i]
            #print(product)
            I[i]=I2[i]-(p[i]/m.prod((I2[i]-I2[j]) for j in range(0,n) if j!=i))
            #print(I[i],i,k)
    return I
for root in (DurandKerner([1,0,0,0,0, 0,0, -1, -1],[1, .7+.7j, 1j, -.7+.7j, -1, .7j, -.7-.7j, -1j],100000)):
    print(root)