import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sb
import numpy as np

from scipy import stats

from sklearn import svm
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay, classification_report
from sklearn.preprocessing import StandardScaler, PolynomialFeatures



def grabData():
    
    attributes = []

    for i in range( 0, 65): # Builds a name for all the features
       attributes.append("Column " + str(i + 1)) # generates each features name
    attributes.append("Class") # labels the final answer column class

    dataset = pd.read_csv("FoodTypeDataset.csv", names = attributes) # Pulls in all the names

    finalClass = dataset.iloc[:, 65] # This is the final class we are trying to find
    totalAttri = dataset.iloc[:, [i for i in range(64)]] #This holds all the features before splitting

    featureTrain, featureTest, classTrain, classTest = train_test_split(totalAttri, finalClass, test_size = .20, random_state=0)

    return featureTrain, featureTest, classTrain, classTest 

def testAlgorithm(algorithm, featureTest, classTest):
    print(algorithm.score(featureTest, classTest))

    predictions  = algorithm.predict(featureTest)
    confMatrix = classification_report(classTest, predictions)
    print(confMatrix)

    ConfusionMatrixDisplay.from_estimator(algorithm, featureTest, classTest)  
    plt.show()

def smallTest(algorithm, featureTest, classTest):
    trueFeatures = [featureTest[i] for i in range(len(classTest)) if classTest[i]]
    trueClasses = [classTest[i] for i in range(len(classTest)) if classTest[i]]
    print(algorithm.score(trueFeatures, trueClasses), end =" ,")
    print(algorithm.score(featureTest, classTest), end =" :")
    return algorithm.score(trueFeatures, trueClasses)

def compareTests(algorithm1, algorithm2, featureTest, classTest):
    trueFeatures = [featureTest[i] for i in range(len(classTest)) if classTest[i]]
    trueClasses = [classTest[i] for i in range(len(classTest)) if classTest[i]]
    for i, j in enumerate(featureTest):
        if algorithm1.predict(j) != algorithm2.predict(j):
            print("Algorithm 1 Said: ", algorithm1.predict(j), " Algorithm 2 Said: ", algorithm2.predict(j), " Correct Answer is: ", classTest[i])

def booleanize(classes):

    booleanArray = [[False for i in range(len(classes))] for j in range(20)] # makes the boolean Array and sets everything to zero

    for i, j in enumerate(classes):
        booleanArray[j - 1][i] = True # goes through each class and  sets the approiate class number to 1

    return booleanArray # First Index is the class second is the specific element


featureTrain, featureTest, classTrain, classTest  = grabData()

scale = StandardScaler()
scale.fit(featureTrain)
featureTrain = scale.transform(featureTrain)
featureTest = scale.transform(featureTest) # Scales based on deviavtion


booleanClasses = booleanize(classTrain) # Gets True or False on all elements of amnm array for each class
booleanTest = booleanize(classTest)

logAlgo = LogisticRegression()
knn = KNeighborsClassifier(n_neighbors = 3)

algorithms = [0] * 20

poly = PolynomialFeatures(degree = 3 , interaction_only=False, include_bias=False)
X_poly = poly.fit_transform(featureTrain)
numNeighbors = 1


algorithms[0] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[0])
algorithms[1] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[1])

#algorithms[2] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[1])
algorithms[2] = LogisticRegression(max_iter = 1000).fit(X_poly, booleanClasses[2])

algorithms[3] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[3])
algorithms[4] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[4])

#algorithms[5] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[5])
algorithms[5] = LogisticRegression(max_iter = 1000).fit(X_poly, booleanClasses[5])

algorithms[6] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[6])
algorithms[7] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[7])
algorithms[8] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[8])
algorithms[9] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[9])
algorithms[10] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[10])

#algorithms[11] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[11])
algorithms[11] = LogisticRegression(max_iter = 1000).fit(X_poly, booleanClasses[11])
#algorithms[12] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[12])
algorithms[12] = LogisticRegression(max_iter = 1000).fit(X_poly, booleanClasses[12])

algorithms[13] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[13])

#algorithms[14] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[14])
algorithms[14] = LogisticRegression(max_iter = 1000).fit(X_poly, booleanClasses[14])

algorithms[15] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[15])
algorithms[16] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[16])
algorithms[17] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[17])

#algorithms[18] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[18])
algorithms[18] = LogisticRegression(max_iter = 1000).fit(X_poly, booleanClasses[18])

algorithms[19] = KNeighborsClassifier(n_neighbors = numNeighbors).fit(featureTrain, booleanClasses[19])


classProbability = [0] * 20
trainProbability = [0] * 20
#print(algorithms[0].predict_proba(featureTrain)[:, 1])

polyTest = poly.transform(featureTest)


for j, i in enumerate(algorithms):
    if type(i) == type(LogisticRegression(max_iter = 1000)):
        classProbability[j] = i.predict_proba(polyTest)[:, 1]
        trainProbability[j] = i.predict_proba(X_poly)[:, 1]
    else:
        classProbability[j] = i.predict_proba(featureTest)[:, 1]
        trainProbability[j] = i.predict_proba(featureTrain)[:, 1]

#print(classProbability)

print(len(trainProbability[0]), " : ", len(classTrain))
#print(len(trainProbability[0]), " : ", len(classTrain[0]))
trainProbability = np.transpose(trainProbability)
classProbability = np.transpose(classProbability)
finalKnn = KNeighborsClassifier(n_neighbors = 2).fit(trainProbability, classTrain)

#print(len(classProbability), " == ", len(classTest), " : ", len(classProbability[0]), " == ", len(classTest[0]), )

#smallTest(finalKnn, classProbability, classTest)
#print(algorithms)

#for i in algorithms:
    

#for i in range(20):
#    logAlgo = LogisticRegression(max_iter = 1000)
#    knn = KNeighborsClassifier(n_neighbors = 1)
#    knn.fit(featureTrain, booleanClasses[i])
#    print(i, " " , end ="")
#    poly = PolynomialFeatures(degree = 2 , interaction_only=False, include_bias=False)
    
    #knn2 = KNeighborsClassifier(n_neighbors = 2)
    #knn2.fit(featureTrain, booleanClasses[i])
#    X_poly = poly.fit_transform(featureTrain)

#    logAlgo.fit(X_poly, booleanClasses[i])

#    polyTest = poly.transform(featureTest)

#    print(i, " ", end = " ")
    #smallTest(knn2, featureTest, booleanTest[i])
#    smallTest(knn, featureTest, booleanTest[i])
#    print()


#logAlgo.fit(featureTrain, booleanClasses[12])
#knn.fit(featureTrain, booleanClasses[12])

#compareTests(logAlgo, knn, featureTest, booleanTest[12])

#algorithm = KNeighborsClassifier(n_neighbors=1)
#algorithm.fit(featureTrain, classTrain)
testAlgorithm(finalKnn, classProbability, classTest)


