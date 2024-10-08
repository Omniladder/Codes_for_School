#Allows usage of math functions
import math
#Allows User to type in as Fraction
#from fractions import Fraction
import matplotlib.pyplot as plt

def f(x):
    return math.atan(x)

def fPrime(h):
    #h = float(Fraction(input("Please Input Your h\n")))
    x = math.pi / 4

    approx = (8 * f(x + h) - 8 * f(x - h) - f(x + 2 * h) + f(x - 2 * h)) / (12 * h)

    return approx

approx = []

start_index = 500 
end_index = 1000

for i in range(1, end_index):
    approx.append(fPrime(1 / i))

x = range(len(approx))


# Slice the x and y values starting from the specified index
x = x[start_index:]
approx = approx[start_index:]
# Plot the graph
plt.plot(x, approx)

# Add labels and title
plt.xlabel('Index')
plt.ylabel('Y values')
plt.title('Graph of Y values')

# Show the graph
plt.show()