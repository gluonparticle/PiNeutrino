n=int(input("enter the number of elements:"))
l=[]

for i in range(n):
    x=float(input("enter value"))
    l.append(x)

print(l)

x=float(input("enter the element to be found"))

def linearsearch(l,n,x):
    
    for i in range(n):
        if(l[i]==x):
            return i
    return -1
r=linearsearch(l,n,x)
print(r)
