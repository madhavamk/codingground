def selection_sort(a):
    n = len(a)
    for i in range(n - 1):
        small = i
        for j in range(i+1, n):
            if a[j] < a[small]:
                small = j
        a[small],a[i] = a[i],a[small]

print("************Implementation of SelectionSort***********")
a = [23,421,11,-11,423]
selection_sort(a)
print(a)
