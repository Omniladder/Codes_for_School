import math as m

def f(x):
    return m.sqrt(4 - x**2)


def midpointRule(f, a, b, n):
    sum = 0

    h = (b - a) /n

    for i in range(n):
        sum += f(a + h * i) + f(a + h * (i + 1))

    

    return h * sum * .5


print(midpointRule(f, 0,2, 100000))