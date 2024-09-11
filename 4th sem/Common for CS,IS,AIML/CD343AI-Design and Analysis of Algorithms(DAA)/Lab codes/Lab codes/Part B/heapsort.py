from time import perf_counter
A=[]
def heapify(r):
    for i in range(2,r+1):
        j=i
        temp=A[j]
        while j>1 and temp>A[j//2]:
            A[j]=A[j//2]
            j//=2
        A[j]=temp

def heapsort():
    for i in range(len(A)-1,1,-1):
        print(A)
        A[1],A[i]=A[i],A[1]
        heapify(i-1)
    
A=[0]
A1=[int(i) for i in input('Enter an array\n').split(' ')]
A=A+A1
start=perf_counter()
heapify(len(A)-1)
heapsort()
end=perf_counter()
diff=end-start
print("The sorted array is ")
for i in A[1:]:
    print(i,end=' ')
print("\nThe time taken is ",diff)

