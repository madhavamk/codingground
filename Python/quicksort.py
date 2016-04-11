def quicksort(a, l, r):
    if l < r:
        s = partition(a, l, r)
        quicksort(a, l, s-1)
        quicksort(a, s+1, r)

def partition(a, l, r):
    p = a[l]
    i = l
    j = r+1
    while i <= j:
        while a[i] <= p:
            i = i+1
        while a[j] > p:
            j = j-1
        a[i],a[j] = a[j],a[i]
    a[i],a[j] = a[j],a[i]
    a[l],a[j] = a[j],a[l]
    return j

a = [54,32,56,12,88,304,992]
quicksort(a,0,a[-1])
print a