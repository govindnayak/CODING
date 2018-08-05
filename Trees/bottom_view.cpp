//This also shows how to insert into normal binary tree using queues! (Not BST!)
//Do the same for top view, but no overwriting!

#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	int hd = INT_MAX; 	//Horizontal Depth!
	struct node *left, *right;
}node;

node* newnode(int ele)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = ele;
	temp->right = NULL; temp->left = NULL;
	return temp;
}

node* insert_node(node *root, int ele)
{
	if(root==NULL)
		return newnode(ele);

	queue<node*> q;
	q.push(root);

	while(!q.empty())
	{
		node *temp = q.front(); q.pop();

		if(temp->left==NULL)
		{
			temp->left = newnode(ele);
			break;
		}
		else
			q.push(temp->left);

		if(temp->right==NULL)
		{
			temp->right = newnode(ele);
			break;
		}
		else
			q.push(temp->right);
	}
	return root;
}

void bottom_view(node *root)
{
	if(root==NULL)	return;

	map<int, int> d;
	map<int, int>:: iterator iter;

	root->hd = 0;

	queue<node*> q;
	q.push(root);

	int depth;

	while(!q.empty())
	{
		node *temp = q.front(); q.pop();

		depth = temp->hd;
		d[depth] = temp->data;

		if(temp->left!=NULL)
		{
			temp->left->hd = depth-1;
			q.push(temp->left);
		} 
		if(temp->right!=NULL)
		{
			temp->right->hd = depth+1;
			q.push(temp->right);
		}

	}

	for(iter=d.begin(); iter!=d.end(); iter++)
		cout<<iter->second<<" ";
}

int main()
{
	int n;
	node *root = NULL;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		if(i==0)
			root = insert_node(root, x);
		else
			root = insert_node(root, x);
	}
	bottom_view(root);

	return 0;
}