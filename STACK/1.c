//stack
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
void print(struct node* start)
{
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->next;
	}
}
struct node* push(struct node* stack,int a)
{
	stack->data=a;
	stack->next=NULL;
        return stack;
}
	
int pop(struct node** stack)
{
	struct node* temp=(*stack);
	int re=(*stack)->data;
	(*stack)=(*stack)->prev;
	free(temp);
	return re;
}

int main()
{
	struct node* stack=(struct node*)malloc(sizeof(struct node));
	stack->data=-1;
        stack->next=NULL;
	struct node* start=stack;
	int n;
	scanf("%d",&n);
	int m=n;
	while(n--)
	{
		int a;
		scanf("%d",&a);
		stack->next=(struct node*)malloc(sizeof(struct node));
		stack->next->prev=stack;
		stack=push(stack->next,a);



	}
	print(start);
//	printf("%d",start->next->prev->data);
	while(m--)
	{
		int re=pop(&stack);
		printf("%d ",re);
	}
	
	return 0;
}

