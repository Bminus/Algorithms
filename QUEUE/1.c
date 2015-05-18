#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
int dequeue(struct node** front,struct node** rear)
{
	int item=(*front)->data;
	if((*front)==NULL)
	{
		printf("already empty");
	}
	else if((*front)==(*rear))
	{
		(*front)=NULL;
		(*rear)=NULL;
	}
	else
	{
		(*front)=(*front)->next;
	}
	return item;
}

	
void enqueue(struct node** front,struct node** rear,int a)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a;
	temp->next=NULL;
	if((*front)==NULL && (*rear)==NULL)
	{
		(*front)=temp;
		(*rear)=temp;
	}
	else
	{
		(*rear)->next=temp;
		(*rear)=(*rear)->next;
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	int i;
	struct node* front=NULL;
	struct node* rear=NULL;
	for(i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		enqueue(&front,&rear,a);
	}
	/*while(front!=rear->next)
	{
		printf("%d ",front->data);
		front=front->next;
	}*/
	for(i=0;i<n;i++)
	{
		int item=dequeue(&front,&rear);
		printf("%d ",item);
	}
/*	while(front!=rear->next)
	{
		printf("%d ",front->data);
		front=front->next;
	}*/
	return 0;
}
