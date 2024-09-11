def prims(n, cost,s):
    mincost = 0
    visited = [0] * n
    ne = 1
    visited[s] = 1

    print("\nThe edges considered for MST are:")

    while ne < n:
        minv = 999
        u = -1
        v = -1

        for i in range(n):
            for j in range(n):
                if cost[i][j] < minv:
                    if visited[i] == 0:
                        continue
                    else:
                        minv = cost[i][j]
                        u = i
                        v = j

        if visited[u] == 0 or visited[v] == 0:
            print(ne,'. Edge (',u,',',v,') = ',minv)
            ne += 1
            mincost += minv
            visited[v] = 1

        cost[u][v] = cost[v][u] = 999

    print("Cost of constructing MST is ",mincost)

n=int(input('Enter the number of nodes\n'))
cost=[]
print('Enter the array')
for i in range(n):
    temp=[int(i) for i in input().split(' ')]
    cost.append(temp)

for i in range(n):
    for j in range(n):
        if cost[i][j]==0:
            cost[i][j]=999
s=int(input('Enter the source vertex\n'))
prims(n,cost,s)



        

