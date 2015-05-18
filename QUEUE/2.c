#include<stdio.h>
void enqueue(int* queue,int* front,int* rear,int a)
{
	if((*front)==-1 && (*rear)==-1)
	{
		//queue[*front]=a;
		(*front)++;
		(*rear)++;
		queue[*front]=a;
	}
	else if((((*rear)+1)%5)==(*front))
	{
		printf("Stack overflow\n");
	}
	else
	{
		(*rear)++;
		queue[*rear]=a;
	}
}
int dequeue(int* queue,int* front,int* rear)
{
	int item=queue[*front];
	queue[*front]=0;
	if((*front)==-1)
	{
		printf("Underflow\n");
	}
	else if((*front)==(*rear))
	{
		(*front)=-1;
		(*rear)=-1;
	}
	else
	{
	//int item=queue[*front];
	(*front)++;
	}
	return item;
}

int main()
{
	int n;
	scanf("%d",&n);
	int queue[n];
	int front=-1;
	int rear=-1;
	int i;
	for(i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		enqueue(queue,&front,&rear,a);
	}
//	enqueue(queue,&front,&rear,12);
/*	for(i=front;i<=rear;i++)
	{
		printf("%d ",queue[i]);
	}*/
	int k=dequeue(queue,&front,&rear);
	enqueue(queue,&front,&rear,1000);
/*	for(i=front;i<=rear;i++)
	{
		printf("%d ",queue[i]);
	}*/
	for(i=0;i<n;i++)
	{
		int item=dequeue(queue,&front,&rear);
		printf("%d ",item);
	}
	return 0;
}
