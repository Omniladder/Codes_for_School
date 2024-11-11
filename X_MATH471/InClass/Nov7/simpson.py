import math as m

def f(x):
    return m.sqrt(4 - x**2)


def simpsonsRule(f, a, b, n):
    sum = 0

    sum += f(a)
    sum += f(b)
    
    h = (b - a) /n

    for i in range(1, n):
        if(i % 2 == 0):
            sum += 4 * f(a + i * h)
        else:
            sum += 2 * f(a + i * h)

    sum *= 1/3 * h

    return sum


print(simpsonsRule(f, 0,2, 100000))