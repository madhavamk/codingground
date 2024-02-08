def partition(a,l,r):
    p = a[l]
    i = l
    j = r
    while i <= j:
        while a[i] <= p:
            i+=1
        while a[j] > p:
            j-=1
        a[i],a[j] = a[j],a[i]
    a[i],a[j] = a[j],a[i]
    a[l],a[j] = a[j],a[l]
    return j

def quick_sort(a,l,r):
    if l < r:
        s = partition(a,l,r)
        quick_sort(a,l,s-1)
        quick_sort(a,s+1,r)

print("************Implementation of QuickSort***********")
a = [23,421,11,-11,423]
quick_sort(a, 0, len(a) - 1)
print(a)
