def insertion_sort(arr):
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
        key = arr[i]
        print('key', key)
        j = i - 1
        print('j', j)

        # Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
            print("iteration: ", arr)
        arr[j + 1] = key
        print(arr)

# Example usage
arr = [64, 34, 25, 12, 22, 11, 90]
insertion_sort(arr)
