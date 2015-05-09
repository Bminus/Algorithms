//min stack
#include<stdio.h>
void push(int* stack1,int* stack2,int* front1,int* front2,int a)
{
	(*front1)++;
	stack1[*front1]=a;
	int temp=(*front2);
	if(a<stack2[*front2])
	{
		(*front2)++;
		stack2[*front2]=a;
	}
	else
	{
		(*front2)++;
		stack2[*front2]=stack2[temp];
	}
}
int pop(int* stack1,int* stack2,int* front1,int* front2)
{
	int item=stack1[*front1];
	stack1[*front1]=-1;
	stack2[*front2]=-1;
	(*front1)--;
	(*front2)--;
	return item;
}
int main()
{
	int n;
	scanf("%d",&n);
	int stack1[n];
	int stack2[n];
	int front1=0;
	int front2=0;
	int i;
	int b;
	scanf("%d",&b);
	stack1[front1]=b;
	stack2[front2]=b;
	for(i=1;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		push(stack1,stack2,&front1,&front2,a);
	}
	while(n--)
	{
		int k=pop(stack1,stack2,&front1,&front2);
		printf("%d %d\n",k,stack2[front2]);
	}
	return 0;
}

