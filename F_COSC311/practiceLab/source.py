from sklearn.datasets import load_digits
from sklearn.svm import SVC
from sklearn.model_selection import train_test_split


import matplotlib.pyplot as plt


digits = load_digits()
#print(digits)

Xtrain, Xtest, Ytrain, Ytest = train_test_split(digits, digits.target, test_size=.2)


#svc = SVC(kernel = 'rbf')
#svc.fit(digits)




'''plt.gray()
plt.matshow(digits.images[5])


plt.show()'''
