ifile = open('sam.txt')
dict_words = { }
for line in ifile:''
    words = line.split( )
    for word in words:
        dict_words[word]= dict_words.get(word, 0)+1
list_words = [ ]
for key, val in dict_words.items( ): 
    list_words.append((val,key))
list_words.sort(reverse = True)
print('the slice of ten items of sorted dictionary are : ')
print(list_words[0:10])









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

























# Binary Search in python


def binarySearch(array, x, low, high):

    # Repeat until the pointers low and high meet each other
    while low <= high:

        mid = low + (high - low)//2

        if array[mid] == x:
            return mid

        elif array[mid] < x:
            low = mid + 1

        else:
            high = mid - 1

    return -1


array = [3, 4, 5, 6, 7, 8, 9]
x = 4

result = binarySearch(array, x, 0, len(array)-1)

if result != -1:
    print("Element is present at index " + str(result))
else:
    print("Not found")

















