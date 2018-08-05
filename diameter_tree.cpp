#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	struct node *left, *right;
}node;
node* getnode(int ele)
{
	node* n = new node;
	n->data = ele;
	n->right = NULL; n->left = NULL;
	return n;
}
int diameter(node* root, int *height)
{
	if(root==NULL)
		return 0;

	int lh = 0, rh = 0;

	int ld = diameter(root->left, &lh);
	int rd = diameter(root->right, &rh);

	*height = max(lh, rh)+1;

	return max(max(ld, rd), lh+rh+1);
}
int main()
{
	node* root = getnode(1);
	root->left = getnode(2);
	root->right = getnode(3);

	int height = 0;
	cout<<diameter(root, &height)<<"\n";
}