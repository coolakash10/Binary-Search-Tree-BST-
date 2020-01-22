/*********************************************************************************************************************
     **
     **  Binary Tree using recurssion
     **  Input in the format of integer array
     **  insert and  delete operation using recurssion
     **  Display  Depth First Search and Breadth First Search
     **  Tree is printed in 2dimensional from top to bottom in left to right way
     
     **  Written By:    Akash Vishwas Londhe
     **
*********************************************************************************************************************/

#include<bits/stdc++.h>
#define count 10

using namespace std;

typedef struct node
{
	
	int data;
	struct node *left;
	struct node *right;
	
}NODE;

NODE * insert(NODE * root,int data)
{
	
	if(root==NULL)
	{
		NODE *tmp=(NODE*)malloc(sizeof(NODE));
		tmp->data=data;
		root=tmp;
		return root;
	}
	
	if(data<root->data)
		root->left=insert(root->left,data);
	else
		root->right=insert(root->right,data);
	
	return root;
	
}

int largest(NODE * root)
{
    
	if(root->right==NULL)
		return root->data;
	largest(root->right);
	
}

int smallest(NODE * root)
{
    
	if(root->left==NULL)
		return root->data;
	largest(root->left);
	
}

NODE * deleteNode(NODE *root,int data)
{
    
	if(data<root->data)	
		root->left=deleteNode(root->left,data);
	else if(data>root->data)
		root->right=deleteNode(root->right,data);
	else
	{
		if(root->left==NULL)
		{
			NODE * tmp=(NODE*)malloc(sizeof(NODE));
			tmp=root->right;
			free(root);
			return tmp;
		}
		else if(root->right==NULL)
		{
			NODE * tmp=(NODE*)malloc(sizeof(NODE));
			tmp=root->left;
			free(root);
			return tmp;
		}
		
		//using left subtree
		int max=largest(root->left);
		root->data=max;
		root->left=deleteNode(root->left,max);
		
		//using right subtree
		/*
		int min=smallest(root->right);
		root->data=min;
		root->right=deleteNode(root->right,min);
		*/	
	}
	return root;
	
}

void breadthFirstSearch(NODE *root)
{
	
	queue<NODE *> q;
	
	if(root==NULL )
		return;
		
	// To print in list form
	NODE * currentNode=root;
	
	while(currentNode)
	{
		printf("%d ",currentNode->data);
		
		if(currentNode->left!=NULL)
			q.push(currentNode->left);
		if(currentNode->right!=NULL)
			q.push(currentNode->right);
			
		if(q.empty())
			currentNode=NULL;
		else
		{
		    currentNode=q.front();
		    q.pop();
		}
	}
	
	//To print in level form
	/*
	q.push(root);
	while(!q.empty())
	{
		int size=q.size();
		
		while(size)
		{
		    NODE * tmp=q.front();
			printf("%d ",tmp->data);
			q.pop();
		
			if(tmp->left!=NULL)	
				q.push(tmp->left);
			if(tmp->right!=NULL)	
				q.push(tmp->right);
			size--;
		}
		printf("\n");
	}
	*/
	
}
void printTree(NODE *root, int space)
{
	
	if(root==NULL)
		return;
	
	space = space+count;
	
	printTree(root->right, space);
	
	for(int i=count;i<=space;i++)
		printf(" ");
	printf("%d\n\n",root->data);
	
	printTree(root->left, space);
	
}

void inorder(NODE *root)
{
	
	if(root->left)
		inorder(root->left);
		
	printf(" %d ",root->data);
	
	if(root->right)
		inorder(root->right);
	
}

void preorder(NODE *root)
{
	
	printf(" %d ",root->data);
	
	if(root->left)
		preorder(root->left);	
	
	if(root->right)
		preorder(root->right);
		
}

void postorder(NODE *root)
{
	
	if(root->left)
		postorder(root->left);
			
	if(root->right)
		postorder(root->right);
		
	printf(" %d ",root->data);
		
}

int main()
{
	
	int arr[] = { 7, 5, 4, 3, 2, 12,  15, 16, 14,20,19 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
    
	NODE *sorted_root=(NODE *)malloc(sizeof(NODE));
    sorted_root->data=7; 
    
	for(int i=1;i<n;i++)
	{ 
	    insert(sorted_root,arr[i]);
	}
	
	/***** Depth First Search *****/	
	//inorder display
	printf("Inorder : ");
	inorder(sorted_root);
	
	//preorder display
	printf("\nPreorder : ");
	preorder(sorted_root);
	
	//postorder display
	printf("\nPostorder : ");
	postorder(sorted_root);
	
	/**********************/ 
	
	/***** Breadth  First Search *****/
	
	printf("\nBreadth First Search : ");
	 breadthFirstSearch(sorted_root);
	//print tree in 2dimensional
	printf("\nTree ( sorted ) :\n ");
	printTree(sorted_root,0);
	
	getchar();
	return 0;
	
}
