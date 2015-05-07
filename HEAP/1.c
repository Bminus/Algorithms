//building a min heap
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
	return 0;
}

