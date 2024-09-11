from time import time
def quicksort(A, l, r):
    if l < r:
        s = partition(A, l, r)
        quicksort(A, l, s - 1)
        quicksort(A, s + 1, r)

def partition(A, l, r):
    pivot = A[l]
    i = l + 1
    j = r
    
    while True:
        while i <= r and A[i] <= pivot:
            i += 1
            if i > r:
                break
        while j >= l and A[j] > pivot:
            j -= 1
            if j < l:
                break
        if i < j:
            A[i], A[j] = A[j], A[i]
        else:
            break
    A[l], A[j] = A[j], A[l]
    return j

A = [int(i) for i in input('Enter the array\n').split()]
start=time()
quicksort(A, 0, len(A) - 1)
end=time()
diff=end-start
print("The sorted array is",A)
print("The time taken is ",diff)

