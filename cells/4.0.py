#Program 4 dataset 


with open('Program4_data.csv', 'w') as f:
    f.write("sky,airTemp,humidity,wind,water,forecast,enjoySport\n")
    f.write("Sunny,Warm,Normal,Strong,Warm,Same,Yes\n")
    f.write("Sunny,Warm,High,Strong,Warm,Same,Yes\n")
    f.write("Rainy,Cold,High,Strong,Warm,Change,No\n")
    f.write("Sunny,Warm,High,Strong,Cool,Change,Yes")
    
#Or use manual with "%%writefile Program4_data.csv" in the beginning
'''
%%writefile Program4_data.csv
sky,airTemp,humidity,wind,water,forecast,enjoySport
Sunny,Warm,Normal,Strong,Warm,Same,Yes
Sunny,Warm,High,Strong,Warm,Same,Yes
Rainy,Cold,High,Strong,Warm,Change,No
Sunny,Warm,High,Strong,Cool,Change,Yes
'''

print()