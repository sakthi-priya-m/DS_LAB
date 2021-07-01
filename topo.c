#include<stdio.h>

int main()
{
	int n,i,j,k,a[10][10],deg[10],flag[10];
	int c=0;
	
	printf("Enter the number of vertices in the given graph: ");
	scanf("%d",&n);
	
	printf("Enter the adjacency matrix of the graph: ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	for(i=0;i<n;i++)
	{
		deg[i]=0;
		flag[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			deg[i]=deg[i]+a[j][i];
		}
	}
	printf("\n The topological order of vertices in the given graph is : \n");
	
	while(c<n)
	{
		for(k=0;k<n;k++)
		{
			if((deg[k]==0) && (flag[k]==0))
			{
				printf(" %d\t",(k+1));
				flag[k]=1;
			}
		for(i=0;i<n;i++)
		{
			if(a[i][k]==1)
				deg[k]--;
		}
		}
		c++;
	}
	return 0;
}
	
				
