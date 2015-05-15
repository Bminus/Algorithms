#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
void merge(struct node** root,struct node* first,struct node* mid,struct node* last)
{
	struct node* i=first;
	struct node* j=mid->next;
	struct node* output=(struct node*)malloc(sizeof(struct node));
	struct node* t=output;
	while(i!=mid->next && j!=last->next)
	{
		if(i->data<=j->data)
		{
			output->data=i->data;
			output->next=(struct node*)malloc(sizeof(struct node));
			i=i->next;
			output=output->next;
		}
		else
		{
			output->data=j->data;
			j=j->next;
			output->next=(struct node*)malloc(sizeof(struct node));
			output=output->next;
		}
	}
//	while(t!=NULL)
//	{
//		printf("%d ",t->data);
//		t=t->next;
//	}
	while(i!=mid->next)
	{
		output->data=i->data;
		output->next=(struct node*)malloc(sizeof(struct node));
		i=i->next;
		output=output->next;
	}
	while(j!=last->next)
	{
		output->data=j->data;
		output->next=(struct node*)malloc(sizeof(struct node));
		j=j->next;
		output=output->next;
	}
/*	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}*/

	//struct node* st=first;
	while(first!=last->next)
	{
		first->data=t->data;
		first=first->next;
		t=t->next;
	}
}




void mergesort(struct node** root,struct node* first,struct node* last)
{
	int count=0;
	struct node* temp1=first;
	struct node* temp2=last;
//	printf("%d %d",first->data,last->data);
	while(temp1!=temp2)
	{
		count++;
		temp1=temp1->next;
	}
	count++;
//	printf("%d",count);
	if(count>1)
	{
		struct node* mid=first;
		int m;
		if(count%2==1)
		m=count/2;
		else
		m=count/2-1;
		while(m--)
		{
			mid=mid->next;
		}
//		printf("%d ",mid->data);
//		printf("j");
		mergesort(root,first,mid);
		mergesort(root,mid->next,last);
		merge(root,first,mid,last);
	}
}

void insert(struct node** root,int a)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a;
	temp->next=NULL;
	if((*root)==NULL)
	{
		(*root)=temp;
	}
	else
	{
		insert(&((*root)->next),a);
	}
}
void print(struct node* start)
{
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->next;
	}
	printf("\n");
}
int main()
{
	int n;
	scanf("%d",&n);
	struct node* start=NULL;
	int i;
	for(i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		insert(&start,a);
	}
	//print(start);
	struct node* last=start;
	struct node* first=start;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	struct node* y=first;

	mergesort(&start,first,last);
	print(y);
	return 0;
}


