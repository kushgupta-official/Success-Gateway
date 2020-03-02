# include <iostream>
# include <stdlib.h>
using namespace std;

typedef struct tree{
	struct tree *left;
	int data;
	struct tree *right;
}btree;

btree *head=NULL;
btree* in(int d)
{
	btree *temp=(struct tree*)malloc(sizeof(tree));
	temp->data=d;
	temp->left=temp->right=NULL;
	return(temp);
}

void inorder(btree *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		cout<<t->data<<"->";
		inorder(t->right);
	}
}

void preorder(btree *t)
{
	if(t!=NULL)
	{
		cout<<t->data<<"->";
		preorder(t->left);
		preorder(t->right);
	}
}

void postorder(btree *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		cout<<t->data<<"->";
	}
}

void converse_preorder(btree *t)
{
	if(t!=NULL)
	{
		cout<<t->data<<"->";
		converse_preorder(t->right);
		converse_preorder(t->left);
	}
}

void converse_inorder(btree *t)
{
	if(t!=NULL)
	{
		converse_inorder(t->right);
		cout<<t->data<<"->";
		converse_inorder(t->left);
	}
}

void converse_postorder(btree *t)
{
	if(t!=NULL)
	{
		converse_postorder(t->right);
		converse_postorder(t->left);
		cout<<t->data<<"->";
	}
}
int main()
{
	btree *t;
	t=in(1);
	t->left=in(2);
	t->right=in(3);
	t->left->right=in(4);
	t->right->left=in(5);
	cout<<"Inorder : ";
	inorder(t);
	cout<<"NULL\n";
	cout<<"Preorder : ";
	preorder(t);
	cout<<"NULL\n";
	cout<<"Postorder : ";
	postorder(t);
	cout<<"NULL\n";
	cout<<"Converse Inorder : ";
	converse_inorder(t);
	cout<<"NULL\n";
	cout<<"Converse Preorder : ";
	converse_preorder(t);
	cout<<"NULL\n";
	cout<<"Converse Postorder : ";
	converse_postorder(t);
	cout<<"NULL\n";
//	return 0;
}


