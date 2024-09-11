import random
from time import time

adjmat=list()
res=list()
visited=list()
n=None
def toposearch():
    res.append(0)
    for i in range(n):
        if visited[i]==0:
            dfs(i)
            
def dfs(s):
    
    visited[s]=1
    for i in range(n):
        if adjmat[s][i]==1 and visited[i]==0:
            dfs(i)
    res.append(s)
    
n=int(input("Enter the number of vertices\n"))
for i in range(n):
    temp=[0]*n
    adjmat.append(temp)
    
for i in range(1,n):
    for j in range(0,i):
        adjmat[i][j]=random.randint(0,1)
        
for i in adjmat:
    for j in i:
        print(j,end=' ')
    print('\n')

visited=[0]*n

start=time()
toposearch()
end=time()
diff=end-start
print("The result is \n")
for i in range(n,0,-1):
    print(res[i],end=' ')
    
print('\n')

print("The time taken is ",diff)
        

