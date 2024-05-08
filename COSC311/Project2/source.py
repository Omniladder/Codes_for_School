import pandas as pd
from matplotlib import pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

from sklearn.neural_network import MLPClassifier
from sklearn.svm import SVC
from sklearn.naive_bayes import GaussianNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.ensemble import RandomForestClassifier

# This Segment of code sets up the data to be used
dataFiles = ["COUGH.csv", "EAT.csv", "SIT.csv", "WALK.csv", "DRINK.csv", "READ.csv"]
datasets = []

for i in dataFiles:
    tempData = pd.read_csv(i)
    tempData = tempData.drop(0)
    tempData = tempData.apply(pd.to_numeric)
    datasets.append(tempData)

#This section generates various Windows of data for the algorithm to predict from

def slidingWindow(windowSize, dataset):
    
    
    numSegments = int((len(dataset)) / windowSize)
    segments = []
    
    #Grabs Window worth of Data
    for i in range(numSegments):
        segments.append(dataset.iloc[i * windowSize : i * windowSize + windowSize])
    
    if (len(tempData) % windowSize != 0):
        segments.append(dataset.iloc[len(dataset) - windowSize : len(dataset)])

    return segments

def developWindow(windowSize, datasets):
    labels = []
    segmentations = []
    
    for i, k in enumerate(datasets):
        tempSeg = slidingWindow(windowSize, k)
        segmentations.append(tempSeg)
        for j in range(len(tempSeg)):
            labels.append(i)
    
    
    segmentations = sum(segmentations, []) #This is craziest way of flattening a list

    for i in range(len(segmentations)):
        segmentations[i] = segmentations[i].values.flatten()
    
    Scaler = StandardScaler()

    Scaler.fit(segmentations)

    segmentations = Scaler.fit_transform(segmentations)
    #print(segmentations)
    return segmentations, labels

svc = SVC()

'''for i in [i * 100 + 1 for i in range(int(1024 / 100))]:
    segments, labels = developWindow(i, datasets)


    x_train, x_test, y_train, y_test = train_test_split(segments, labels, test_size=0.99, random_state=0)

    #sum(x_train) #Flatten Training Data so SVM can work


    svc.fit(x_train, y_train)

    print(svc.score(x_test, y_test))'''

segments, labels = developWindow(101, datasets)


x_train, x_test, y_train, y_test = train_test_split(segments, labels, test_size=0.99, random_state=0)


svc = SVC(kernel='linear')
svc.fit(x_train, y_train)

weights = svc.coef_ #Grabs Weight Coeffcients

weights = abs(weights)
weights = sum(weights)

indexWeights = []

for i, j in enumerate(weights):
    indexWeights.append((j, i))

indexWeights = sorted(indexWeights, reverse=True)

indexesKeep = []

for i in indexWeights[:20]:
    indexesKeep.append(i[1])

preSegments = segments

segments = segments[:, indexesKeep]


def testClassifiers(trainX, trainY, testX, testY):

    knn = KNeighborsClassifier()
    svc = SVC()
    randForest = RandomForestClassifier()
    mlp = MLPClassifier(max_iter=1000)
    naiveBayes = GaussianNB()

    algorithms = [knn, svc, randForest, mlp, naiveBayes]

    for i in algorithms:
        i.fit(trainX, trainY)
    
    for i in algorithms:
        print(i.score(testX, testY))

print("Self Test")

print()

testClassifiers(segments, labels, segments, labels)

print()

print("Independent Test")

print()

x_train, x_test, y_train, y_test = train_test_split(segments, labels, test_size=0.2, random_state=0)

testClassifiers(x_train, y_train, x_test, y_test)

print()

print("Independent Test With Full Features")

x_train, x_test, y_train, y_test = train_test_split(preSegments, labels, test_size=0.2, random_state=0)

print()

testClassifiers(x_train, y_train, x_test, y_test)
