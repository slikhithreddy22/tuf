def separator(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = separator(arr[:mid])
    right = separator(arr[mid:])
    return merge_asc(left, right)


def merge_asc(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend((right[j:]))

    return result


print(separator([5, 2, 4, 6, 1, 3]))
