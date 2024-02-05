def bubble_sort(a):
    n = len(a)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if a[j] > a[j + 1]:
                a[j],a[j+1] = a[j+1],a[j]

print("************Implementation of BubbleSort***********")
a = [23,421,11,-11,423]
bubble_sort(a)
print(a)
