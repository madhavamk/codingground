def insertion_sort(a):
    n = len(a)
    for i in range(1, n - 1):
        element = a[i]
        j = i - 1
        while j >= 0 and element < a[j]:
            a[j+1] = a[j]
            j-=1
        a[j+1] = element

print("************Implementation of InsertionSort***********")
a = [23,421,11,-11,423]
insertion_sort(a)
print(a)
