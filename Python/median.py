# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys
def partition(a, l, r):
    p = a[r]
    i = l
    j = r
    while i <= j:
        while a[i] <= p:
            i = i+1
        while a[j] > p:
            j = j-1
        a[i],a[j] = a[j],a[i]
    a[i],a[j] = a[j],a[i]
    a[l],a[j] = a[j],a[l]
    return j

def quicksort(a, l, r):
    if l < r:
        s = partition(a, l, r)
        quicksort(a, l, s-1)
        quicksort(a, s+1, r)


line0 = 0
n_el = 0
a = []
for line in sys.stdin:
    if line0 == 0:
        line0 = 1
        n = line.split()
        n_el = n[0]
        continue
    else:
        a = line.split()

quicksort(a,0,len(a)-1)
print "sorted is ",a
print "median is ",a[len(a)/2]