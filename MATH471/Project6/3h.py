def f(x):
    return x ** 3 - 2

def fprime(x):
    return 3 * x ** 2


def newtonsMethod(x0, e):
    xn = x0
    
    y = f(xn)
    xn1 = xn
    xn -= y / fprime(xn)
    i = 1
    while(not (5 * abs(xn - xn1) <= e / 5)):
    
        y = f(xn)
        xn1 = xn
        xn -= y / fprime(xn)
        i += 1
    
        


    
    return xn

print(newtonsMethod(1, 1e-6))