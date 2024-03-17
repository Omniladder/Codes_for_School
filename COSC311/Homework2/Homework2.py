import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sb


from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay, classification_report


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

def testAlgorithm(algorithm):
    predictions  = algorithm.predict(featureTest)
    print(algorithm.score(featureTest, classTest))

    confMatrix = classification_report(classTest, predictions)
    print(confMatrix)

    ConfusionMatrixDisplay.from_estimator(algorithm, featureTest, classTest)  
    plt.show()

def smallTest(algorithm):
    predictions  = algorithm.predict(featureTest)
    print(algorithm.score(featureTest, classTest))

featureTrain, featureTest, classTrain, classTest  = grabData()


for i in range(24):
    knn = KNeighborsClassifier(n_neighbors=(i + 1))
    knn.fit(featureTrain, classTrain)
    smallTest(knn)



