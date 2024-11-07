'''
def f(x):
    return x ** 3 - 2

def fprime(x):
    return 3 * x ** 2
'''

def ffprime(x, a):
    return x * (2 - a * x)

def newtonsMethod(x0, e):
    xn = x0
    xn1 = x0
    xn = ffprime(xn, 6/8)

    while(not (5 * abs(xn - xn1) <= e / 5)):
    
        xn1 = xn
        xn = ffprime(xn, 6/8)
        
        


    
    return xn

print(newtonsMethod(1, 1e-16))