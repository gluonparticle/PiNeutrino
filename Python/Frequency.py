##################################################################3
num = input("Enter a number: ")
n= len(num)

n0,n1,n2,n3,n4,n5,n6,n7,n8,n9 = 0,0,0,0,0,0,0,0,0,0

for i in range(n):
    if num[i] == '0':
        n0+=1
    elif num[i] == '1':
        n1+=1

    elif num[i] == '2':
        n2+=1

    elif num[i] == '3':
        
        n3+=1

    elif num[i] == '4':
        n4+=1

    elif num[i] == '5':
        n5+=1

    elif num[i] == '6':
        n6+=1

    elif num[i] == '7':
        n7+=1

    elif num[i] == '8':
        n8+=1

    elif num[i] == '9':
        n9+=1

print("The number %s has the following frequency of digits:" %num)
l=[n0,n1,n2,n3,n4,n5,n6,n7,n8,n9]
for i in range(10):
    if l==0:
        continue 
    else:
        print("The digit %d appears %d times" %(i,l[i]))


###########################################################################
count = [0]*10
print(count)
for i in range(10):
    for ii in range(n):
        if num[ii] == str(i):
            count[i]+=1

print("The number %s has the following frequency of digits:" %num)
for i in range(10):
    if count[i]==0:
        continue 
    else:
        print("The digit %d appears %d times" %(i,count[i]))


###########################################################################


d={}

for i in num:
    d[i]=d.get(i,0)+1

print("The number %s has the following frequency of digits:" %num)

for i in d:
    print("The digit %s appears %d times" %(i,d[i]))

###########################################################################






