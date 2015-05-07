//find the kth largest element in the array
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
void heapify(int* heap,int k,int a)
{
	heap[1]=a;
	int h=1;
	while(h<=k/2 && (heap[h]>heap[2*h] || heap[h]>heap[2*h+1]))
	{
		if((2*h+1>k) || heap[2*h]<heap[2*h+1])
		{
			//printf("red");
			int temp=heap[h];
			heap[h]=heap[2*h];
			heap[2*h]=temp;
			//printf("k%dk",heap[2*h]);
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
}

int main()
{
	int n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int i;
	int heap[n+1];
	int j=0;
	int k;
	printf("Enter k to find the kth largest element in the array\n");
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		int a;
		scanf("%d",&a);
		insert(heap,&j,a);
	}
//	for(i=0;i<k;i++)
//	{
//		printf("%d ",heap[i]);
//	}
	for(i=k;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a>heap[1])
		{
			heapify(heap,k,a);
		}
	}
	/*	for(i=1;i<=k;i++)
		{
			printf("%d ",heap[i]);
		}*/
	printf("%d ",heap[1]);
	return 0;
}

