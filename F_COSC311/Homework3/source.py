from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_absolute_error, mean_squared_error, root_mean_squared_error


from sklearn import datasets
from sklearn.decomposition import PCA
from sklearn.cluster import KMeans
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay, classification_report

import matplotlib.pyplot as plt
import seaborn as sb
import numpy as np
from scipy import stats
import stats as st
import pandas as pd


columns = ["Vendor", "Model Name", "MYCT", "MMIN", "MMAX", "CACH", "CHMIN", "CHMAX", "PRP", "ERP"]


file = pd.read_csv("machine.data", names = columns)

coorelations = []

for i in columns[3:len(columns) - 1]:
#    print(file[i])
    coor = st.correlation(file[i], file['ERP'])

    coorelations.append((coor, i, 'ERP'))

coorelations = sorted(coorelations, reverse=True)

mostImport = [i[1] for i in coorelations[0:4]]

Y = file.iloc[:, -1:]
X = file.iloc[:, :-1]




X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=.4, random_state = 12)

regressModel = LinearRegression()


#print(X_train.columns)
#print(mostImport[0])

importNums = [i for i in range(len(columns)) if columns[i] in mostImport]

linReg = LinearRegression()


#for i in mostImport:
data = X_train.loc[:,mostImport]
linReg.fit(data, Y_train)


pred = linReg.predict(X_test.loc[:, mostImport])


mae = mean_absolute_error(Y_test, pred)
mse = mean_squared_error(Y_test, pred)
rmse = root_mean_squared_error(Y_test, pred)

print("Linear Regression Error: ")
print("MAE: ", mae)
print("MSE: ", mse)
print("RMSE: ", rmse)

print("")


digitData = datasets.load_digits()
digit = digitData.data

pca = PCA(n_components=.85)

pca.fit(digit)

#numCompon = len(pca.explained_variance_ratio_)

PCAdigit = pca.fit_transform(digit)

kmeans = KMeans(n_clusters=10, random_state=13)

kmeans.fit(PCAdigit)

print("Centers: ")
print(kmeans.cluster_centers_)

print()



pointsInCluster = []
pred = [0] * len(kmeans.labels_)
mode = 0


for i, j in enumerate(np.unique(kmeans.labels_)):
    pointsInCluster = [k for k, l in enumerate(kmeans.labels_) if l == j]
    for k in pointsInCluster:
        mode = stats.mode([digitData.target[l] for l in pointsInCluster]).mode
        pred[k] = mode

accuracyData = classification_report(digitData.target, pred)
print(accuracyData)


confMatrix = confusion_matrix(digitData.target, pred)

sb.heatmap(confMatrix, annot=True)

plt.show()

#print(PCAdigit)



