#Allows usage of math functions
import math
#Allows User to type in as Fraction
from fractions import Fraction

#Function f(x)
def f(x):
    return math.sin(math.pi * x)

#Takes in user input uses Fraction to convert fraction into something usable than converts that into a decimal
x = float(Fraction(input("Please Input Your x\n")))
h = float(Fraction(input("Please Input Your h\n")))

#Formulas for calculating these things Based on Forward Difference
approx1 = (f(x + h) - f(x)) / h
error1 = (math.pi ** 2 * h) / 2

#Formulas for calculating Based on Central Difference
approx2 = (f(x + h) - f(x - h)) / (2 * h)
error2 = (math.pi ** 3 * h ** 2) / 6

#Outputs
print("Forward Difference Approximation: ", approx1, " Error: ", error1)
print("Central Difference Approximation : ", approx2, " Error: ", error2)


