def merge(left, right, a):
    m = len(left)
    n = len(right)
    o = len(a)
    i = 0
    j = 0
    k = 0
    while i < m and j < n:
        if left[i] <= right[j]:
            a[k] = left[i]
            i+=1
        else:
            a[k] = right[j]
            j+=1
        k+=1
    while i < m:
        a[k] = left[i]
        i+=1
        k+=1
    while j < n:
        a[k] = right[j]
        j+=1
        k+=1

def merge_sort(a):
    if len(a) > 1:
        mid = len(a)//2
        left = a[:mid]
        right = a[mid:]
        merge_sort(left)
        merge_sort(right)
        merge(left,right,a)

print("************Implementation of MergeSort***********")
a = [23,421,11,-11,423]
merge_sort(a)
print(a)
