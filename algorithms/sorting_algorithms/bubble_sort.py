def bubble_sort(data):
    n = len(data)    
    # Passes : len - 1 (Traverse through all data elements)
    for i in range(n):
        # Compare adjusent unsorted elements in the pass
        for j in range(0, n-i-1):
            # Swap if the element found is grater than the next element
            if data[j] > data[j+1]:
                data[j] , data[j+1] = data[j+1], data[j]

data = [64, 34, 25, 12, 22, 11, 90]
bubble_sort(data)
print(data)
