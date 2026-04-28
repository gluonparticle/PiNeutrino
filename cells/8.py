# Program 8

import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier, plot_tree
from sklearn.metrics import accuracy_score

data = load_breast_cancer()
X, y = data.data, data.target

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

clf = DecisionTreeClassifier(random_state=42).fit(X_train, y_train)
y_pred = clf.predict(X_test)

print(f"Model Accuracy: {accuracy_score(y_test, y_pred) * 100:.2f}%")

new_sample = X_test[0].reshape(1, -1)
prediction = clf.predict(new_sample)
p_class = data.target_names[prediction[0]]
print(f"Predicted Class for the new sample: {p_class}")

plt.figure(figsize=(12, 8))
plot_tree(clf, 
          filled=True, 
          feature_names=data.feature_names.tolist(), 
          class_names=data.target_names.tolist())
plt.title("Decision Tree - Breast Cancer Dataset")
plt.show()