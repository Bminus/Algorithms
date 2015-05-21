//hashing my chaining
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void insert(int a,struct node** start)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a;
	temp->next=(*start);
	(*start)=temp;
}

int main()
{
	//n is the table_size
	int n;
	int i;
	scanf("%d",&n);
	struct node* arr[n];
	for(i=0;i<n;i++)
	{
		arr[i]=NULL;
	}
	int num;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		int a;
		scanf("%d",&a);
		int j=a%n;
		insert(a,&arr[j]);
	}
	for(i=0;i<n;i++)
	{
		struct node* temp=arr[i];
		printf("%d---->",i);
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	int search;
	scanf("%d",&search);
	int k=search%n;
	int flag=0;
	struct node* tempi=arr[k];
	while(tempi!=NULL)
	{
		if(tempi->data==search)
		{
			printf("Found\n");
			flag=1;
			break;
		}
		tempi=tempi->next;
	}
	if(flag!=1)
		printf("Not found\n");

	return 0;
}


