# Program 5

import numpy as np
import matplotlib.pyplot as plt
from sklearn.neighbors import KNeighborsClassifier

data = np.random.rand(90).reshape(-1, 1)
train_X, test_X = data[:45], data[45:]
train_y = np.array(["Class1" if x <= 0.5 else "Class2" for x in train_X])
k_values = [1, 2, 3, 4, 5, 20, 30]
results = {}

plt.figure(figsize=(10, 15))
colors = {"Class1": "blue", "Class2": "red"}

for i, k in enumerate(k_values):
    knn = KNeighborsClassifier(n_neighbors=k).fit(train_X, train_y)
    pred_y = knn.predict(test_X)
    results[k] = pred_y
    
    plt.subplot(4, 2, i + 1)
    plt.scatter(train_X, [0]*45, c=[colors[l] for l in train_y], alpha=0.5, marker="o")
    
    for cls in ["Class1", "Class2"]:
        pts = test_X[pred_y == cls]
        plt.scatter(pts, [1]*len(pts), c=colors[cls], marker="x", label=cls)
    
    plt.title(f"k-NN Results (k={k})")
    plt.yticks([0, 1], ["Train", "Test"])
    plt.grid(True)

plt.subplots_adjust(hspace=0.5, wspace=0.3)
plt.show()

print("--- k-Nearest Neighbors Classification ---")
print("Training dataset: 45 points (x <= 0.5 -> Class1, x > 0.5 -> Class2)")
print("Testing dataset: 45 points to be classified\n")

for k in k_values:
    print(f"Results for k = {k}:")
    predictions = results[k]
    for idx in range(len(predictions)):
        print(f"Point x{idx+46} (value: {test_X[idx][0]:.4f}) is classified as {predictions[idx]}")
    print("\n")

print("Classification complete.")