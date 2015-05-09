//evaluation of postfix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	(*stack)->next=NULL;
	free(temp);
	return re;
}

int main()
{
	struct node* stack=(struct node*)malloc(sizeof(struct node));
	stack->data=-1;
        stack->next=NULL;
	struct node* start=stack;
	char string[1000];
	scanf("%s",string);
	int n=strlen(string);
	int i;
	int result;
	for(i=0;i<n;i++)
	{
		char a=string[i];
		if(a=='1' || a=='2' || a=='3' || a=='4' || a=='5' || a=='6' || a=='7' || a=='8' || a=='9' || a=='0')
		{
		stack->next=(struct node*)malloc(sizeof(struct node));
		stack->next->prev=stack;
		stack=push(stack->next,a);
		}
		else
		{
			char x=pop(&stack);
			char y=pop(&stack);
			if(a=='+') 
			{
				result=(x-'0')+(y-'0');
		//		printf("%d ",result);
			}
			else if(a=='-')
			{
				result=(y-'0')-(x-'0');
		//		printf("%d ",result);
			}
			else if(a=='*')
			{
				result=(x-'0')*(y-'0');
		//		printf("%d ",result);
			}
			else if(a=='/')
			{
				result=(y-'0')/(x-'0');
		//		printf("%d ",result);
			}
			  stack->next=(struct node*)malloc(sizeof(struct node));
			  stack->next->prev=stack;
			  stack=push(stack->next,result+'0');
		}


	}
	char yt=stack->data;
	int ut=yt-'0';
	printf("%d",ut);
/*	print(start);
//	printf("%d",start->next->prev->data);
	while(m--)
	{
		int re=pop(&stack);
		printf("%d ",re);
	}*/
	
	return 0;
}

