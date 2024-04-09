import pandas as pd
from matplotlib import pyplot as plt
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import classification_report
from sklearn import tree
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
import seaborn as sb



knn = KNeighborsClassifier(n_neighbors=1)


columns = ['Column ' + str(i + 1) for i in range(7)]
columns.append('Final Class')

dataset = pd.read_csv("wifi_localization.txt", delimiter = '\t', names = columns)

print("Self Test:")

featureData = dataset.iloc[:, :6]
testData = dataset.iloc[:, -1]

#print(testData)
knn.fit(featureData, testData)

predictions = knn.predict(featureData)

csr = classification_report(testData, predictions)
print(csr)

DTree = tree.DecisionTreeClassifier()
DTree.fit(featureData, testData)

predictions = DTree.predict(featureData)

csr = classification_report(testData, predictions)
print(csr)


print()
print("Independent Test:")

featureTrain, featureTest, classTrain, classTest = train_test_split(featureData, testData, test_size = .30, random_state=0)

iKnn = KNeighborsClassifier(n_neighbors = 4, weights = 'distance')

iKnn.fit(featureTrain, classTrain)

predictions = iKnn.predict(featureTest)

csr = classification_report(classTest, predictions)

print(csr)


iDTree = tree.DecisionTreeClassifier()

iDTree.fit(featureTrain, classTrain)

predictions = iDTree.predict(featureTest)

csr = classification_report(classTest, predictions)

print(csr)


dataSplit = [i * .1 + .1 for i in range(5)]


print("30% Split Testing")
featureTrain, featureTest, classTrain, classTest = train_test_split(featureData, testData, test_size = .3, random_state=0)

iKnn = KNeighborsClassifier(n_neighbors = 4, weights = 'distance')

iKnn.fit(featureTrain, classTrain)

predictions = iKnn.predict(featureTest)

csr = classification_report(classTest, predictions)

confMatrix = confusion_matrix(classTest, predictions)

sb.heatmap(confMatrix, annot=True)

plt.show()

print(csr)


iDTree = tree.DecisionTreeClassifier()

iDTree.fit(featureTest, classTest)

predictions = iDTree.predict(featureTest)

csr = classification_report(classTest, predictions)

print(csr)


iKnn = KNeighborsClassifier(n_neighbors = 3, weights = 'distance')
iDTree = tree.DecisionTreeClassifier()

treeScores = []
KNNScores = []

for i in dataSplit:
    featureTrain, featureTest, classTrain, classTest = train_test_split(featureData, testData, test_size = i, random_state=0)


    iKnn.fit(featureTrain, classTrain)



    iDTree.fit(featureTrain, classTrain)

    treeScore = iDTree.score(featureTest, classTest)
    knnScore = iKnn.score(featureTest, classTest)

    treeScores.append(treeScore)
    KNNScores.append(knnScore)

width = .5
plt.bar([i * width * 3 for i in range(len(treeScores))], treeScores, width, label = 'Decision Tree Accuracy')
plt.bar([i * width * 3 + width for i in range(len(KNNScores))], KNNScores, width, label = 'KNN Accuracy')

print(treeScores)

dataSplit = [(str(round(i * 100, 0)) + "%") for i in dataSplit]

plt.xticks([i * width * 3 + width / 2  for i in range(len(KNNScores))], dataSplit)

plt.legend()

plt.show()


