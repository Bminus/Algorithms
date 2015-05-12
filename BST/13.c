#include<stdio.h>
#include<stdlib.h>
int flag=1;
struct node
{
	int data;
	int l;
	struct node* left;
	struct node* right;
	struct node* par;
};
void identical(int* arr1,int* arr2,int n,int m)
{
	if(n==0 && m==0)
		return;
	if(arr1[0]!=arr2[0])
		flag=0;
	int i;
	int x=0;
	int y=0;
	int z=0;
	int w=0;
	int arr3[1000];
	int arr4[1000];
	int arr5[1000];
	int arr6[1000];
	for(i=1;i<n;i++)
	{
		if(arr1[i]<arr1[0])
		{
			arr3[x++]=arr1[i];
		}
		else
		{
			arr4[y++]=arr1[i];
		}

	}
	for(i=1;i<m;i++)
	{
		if(arr2[i]<arr2[0])
		{
			arr5[z++]=arr2[i];
		}
		else
		{
			arr6[w++]=arr2[i];
		}
	}
//	for(i=0;i<w;i++)
//		printf("%d ",arr6[i]);
	identical(arr3,arr5,x,z);
	identical(arr4,arr6,y,w);
}


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
void lowest_ancestor(struct node* root,int a,int b)
{
	if(root->data>=a && root->data<=b)
	{
		printf("%d ",root->data);
	}
	else if(root->data>=b && root->data>=a)
	{
		lowest_ancestor(root->left,a,b);
	}
	else
	{
		lowest_ancestor(root->right,a,b);
	}
}
struct node* build(int* arr,struct node* root,int first,int last)
{
	if(first<=last)
	{
	root=(struct node*)malloc(sizeof(struct node));
	int middle=(first+last)/2;
	root->data=arr[middle];
	root->left=NULL;
	root->right=NULL;
	root->left=build(arr,root->left,first,middle-1);
//	printf("%d",root->left->data);
	root->right=build(arr,root->right,middle+1,last);
	return root;
	}
	else
		return NULL;
}
void ser(struct node* root,int search)
{
	if(root->data==search)
	{
		if(root->right!=NULL)
		{
			root=root->right;
			while(root->left!=NULL)
			{
				root=root->left;
			}
			printf("%d ",root->data);
		}
		else
		{
			while(root->par->left!=root)
			{
				root=root->par;
			}
			printf("%d ",root->par->data);
		}
	}
	else if(root->data>search)
	{
		ser(root->left,search);
	}
	else
	{
		ser(root->right,search);
	}
}

void kth_smallest(struct node* root,int k)
{
	if(root->l==k-1)
		printf("%d ",root->data);
	else if(root->l>=k)
	{
		kth_smallest(root->left,k);
	}
	else
	{
		kth_smallest(root->right,k-root->l-1);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int arr1[100000];
	int arr2[100000];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
	}
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&arr2[i]);
	}
	identical(arr1,arr2,n,m);
	printf("%d",flag);

	/*inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");*/
/*	int k;
	scanf("%d",&k);
	kth_smallest(root,k);*/
/*	int search;
	scanf("%d",&search);
	ser(root,search);*/

/*	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	root=build(arr,root,0,n-1);
	inorder(root);
	printf("\n");*/
/*	int a,b;
	scanf("%d %d",&a,&b);
	lowest_ancestor(root,a,b);*/
	/*int search;
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
	}*/
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
