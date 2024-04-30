#include<stdio.h>
#include<conio.h>
int a[20][20],reach[20],n;

void dfs(int v) {
	int i;
	reach[v]=1;
	printf("Node visited = %d\n",v);
	for (i=1;i<=n;i++)
	  if(a[v][i] && !reach[i]) {
		//printf("\n %d->%d",v,i);
		dfs(i);
	}
}
void main() {
	int i,j,source;

	printf("\n Enter number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		reach[i]=0;
		for (j=1;j<=n;j++)
		   a[i][j]=0;
	}
	printf("\n Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
    printf("Enter the source vertex\n");
    scanf("%d",&source);
	dfs(source);
	printf("\n");
}
