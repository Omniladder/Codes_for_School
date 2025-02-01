#Breast Cancer Dataset
from sklearn.datasets import load_breast_cancer

#Baseline Classifier
from sklearn.svm import SVC

#Ensemble Classifier
from sklearn.ensemble import RandomForestClassifier

#Grid Search for Parameter tuning
from sklearn.model_selection import train_test_split, GridSearchCV

#Classification report and confusion matrix for analysis
from sklearn.metrics import classification_report, confusion_matrix

'''
    Extracts the Data to use on model
'''

#Grabbing Data
dataset = load_breast_cancer()
target = dataset.target
data = dataset.data

#Splitting Data
X_train, X_test, y_train, y_test = train_test_split(data, target, test_size=0.30)


'''
    Training and usage of baseline classification model
'''

print("SVM Results")

#Creates and trains best baseline model with best parameters
parameters = {'kernel':('linear', 'rbf','sigmoid'), 'gamma':('scale', 'auto'), 'decision_function_shape' : ('ovo', 'ovr')}

model = SVC()
model = GridSearchCV(model, parameters)

model.fit(X_train, y_train)
print("Best SVM Parameters")
print(model.best_params_)

# Tests model on data

y_pred = model.predict(X_test)

print("SVM Classification Report")
print(classification_report(y_test, y_pred))

print("SVM Confusion Matrix")

cm = confusion_matrix(y_test, y_pred)
print(cm)


'''
    Training and usage of ensemble classification model
'''

print("Random Forest Results")

#Creates and trains best baseline model with best parameters
parameters = {'criterion' : ('gini', 'entropy', 'log_loss'), 'max_features' : ('sqrt', 'log2'), 'class_weight' : ('balanced', 'balanced_subsample')}

model = RandomForestClassifier()
model = GridSearchCV(model, parameters)

model.fit(X_train, y_train)
print("Best Random Forest Parameters")
print(model.best_params_)

# Tests model on data

y_pred = model.predict(X_test)

print("Random Forest Classification Report")
print(classification_report(y_test, y_pred))

print("Random Forest Confusion Matrix")

cm = confusion_matrix(y_test, y_pred)
print(cm)

