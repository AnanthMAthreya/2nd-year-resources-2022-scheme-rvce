def get():
    global n, a, visited
    n = int(input("Enter No. of Cities: "))

    a = []
    visited = [0] * n

    print("\nEnter Cost Matrix:")
    for i in range(n):
        row = [int(i) for i in input().split(' ')]
        a.append(row)
        visited[i] = 0

    print("\n\nThe cost list is:\n")
    for row in a:
        print("\t".join(map(str, row)))


def mincost(city):
    global cost
    visited[city] = 1
    print(f"{city + 1} ->", end=" ")

    ncity = least(city)

    if ncity == 999:
        ncity = 0
        print(f"{ncity + 1}")
        cost += a[city][ncity]
        return

    mincost(ncity)


def least(c):
    global cost
    min_value = 999
    nc = 999
    kmin = 0

    for i in range(n):
        if a[c][i] != 0 and visited[i] == 0:
            if a[c][i] + a[i][0] < min_value:
                min_value = a[c][i] + a[i][0]
                kmin = a[c][i]
                nc = i

    if min_value != 999:
        cost += kmin

    return nc


def put():
    print("\n\nMinimum cost:", cost)

global cost
cost = 0
get()

print("\n\nThe Path is:\n")
mincost(0)

put()


