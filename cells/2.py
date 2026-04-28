# Program 2

import pandas as pd 
import seaborn as sns 
import matplotlib.pyplot as plt 
from sklearn.datasets import fetch_california_housing 
import warnings



california_data = fetch_california_housing(as_frame=True) 
data = california_data.frame 

correlation_matrix = data.corr() 

plt.figure(figsize=(10, 8)) 
sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', fmt='.2f', linewidths=0.5) 
plt.title('Correlation Matrix of California Housing Features') 
plt.show() 

sns.pairplot(data, diag_kind='kde', plot_kws={'alpha': 0.5}) 
plt.suptitle('Pair Plot of California Housing Features', y=1.02)
plt.show()