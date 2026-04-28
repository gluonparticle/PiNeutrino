# Program 4

import numpy as np
import pandas as pd

with open('Program4_data.csv', 'w') as f:
    f.write("sky,airTemp,humidity,wind,water,forecast,enjoySport\n")
    f.write("Sunny,Warm,Normal,Strong,Warm,Same,Yes\n")
    f.write("Sunny,Warm,High,Strong,Warm,Same,Yes\n")
    f.write("Rainy,Cold,High,Strong,Warm,Change,No\n")
    f.write("Sunny,Warm,High,Strong,Cool,Change,Yes")

data = pd.read_csv('Program4_data.csv')

def train(concepts, target):
    specific_h = concepts[0].copy()
    for i, h in enumerate(concepts):
        if target[i] == "Yes":
            for x in range(len(specific_h)):
                if h[x] != specific_h[x]:
                    specific_h[x] = "?"
    return specific_h

concepts = np.array(data.iloc[:, 0:-1])
target = np.array(data.iloc[:, -1])

print('Data', data)
print('\nConcept\n', concepts)
print('Target', target)
print(train(concepts, target))