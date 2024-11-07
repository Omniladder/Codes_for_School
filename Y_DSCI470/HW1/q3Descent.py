
def derivf(x):
    return 6 * x - 5

def gradientDecent(x=0, learningRate = .01, numIter = 1000):
    x = 0 #Simple Starting Value
    for i in range(numIter):
        x = x - learningRate * derivf(x)
    
    return x


'''
#The one Liner
def gradientDecent(x=0,learningRate = .01, numIter = 10):
    return x if numIter == 0 else gradientDecent(x, learningRate, numIter - 1) - learningRate * (6 * gradientDecent(x, learningRate, numIter - 1) - 5)
'''

print("Approx.: ", gradientDecent(x=0,learningRate=.1, numIter=10000))
print("Real Answer: ", 5/6)
