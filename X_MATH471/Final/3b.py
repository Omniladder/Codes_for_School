import math as m


x = 1
for i in range(1,6):
    #X is point attempting to be approximated ex. f(1)

    h = 1/(2*i)

    def f(y, t_n):
        return -y * m.log(y)

    def second_Derv(t):
        return 3 ** m.exp(-t)*m.exp(-2*t)*m.log(3)*(m.exp(t) + m.log(3))

    def realAnswer(t):
        return m.exp(m.log(3) * m.exp(-t))

    def residualError(t,h):
        #0 used as it is the maximum of second derivative
        return 1/2 * h ** 2 * second_Derv(0)

    n = int(x / h)
    y_0 = 3


    y_n = y_0

    for i in range(0, n):
        y_n += h * f(y_n, i * h)


    print()

    print("Values for h = ", h)

    print("Real Answer. ", realAnswer(1))
    print("Approx Answer. ", y_n)

    print("Real Error. ", realAnswer(1) - y_n)

    #Outputs Truncation Error
    print("Therotical Error. ", 1/h*residualError(1, h))

print()

