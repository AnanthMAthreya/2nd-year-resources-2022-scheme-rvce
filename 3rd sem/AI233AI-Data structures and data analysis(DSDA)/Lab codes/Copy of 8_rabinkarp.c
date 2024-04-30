#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char line[100], pat[100];
int n, m;
float hasher(char a[])
{
    int i;
    float val = 1000;

    for (i = 0; i < n; i++)
    {
        val = val / a[i];
        printf("%f\t", val);
    }
    return val;
}
int main()
{
    char new[100];
    printf("enter the line:");
    scanf("%s", line);
    printf("enter the pattern:");
    scanf("%s", pat);
    m = strlen(line);
    n = strlen(pat);
    int i, j;
    for (i = 0; i < m; i++)
    {
        if (line[i] == pat[0])
        {
            for (j = 0; j < n; j++)
            {
                new[j] = line[i + j];
            }
            if (hasher(pat) == hasher(new))
            {
                printf("position is at %d\n", i);
            }
        }
    }
    return 0;
}
