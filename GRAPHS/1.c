//prims algorithm
#include<stdio.h>
#include<limits.h>
struct node
{
	int data;
	int key;
};
int deletemin(struct node* heap,int* m)
{
	int item=heap[1].data;
	heap[1].data=heap[*m].data;
	heap[1].key=heap[*m].key;
	(*m)--;
	int h=1;
	while( h<=(*m)/2 && ((heap[h].key>heap[2*h].key) || (heap[h].key>heap[2*h+1].key)))
	{
		if(heap[2*h].key>heap[2*h+1].key && (2*h+1<=(*m)))
		{
			int temp1=heap[h].key;
			int temp2=heap[h].data;
			heap[h].key=heap[2*h+1].key;
			heap[h].data=heap[2*h+1].data;
			heap[2*h+1].key=temp1;
			heap[2*h+1].data=temp2;
			h=2*h;
		}
		else
		{
			int temp1=heap[h].key;
			int temp2=heap[h].data;
			heap[h].key=heap[2*h].key;
			heap[h].data=heap[2*h].data;
			heap[2*h].key=temp1;
			heap[2*h].data=temp2;
			h=2*h;
			
			
		}
	}
	return item;
}

void insert(struct node* heap,int* m,int i,int ke)
{
	(*m)++;
	heap[*m].data=i;
	heap[*m].key=ke;
	int h=(*m);
	while(heap[h].key<heap[h/2].key && h!=1 )
	{
		int temp1=heap[h].data;
		int temp2=heap[h].key;
		heap[h].data=heap[h/2].data;
		heap[h].key=heap[h/2].key;
		heap[h/2].data=temp1;
		heap[h/2].key=temp2;
		h=h/2;
	}
}
void decrese_key(struct node* heap,int new,int j)
{
	int h=j;
	//printf("%d",j);
	heap[h].key=new;
	while(heap[h].key<heap[h/2].key && h!=1)
	{
	//	printf("kanika");
		int temp1=heap[h].data;
		int temp2=heap[h].key;
		heap[h].data=heap[h/2].data;
		heap[h].key=heap[h/2].key;
		heap[h/2].data=temp1;
		heap[h/2].key=temp2;
		h=h/2;
	}
}

int main()
{
	int n;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	int graph[n][n];
	int matrix[n][n];
	int parent[n];
	int i,j;
	int l;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
			matrix[i][j]=0;
		}
	}
	int flag[n];
	int dis[n];
	for(i=0;i<n;i++)
	{
		flag[i]=0;
		dis[i]=INT_MAX;
		parent[i]=0;
	}
	dis[0]=0;
	struct node heap[n];
	int m=0;
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			insert(heap,&m,i,0);
		}
		else
		{
			insert(heap,&m,i,INT_MAX);
		}

	}
	int mn=n;
	for(l=1;l<=n;l++)
	{
		int d=deletemin(heap,&mn);
//		printf("%d",d);
//		for(j=0;j<=mn;j++)
//			printf("jj%d ",heap[j].data);
		flag[d]=1;
//		printf("%d",d);
		for(i=0;i<n;i++)
		{
			if(graph[d][i]!=0 && flag[i]!=1)
			{
				//printf("%d",i);
				if(dis[i]>graph[d][i])
				{
					dis[i]=graph[d][i];
					parent[i]=d;
					for(j=0;j<=mn;j++)
					{
						if(heap[j].data==i)
						   decrese_key(heap,dis[i],j);
					}
				}
			}
		}
	}
/*		for(i=1;i<=mn;i++)
			printf("%d ",heap[i].data);
		printf("\n");
		for(i=1;i<=mn;i++)
			printf("%d ",heap[i].key);*/
		for(i=0;i<n;i++)
			printf("%d ",dis[i]);
		printf("\n");
		for(i=0;i<n;i++)
		{
			//printf("%d ",parent[i]);
			matrix[i][parent[i]]=dis[i];
			matrix[parent[i]][i]=dis[i];
		}
		//printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

				


/*	int mn=n-1;
	for(i=0;i<n;i++)
	{
		int d=deletemin(heap,&mn);
		printf("%d ",d);
	}*/
	return 0;
}
