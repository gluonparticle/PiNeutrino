import math
n=int(input('enter the number of elements in series:'))
num_list= []
print('enter the',n,'elements of the list:')
for i in range (n):
    num_list.append(int(input(str(i+1)+ ':')))
print(num_list)
sum_series = 0
sum_square = 0
for x in num_list:
    sum_series+=x
mean = sum_series/n
for x in num_list:
    sum_square+=(x-mean)**2
variance = sum_square/n
std_dev = math .sqrt(variance)
print('the mean =', mean, 'variance = ',variance, 'and' 'stanadard deviation = ',std_dev)

print('using numpy package:')
import numpy as np
print('the mean = {:.2f}, variance = {:.2f} and standard deviation = {:.2f}'
     .format(np.average(num_list),np.var(num_list),np.std(num_list)))





ifile = open('sam.txt')
dict_words = { }
for line in ifile:
    words = line.split( )
    for word in words:
        dict_words[word]= dict_words.get(word, 0)+1
list_words = [ ]
for key, val in dict_words.items( ):
    list_words.append((val,key))
list_words.sort(reverse = True)
print('the slice of ten items of sorted dictionary are : ')
print(list_words[0:10])



















num = input ('input multi-digit number :')
n=len(num)
n0,n1,n2,n3,n4,n5,n6,n7,n8,n9 = 0,0,0,0,0,0,0,0,0,0
for i in range(n) :
    if num[i] =='0':
        n0+=1
    elif num[i] =='1':
        n1+=1
    elif num[i] =='2':
        n2+=1
    elif num[i] =='3':
        n3+=1
    elif num[i] =='4':
        n4+=1
    elif num[i] =='5':
        n5+=1
    elif num[i] =='6':
        n6+=1
    elif num[i] =='7':
        n7+=1
    elif num[i] =='8':
        n8+=1
    elif num[i] =='9':
        n9+=1
dfreq = [n0,n1,n2,n3,n4,n5,n6,n7,n8,n9]
print('the number', num, 'has:')
for i in range(10):
    if dfreq[i] ==0:
        continue
    print(i, 'digit', dfreq[i], 'times')
    
count = [0,0,0,0,0,0,0,0,0,0]
for i  in range (10):
    for j in range(n):
        if num[j]==str(i):
            count[i]+=1
print('the frequency of each digit in',num, 'is : ')
print(count)

dict = { }
for i in num :
    if i not in dict:
        dict[i]=1
    else:
        dict[i]+=1
print('the frequency of each digit in',num, 'is : ')
print(dict)

ddict = { }
for j in num:
    ddict[j]=ddict.get(j,0)+1
print(ddict)
