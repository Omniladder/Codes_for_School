from sklearn import datasets
from sklearn.decomposition import PCA
from sklearn.cluster import KMeans
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay, classification_report

import matplotlib.pyplot as plt
import seaborn as sb
import numpy as np
from scipy import stats


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


