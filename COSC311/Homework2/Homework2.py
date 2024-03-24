import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sb
import numpy as np

from sklearn.svm import SVC
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.neural_network import MLPClassifier
#from sklearn.tree import DecisionTreeClassifier

from sklearn.ensemble import VotingClassifier
from sklearn.model_selection import GridSearchCV

from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay, classification_report
from sklearn.preprocessing import StandardScaler, PolynomialFeatures
from sklearn.pipeline import make_pipeline

'''
This Code here is used to quickly grab and then split the data set into its needed pieces

'''

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







#Main Code 

featureTrain, featureTest, classTrain, classTest = grabData()

#Rescales the code
scale = StandardScaler()
scale.fit(featureTrain)
featureTrain = scale.transform(featureTrain)
featureTest = scale.transform(featureTest) # Scales based on deviavtion


#
#for i in range(20):

#KNN Training 1 Neighbor
knn = KNeighborsClassifier(n_neighbors = 1)
#knn.fit(featureTrain, classTrain)
#predictions  = knn.predict(featureTest)'''

#KNN training 3 Neighbors
#'''knn = KNeighborsClassifier(n_neighbors = 3)
#knn.fit(featureTrain, classTrain)
#predictions  = knn.predict(featureTest)'''


#MLPClassifier
#mlp = MLPClassifier(hidden_layer_sizes=500, alpha=.1, random_state=1, batch_size=10)
#mlp = MLPClassifier(hidden_layer_sizes= 501, alpha=.1, random_state=1, batch_size=30, solver = 'lbfgs', max_iter = 10000, tol = 5e-5, max_fun=50000)
mlp = MLPClassifier(hidden_layer_sizes= 500, alpha=1e-5, random_state=1, batch_size=30, solver = 'adam', max_iter = 10000, tol=1e-5) #TEST BATCH SIZES ON MLP
#mlp.fit(featureTrain, classTrain)
#predictions  = mlp.predict(featureTest)


#Decision Tree
#randForest = RandomForestClassifier(max_depth=16, random_state=0)
randForest = RandomForestClassifier(max_depth=16, random_state=0, n_estimators = 321)
#randForest.fit(featureTrain, classTrain)
#predictions  = randForest.predict(featureTest)'''

#SVC
svc = SVC(kernel='rbf', C=7, gamma="auto", probability=True, decision_function_shape='ovo')
#svc = SVC(kernel='poly', C=500, probability=True, decision_function_shape='ovo', coef0=1.5)
#svc.fit(featureTrain, classTrain)
#predictions  = svc.predict(featureTest)'''

#Logistic Regression


logReg = make_pipeline(PolynomialFeatures(2) ,LogisticRegression(max_iter = 10002, C=1, solver = 'lbfgs', tol=1e-6))#Remove features and add degrees
#logReg.fit(featureTrain, classTrain)
#predictions = logReg.predict(featureTest)




for i in range(30):
    votingAlgo = VotingClassifier(                                        
        estimators=[
            ('logistic', logReg),
            ('svc', svc), 
            ('Random Forest', randForest), 
            ('MLP', mlp), 
            ('KNN', knn)
            ],
        weights=[1.3 * 2, 1.3 * 2, 1.4 * 2, 2.2 * 2, 1 * 2],
        voting='soft'
        )

    votingAlgo.fit(featureTrain, classTrain)
    print(2, votingAlgo.score(featureTest, classTest))

#params = {'lr__C': [1.0, 100.0], 'rf__n_estimators': [20, 200]}

#grid = GridSearchCV(estimator=votingAlgo, param_grid=params, cv=5)

#grid.fit(featureTrain, classTrain)

predictions = votingAlgo.predict(featureTest)

#voteRegress.fit(featureTrain, classTrain)

#predictions = voteRegress.predictions(featureTest)

confMatrix = classification_report(classTest, predictions)
print(confMatrix)

