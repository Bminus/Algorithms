//Huffman coding
#include<stdio.h>
#include<stdlib.h>
struct node
{
	char data;
	int frequency;
	struct node* left;
	struct node* right;
};
void root_to_leaf(struct node* root,int i,int flag,char k)
{
	static int array[1000];
	if(root==NULL && flag!=1)
	{
		printf("%c->",k);
		int j;
		for(j=0;j<i-1;j++)
		{
			printf("%d",array[j]);
		}
		printf("\n");
	}
	if(root!=NULL)
	{
	array[i]=0;
	flag=0;
	k=root->data;
	root_to_leaf(root->left,i+1,flag,k);
	array[i]=1;
	flag=1;
	k=root->data;
	root_to_leaf(root->right,i+1,flag,k);
	}
}

void enqueue(struct node** queue1,int* front,int* rear,struct node* p)
{
	if((*front)==-1 && (*rear)==-1)
	{
		(*front)++;
		(*rear)++;
		queue1[*front]=p;
	}
	else
	{
		(*rear)++;
		queue1[*rear]=p;
	}
}
struct node* dequeue(struct node** queue1,int* front,int* rear)
{
	if((*front)==(*rear))
	{
		struct node* temp=queue1[*front];
		(*front)=-1;
		(*rear)=-1;
		return temp;
	}
	if((*front)!=-1)
	{
	struct node* temp=queue1[*front];
	(*front)++;
	return temp;
	}
}
	

int main()
{
	int n;
	printf("Enter the number of characters\n");
	scanf("%d",&n);
	int i;
	struct node* queue1[n];
	struct node* queue2[n];
	int front1=-1;
	int front2=-1;
	int rear1=-1;
	int rear2=-1;
	for(i=0;i<n;i++)
	{
		char a;
		getchar();
		scanf("%c",&a);
		int f;
		scanf("%d",&f);
		struct node* temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=a;
		temp->frequency=f;
		temp->left=NULL;
		temp->right=NULL;
		enqueue(queue1,&front1,&rear1,temp);
	}
/*	for(i=0;i<n;i++)
	{
		struct node* temp=dequeue(queue1,&front1,&rear1);
		printf("%c %d\n",temp->data,temp->frequency);
	}*/
	int count1=rear1-front1+1;
	int count2=rear2-front2+1;
	struct node* temp1;
	struct node* temp2;
	while(count1+count2>=2)
	{
		if(front1==-1)
		{
			temp1=dequeue(queue2,&front2,&rear2);
		}
		else if(front2==-1)
		{
			temp1=dequeue(queue1,&front1,&rear1);
		}
		else
		{
			if(queue1[front1]->frequency<queue2[front2]->frequency)
			{
				temp1=dequeue(queue1,&front1,&rear1);
			}
			else
			{
				temp1=dequeue(queue2,&front2,&rear2);
			}
		}
		if((front1)==-1)
		{
			temp2=dequeue(queue2,&front2,&rear2);
		}
		else if((front2)==-1)
		{
			temp2=dequeue(queue1,&front1,&rear1);
		}
		else
		{
			if(queue1[front1]->frequency<queue2[front2]->frequency)
			{
				temp2=dequeue(queue1,&front1,&rear1);
			}
			else
			{
				temp2=dequeue(queue2,&front2,&rear2);
			}
		}
		//printf("%d %d",temp1->frequency,temp2->frequency);
		struct node* temp3=(struct node*)malloc(sizeof(struct node));
		temp3->frequency=temp1->frequency+temp2->frequency;
		temp3->left=temp1;
		temp3->right=temp2;
		enqueue(queue2,&front2,&rear2,temp3);
		if((front1)==-1)
			count1=0;
		else
		count1=rear1-front1+1;
		if(front2==-1)
			count2=0;
		else
		count2=rear2-front2+1;
//		printf("%d %dll",count1,count2);
	
	//printf("%d",temp3->frequency);
	}
	struct node* root=queue2[front2];
	//printf("%d",root->frequency);
	root_to_leaf(root,0,0,'a');

	return 0;
}


