#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
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
void inorder(struct node* root,int a,int b)
{
	if(root!=NULL)
	{
		if(root->data>=a)
		inorder(root->left,a,b);
		if(root->data<=b && a<=root->data)
			printf("%d ",root->data);
		if(root->data<=b)
		inorder(root->right,a,b);
	}
}
void searchi(struct node* root,int search)
{
	if(root!=NULL)
	{
	if(root->data==search)
	{
		printf("Element fOUND\n");
		if(root->left!=NULL && root->right!=NULL)
		{
			struct node* temp=root->right;
			while(temp->left!=NULL)
			{
				temp=temp->left;
			}
			int swap=root->data;
			root->data=temp->data;
			temp->data=swap;
			root=temp;
		}
		if(root->left==NULL && root->right==NULL)
		{
			if(root->par->left==root)
			{
				root->par->left=NULL;
			}
			else
				root->par->right=NULL;
		}
		else if(root->left!=NULL && root->right==NULL)
		{
			if(root->par->left==root)
			{
				root->par->left=root->left;
			}
			else
				root->par->right=root->left;
		}
		else if(root->left==NULL && root->right!=NULL)
		{
			if(root->par->left==root)
			{
				root->par->left=root->right;
			}
			else
				root->par->right=root->right;
		}
		

	}
	else if(root->data<search)
	{
		searchi(root->right,search);
	}
	else
		searchi(root->left,search);
	}
}
void insert(struct node** root,int a,struct node* parent)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a;
	temp->left=NULL;
	temp->right=NULL;
	temp->par=parent;
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
			insert(&((*root)->left),a,(*root));
		}
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
/*	inorder(root,a,b);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");*/
	int c,b;
	scanf("%d %d",&c,&b);
//	searchi(root,search);
	//printf("%d",root->right->left->data);
	inorder(root,c,b);
	printf("\n");
/*	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");*/
	return 0;
}
