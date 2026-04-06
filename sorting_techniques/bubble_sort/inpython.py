def bubble_sort_asc(arr):
    for i in range(len(arr)):
        for j in range(0, len(arr) - i - 1):
            if arr[j + 1] < arr[j]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    print(arr)


def bubble_sort_dsc(arr):
    for i in range(len(arr)):
        for j in range(0, len(arr) - i - 1):
            if arr[j + 1] > arr[j]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    print(arr)


bubble_sort_asc([5, 2, 4, 6, 1, 3])
bubble_sort_dsc([5, 2, 4, 6, 1, 3])
