//heapsort
#include<stdio.h>
void insert(int* heap,int* j,int a)
{
	(*j)++;
	if((*j)==1)
	{
		heap[*j]=a;
		return;
	}
	else
	{
		heap[*j]=a;
		int h=(*j);
		while(h!=1 && heap[h/2]>heap[h])
		{
			int temp;
			temp=heap[h];
			heap[h]=heap[h/2];
			heap[h/2]=temp;
			h=h/2;
		}
	}
}
int delete_min(int* heap,int* m)
{
	int item=heap[1];
	heap[1]=heap[*m];
	(*m)--;
	int h=1;
	while( h<=(*m)/2 && ((heap[h]>heap[2*h]) || (heap[h]>heap[2*h+1])))
	{
		if(heap[2*h]<heap[2*h+1])
		{
			int temp=heap[h];
			heap[h]=heap[2*h];
			heap[2*h]=temp;
			h=2*h;
		}
		else
		{
			int temp=heap[h];
			heap[h]=heap[2*h+1];
			heap[2*h+1]=temp;
			h=2*h+1;
		}
	}
	return item;
}


int main()
{
	int n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int i;
	int heap[n+1];
	int j=0;
	for(i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		insert(heap,&j,a);
	}
	for(i=1;i<=n;i++)
	{
		printf("%d ",heap[i]);
	}
	printf("\n");
	int m=n;
	for(i=1;i<=n;i++)
	{
		int k=delete_min(heap,&m);
		printf("%d ",k);
	}
	return 0;
}

