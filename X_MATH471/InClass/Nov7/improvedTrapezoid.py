import math as m

def f(x):
    return m.sqrt(4 - x**2)


def trapezoidRule(f, a, b, n):
    sum = 0


    h = (b - a) / n

    sum += f(a)
    sum += f(b)

    for i in range(1, n):
        sum += 2 * f(a + h * i)
    

    return (sum * h / 2) - (1 / 12) * h**2 * (f(b) - f(a))

print("Trapezoid: ",trapezoidRule(f, 0,2, 100000))