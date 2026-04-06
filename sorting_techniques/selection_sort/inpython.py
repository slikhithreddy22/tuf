def insertion_sort(arr):
    for i in range(len(arr)):
        mini = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[mini]:
                mini = arr[j]
