def mergesort(a):
  if len(a) > 1:
    mid = len(a)/2
    left = a[:mid]
    right = a[mid:]
    mergesort(left)
    mergesort(right)
    merge(left,right,a)
    
def merge(left,right,a):
  i = 0
  j = 0
  k = 0
  while i < len(left) and j < len(right):
    if left[i] < right[j]:
      a[k] = left[i]
      i=i+1
    else:
      a[k] = right[j]
      j=j+1
    k=k+1
  while i < len(left):
    a[k] = left[i]
    i=i+1
    k=k+1
  while j < len(right):
    a[k] = right[j]
    j=j+1
    k=k+1

a = [15,21,1,6,394,123,596]
mergesort(a)
print a