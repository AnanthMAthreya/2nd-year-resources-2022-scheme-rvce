#include <stdio.h>
// #include <math.h>
int main()
{
    int n, g[100][100], i, j, s, visited[100], count, next;
    int distance[100];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjaceny matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
            if (g[i][j] == 0)
            {
                g[i][j] = 999;
            }
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &s);

    for (i = 0; i < n; i++)
    {
        distance[i] = g[s][i];

        visited[i] = 0;
    }
    distance[s] = 0;
    visited[s] = 1;
    count = 1;
    while (count < n - 1)
    {
        int mindistance = 999;
        for (i = 0; i < n; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                next = i;
            }
        }
        visited[next] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if ((mindistance + g[next][i]) < distance[i])
                {
                    distance[i] = mindistance + g[next][i];
                }
            }
        }
        count++;
    }
    for (i = 0; i < n; i++)
    {
        if (i != s)
        {
            printf("\nDistance of %d from %d = %d\n", i, s, distance[i]);
        }
    }
    return 0;
}
