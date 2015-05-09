//infix to postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char data;
	struct node* next;
};
int precedence(char a)
{
	if(a=='+')
		return 1;
	else if(a=='-')
		return 1;
	else if(a=='*')
		return 2;
	else if(a=='/')
		return 2;
	else if(a=='^')
		return 3;
	else if(a=='%')
		return 3;
	else
		return -1;
}
void push(struct node** start,char a)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a;
	temp->next=NULL;
	if((*start)==NULL)
	{
		(*start)=temp;
	}
	else
	{
		temp->next=(*start);
		(*start)=temp;
	}
}
char pop(struct node** start)
{
	if((*start)!=NULL)
	{
	char item=(*start)->data;
	struct node* temp=(*start);
	(*start)=(*start)->next;
	free(temp);
	return item;
	}
}
int main()
{
	char arr[1000];
	scanf("%s",arr);
	struct node* start=NULL;
	int i;
	int l=strlen(arr);
	for(i=0;i<l;i++)
	{
		if((arr[i]<=122 &&  arr[i]>=97)||(arr[i]>=65 && arr[i]<=90))
		{
			printf("%c",arr[i]);
		}
		else if(arr[i]=='(')
		{
			push(&start,'(');
		//printf("%c",start->data);
		}
		else if(arr[i]==')')
		{
			while(start->data!='(')
			{
				char item=pop(&start);
				printf("%c",item);
			}
			char v=pop(&start);
		}
		else
		{
			int p1;
			if(start==NULL)
				p1=-1;
			else
				p1=precedence(start->data);
			int p2=precedence(arr[i]);
//			printf("%d %d",p1,p2);
			if(p2>=p1)
			{
				push(&start,arr[i]);
			}
			else
			{
				//printf("%d %d",p1,p2);
				while(p2<p1)
				{
					if(start!=NULL)
					{
						char l=pop(&start);
						printf("%c",l);
					}
					p1=precedence(start->data);
				//	printf("jjj%djj",p1);
				}
				push(&start,arr[i]);
				//printf("uuu%cuuu",start->data);
			}
		}
	}

	while(start!=NULL)
	{
		char j=pop(&start);
		printf("%c",j);
	}
	return 0;
}

