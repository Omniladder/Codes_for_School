import sympy as sp

'''
Defines Various Variables for Expression
'''
x = sp.symbols('x')
x_n = sp.symbols('x0:4')


a,b = sp.symbols('a b')

h = sp.symbols('h')


'''
Constructs all the lagrange polynomials
'''
def createLagrange(x, Xs):
    lagranges = []
    for xn in Xs:
        f = 1
        g = 1
        for i in [x_i for x_i in Xs if x_i != xn]:
            f *= (x - i)
            g *= (xn - i)
    

        f /= g

        lagranges.append(f)
    return lagranges


'''
Puts all the terms in reference to distance between it and a
'''
def substiuteh(lagrange, h, Xs):
    for index, term  in enumerate(Xs):
        lagrange = lagrange.subs(term, Xs[0] + index * (x_n[-1] - x_n[0])/(len(Xs) - 1))
    return lagrange




'''
Main Part of the code
'''
lagrangeFormulas = createLagrange(x, x_n)

for index, lagrange in enumerate(lagrangeFormulas):
    newLagrange = substiuteh(lagrange, h, x_n)
    

    newLagrange = sp.integrate(newLagrange, (x,x_n[0], x_n[-1]))

    newLagrange = sp.cancel(newLagrange)


    newLagrange =newLagrange.subs(x_n[0], a)
    newLagrange =newLagrange.subs(x_n[-1], b) 


    print("Original Formula: ", lagrange)
    print(f"Coeffcient {index + 1}: ", newLagrange, "\n")


