import numpy as np

def gradientDecent(learningRate = .01, x = np.array([ 0 , 0 , 0 , 0 , 0 ]), iterations = 100):
    X = np.array([[1,1,1,1,1],[1,2,4,8,16],[1,3,9,27,81],[1,4,16,64,256],[1,5,25,125,625]])
    y = np.array([5,31,121,341,781])
    XT = X.T

    for i in range(iterations):
        x = x - learningRate * (XT @ ((X @ x) - y))
    return x


print(gradientDecent(learningRate = .000001, x = np.array([0,0,0,0,0]), iterations = 15000000))