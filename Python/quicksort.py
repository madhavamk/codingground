def partition(a,l,r):
    p = a[l]
    i = l-1
    j = r+1
    while True:
        i+=1
        while a[i] < p:
            i+=1
        j-=1
        while a[j] > p:
            j-=1
        if i>=j:
            return j
        a[i],a[j] = a[j],a[i]

def quick_sort(a,l,r):
    if l < r:
        s = partition(a,l,r)
        quick_sort(a,l,s)
        quick_sort(a,s+1,r)

print("************Implementation of QuickSort***********")
a = [23,421,11,-11,423]
quick_sort(a, 0, len(a) - 1)
print(a)
