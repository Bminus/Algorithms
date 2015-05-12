#include<stdio.h>
#include<stdlib.h>
int arr[1000];
int k=0;
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
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		arr[k++]=root->data;
		inorder(root->right);
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
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	int search;
	scanf("%d",&search);
	int start=0;
	int end=k-1;
	int sum;
	int flag=1;
	for(i=0;i<n;i++)
	{
		sum=arr[i];
		start=i+1;
		end=n-1;
		search=search-sum;
	while(start<=end)
	{
		if(arr[start]+arr[end]==search)
		{
			flag=0;
			printf("%d %d %d",sum,arr[start],arr[end]);
			break;
		}
		else if(arr[start]+arr[end]>search)
		{
			end--;
		}
		else
		{
			start++;
		}
	}
	if(flag==0)
		break;
	}
/*	searchi(root,search);
	//printf("%d",root->right->left->data);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");*/
	return 0;
}
