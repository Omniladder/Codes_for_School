import math as m

def f(y):
    return -1 * y * m.log(y)

def realAnswer(t):
    return m.exp(m.log(3) * m.exp(-t))


def approxAnswer(t, h, y_0, f):
    n = int(t/h)
    y_n = y_0
    for i in range(1,n+1):
        k1 = h * f(y_n)
        k2 = h * f(y_n + 1/2 * k1)
        k3 = h * f(y_n + 1/2  * k2)
        k4 = h * f(y_n + k3)

        y_n += 1/6 * (k1 + 2 * k2 + 2 * k3 + k4)
        #rint(k2)
    
    return y_n

#I couldn't find any error term besides O(h^2) one
def theoryError(h):
    return h **2

for i in range(5):
    h =  1/(i * 2 + 2)
    print("h: ",h)
    print("Real Error: ", realAnswer(3) - approxAnswer(3, h, 3, f))
    print("Theortical Error: ", theoryError(h))
    print()
    print()