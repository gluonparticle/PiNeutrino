#Program 6 Dataset 

import seaborn as sns

df = sns.load_dataset("tips")
df.to_csv('Prog6.csv', index=False)
print(f"Successfully saved dataset!")