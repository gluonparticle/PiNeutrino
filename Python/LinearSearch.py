def linearsearch(l,x):
    n=len(l)
    for i in range(n):
        if l[i]==x:
            return i
    return -1
    
    
    
    
n=int(input("enter the number of elements:"))
l=[]

for i in range(n):
    x=float(input("enter value"))
    l.append(x)
print(l)
x=float(input("enter the element to be found"))


    
r=linearsearch(l,x)
print(r)
