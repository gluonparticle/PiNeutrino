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
 
# Test array
arr = [ 2, 3, 4, 10, 40 ]
x = 10
 
# Function call
result = binary_search(arr, x, 0,len(arr)-1)
 
if result != -1:
    print("Element is present at index", str(result))
else:
    print("Element is not present in array")
