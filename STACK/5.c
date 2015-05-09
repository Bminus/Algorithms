//next greater element
#include<stdio.h>
#include<limits.h>
void push(int a,int* front,int* stack)
{
	(*front)++;
	stack[*front]=a;
}
int pop(int* stack,int* front)
{
	int item=stack[*front];
	stack[*front]=0;
	(*front)--;
	return item;
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int stack[n];
	int front=-1;
	push(arr[0],&front,stack);
	for(i=1;i<n;i++)
	{
		int temp=arr[front];
		while(arr[i]>temp)
		{
			printf("%d--->%d\n",pop(stack,&front),arr[i]);
			if(front!=-1)
			temp=arr[front];
			else
				temp=INT_MAX;
		}
		push(arr[i],&front,stack);
	}
	while(front!=-1)
	{
		printf("%d---->%d\n",pop(stack,&front),-1);
	}
	return 0;
}

