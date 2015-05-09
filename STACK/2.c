//balancing of paranthesis
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag=1;
struct node
{
	char data;
	struct node* next;
	struct node* prev;
};
void print(struct node* start)
{
	while(start!=NULL)
	{
		printf("%c ",start->data);
		start=start->next;
	}
}
struct node* push(struct node* stack,int a)
{
	stack->data=a;
	stack->next=NULL;
        return stack;
}
	
char pop(struct node** stack)
{
	struct node* temp=(*stack);
	char re=(*stack)->data;
	(*stack)=(*stack)->prev;
	(*stack)->next=NULL;
	free(temp);
	return re;
}
int count(struct node* start)
{
	int c=0;
	while(start!=NULL)
	{
		c++;
		start=start->next;
	}
	return c;
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
	int m=n;
	int i;
	for(i=0;i<n;i++)
	{
		char a;
		a=string[i];
		if(a=='(' || a=='[' || a=='{')
		{
		stack->next=(struct node*)malloc(sizeof(struct node));
		stack->next->prev=stack;
		stack=push(stack->next,a);
		}
		else if(a==')' || a==']' || a=='}')
		{
			char re=pop(&stack);
//			printf("%c  %c ",a,re);
			if(a==')' && re!='(')
			{
				flag=0;
//				printf("jj");
				break;
			}
			else if(a==']' && re!='[')
			{
				flag=0;
				break;
			}
			else if(a=='}' && re!='{')
			{
				flag=0;
			//	printf("oo");
			//	printf("lll%c %clll",a,re);
				break;
			}
		}

	}
//	print(start);
	int c=count(start);
	printf("%d ",c);
	if(c>1)
		flag=0;
	if(flag==0)
		printf("Expression is not balanced\n");
	else 
		printf("Expression is balanced\n");
//	print(start);
//	printf("%d",start->next->prev->data);
/*	while(m--)
	{
		int re=pop(&stack);
		printf("%d ",re);
	}*/
	
	return 0;
}

