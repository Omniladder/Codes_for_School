import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sb
import numpy as np

from sklearn.svm import SVC
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.neural_network import MLPClassifier
from sklearn.discriminant_analysis import QuadraticDiscriminantAnalysis
#from sklearn.tree import DecisionTreeClassifier

from sklearn.ensemble import VotingClassifier, HistGradientBoostingClassifier, AdaBoostClassifier
from sklearn.model_selection import GridSearchCV
from sklearn.multiclass import OneVsRestClassifier

from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay, classification_report
from sklearn.preprocessing import StandardScaler, PolynomialFeatures
from sklearn.pipeline import make_pipeline


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






featureTrain, featureTest, classTrain, classTest = grabData()

#Rescales the code
scale = StandardScaler()
scale.fit(featureTrain)
featureTrain = scale.transform(featureTrain)
featureTest = scale.transform(featureTest) # Scales based on deviavtion

#solvers = ['lbfgs', 'sgd', 'adam']


'''tolerance = [0, .1, .2, .3, .4, .5]
for i in [1, 0, -1]:
    randForest = RandomForestClassifier(max_depth=16, random_state=0, n_estimators = 321)
    randForest.fit(featureTrain, classTrain)
    print(i, randForest.score(featureTest, classTest))'''






coeff = [1,1e-1,1e-2,1e-3,1e-4,1e-5,1e-6,1e-7,1e-8,1e-9,1e-10, 1e-11, 1e-12, 1e-13, 1e-14, 1e-15]
cache = [i * 100 + 1 for i in range(100)]
learning = [i + 1 for i in range(99)]




'''for i in learning:
    algo = AdaBoostClassifier(algorithm='SAMME', n_estimators=2901, learning_rate = i)
    algo.fit(featureTrain,classTrain)
    print(i, algo.score(featureTest, classTest))'''

'''for i in coeff:
    algo = GaussianNB(var_smoothing = 1e-1)
    algo.fit(featureTrain,classTrain)
    print(algo.score(featureTest, classTest))'''



'''for i in coeff:
    algo = HistGradientBoostingClassifier(learning_rate= 3/30, max_iter = 291, class_weight='balanced')
    algo.fit(featureTrain,classTrain)
    print(algo.score(featureTest, classTest))'''



'''for i in [i + 1 for i in range(20)]:
    knn = KNeighborsClassifier(n_neighbors = 4, weights='distance')
    knn.fit(featureTrain, classTrain)
    print(i , knn.score(featureTest, classTest))'''




'''for i in range(700):
    svc = SVC(kernel='poly', C=500, probability=True, decision_function_shape='ovo', coef0=1.5)
    svc.fit(featureTrain, classTrain)
    print(i +1, svc.score(featureTest, classTest))'''

'''for i in range(20):
    svc = SVC(kernel='rbf', C=7, gamma="auto", probability=True, decision_function_shape='ovo')
    svc.fit(featureTrain, classTrain)
    print(svc.score(featureTest, classTest))'''







'''learning_rate = [2]
tolerance = [1, 2, 3, 4, 5, 6]

logReg = make_pipeline(PolynomialFeatures(2) ,LogisticRegression(max_iter = 10002, C=1, solver = 'lbfgs', tol=1e-6))
logReg.fit(featureTrain, classTrain)

#print(logReg.score(featureTest, classTest))'''



'''for i in range(5):
    logReg = make_pipeline(PolynomialFeatures(i + 1) ,LogisticRegression(max_iter = 10002, C=1, solver = "liblinear", tol=1e-3))

    ovr = OneVsRestClassifier(logReg)

    ovr.fit(featureTrain, classTrain)
    print(ovr.score(featureTest, classTest))'''








'''tolerance = [1 - 1e-1, 1 - 1e-2, 1 - 1e-3, 1 - 1e-4, 1 - 1e-5, 1 - 1e-6, 1 - 1e-7, 1 - 1e-8, 1 - 1e-9, 1 - 1e-10, 1 - 1e-11, 0]

#    mlp = MLPClassifier(hidden_layer_sizes= 501, alpha=.1, random_state=1, batch_size=30, solver = 'lbfgs', max_iter = 10000, tol = 5e-5, max_fun=50000)
algo = MLPClassifier(hidden_layer_sizes= 500, alpha=1e-5, random_state=1, batch_size=30, solver = 'adam', max_iter = 10000, tol=1e-5)
algo.fit(featureTrain, classTrain)
#print(mlp.score(featureTest, classTest))'''

predictions = algo.predict(featureTest)

confMatrix = classification_report(classTest, predictions)
print(confMatrix)

#print(mlp.score(featureTest, classTest))'''
