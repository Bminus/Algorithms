#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* partition(struct node* first,struct node* last)
{
	int pivot=first->data;
	struct node* t=first;
	struct node* ti=first;
	int i;
	first=first->next;
	struct node* index=first;
	while(first!=last->next)
	{
		if(first->data<pivot)
		{
			int temp=first->data;
			first->data=index->data;
			index->data=temp;
			index=index->next;
		}
		first=first->next;
	}
	while(t->next->next!=index)
	{
		t=t->next;
	}
	ti->data=t->next->data;
	t->next->data=pivot;
	return t;
}


void quicksort(struct node* first,struct node* last)
{
	if(first!=NULL && last!=NULL)
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
	printf("%d ",count);
	if(count>1)
	{
		struct node* p=partition(first,last);
	//	quicksort(first,p);
	//	quicksort(p->next->next,last);
	}
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
void insert(struct node** start,int a)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a;
	if((*start)==NULL)
	{
		(*start)=temp;
	}
	else
	{
		insert(&((*start)->next),a);
	}
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
	struct node* first=start;
	struct node* tem=first;
	while(start->next!=NULL)
	{
		start=start->next;
	}
	struct node* last=start;
//	printf("%d %d",first->data,last->data);
	quicksort(first,last);
//	print(first);
	return 0;
}

