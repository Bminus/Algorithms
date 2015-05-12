#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
	int data;
	int l;
	struct node* left;
	struct node* right;
	struct node* par;
};
void preorder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d %d\n",root->data,root->l);
		inorder(root->right);
	}
}

void insert(struct node** root,int a,struct node* parent)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a;
	temp->left=NULL;
	temp->right=NULL;
	temp->par=parent;
	temp->l=0;
	if((*root)==NULL)
	{
		(*root)=temp;
		return;
	}
	else
	{
		if((*root)->data<a)
		{
			insert(&((*root)->right),a,(*root));
		}
		else
		{
			(*root)->l++;
			insert(&((*root)->left),a,(*root));
		}
	}
}

int floort(struct node* root,int a)
{
	//greatest interger less than a
	if(root==NULL)
	{
		return INT_MAX;
	}
	if(root->data==a)
		return root->data;
	else if(root->data>a)
	{
		floort(root->left,a);
	}
	else
	{
		int k1=floort(root->right,a);
		if(k1<=a)
			return k1;
		else
			return root->data;
	}
}



int main()
{
	int n;
	scanf("%d",&n);
	int i;
	struct node* root=NULL;
	for(i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		insert(&root,a,NULL);
	}
	int m;
	scanf("%d",&m);
	int k=floort(root,m);
	printf("%d",k);
	return 0;
}
