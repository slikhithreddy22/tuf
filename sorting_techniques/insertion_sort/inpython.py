arr = [5,2,4,6,1,3]
def insertion_sort_asc(arr):
    for i in range(1,len(arr)):
        key = arr[i]
        j = i-1
        while j>=0 and key<arr[j]:
            arr[j+1] = arr[j]
            j = j-1 
        arr[j+1] = key
    return arr
print("Insertion Sort Ascending order : ",insertion_sort_asc(arr))
def insertion_sort_desc(arr):
    for i in range(1,len(arr)):
        key = arr[i]
        j = i-1
        while j>=0 and key>arr[j]:
            arr[j+1] = arr[j]
            j = j-1 
        arr[j+1] = key
    return arr
print("Insertion Sort Descending order : ",insertion_sort_desc(arr))
