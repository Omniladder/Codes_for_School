import math as m
def f(x):
    return 1 / x

def trapezoid(f, b, a, n):

    approx = .5 *(f(a) + f(b))


    h = (b - a)/n

    for k in range(1, int(n)):
        approx += f(a + k*h)
    return approx * h

print("Approximation: ", trapezoid(f, 2, 1, 2887))
print("Comparison:    ", m.log(2) - m.log(1))