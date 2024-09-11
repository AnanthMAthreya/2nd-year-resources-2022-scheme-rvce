def floyds(D):
    n=len(D)
    for i in range(n):
        for j in range(n):
            for k in range(n):
                D[i][j]=min(D[i][j],D[i][k]+D[k][j])
    return D

D=[]
print("Enter the adjacency matrix\n")
while True:
    temp=[int(i) for i in input().split()]
    D.append(temp)
    s=int(input("Press 1 to continue, else 0\n"))
    if s==0:
        break

n=len(D)
for i in range(n):
    for j in range(n):
        if D[i][j]==0 and i!=j:
            D[i][j]=999
D1=floyds(D)
print("The all pair shortest path is")
for i in D1:
    for j in i:
        print(j,end=" ")
    print(end="\n")

    

