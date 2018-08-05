#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left, *right;
}node;

node* newnode(int ele)
{
    node *n = (node*)malloc(sizeof(node));
    n->data = ele;
    n->right = NULL; n->left = NULL;
    return n;
}

node* insert_node(node *root, int ele)
{
    if(root==NULL)
    {
        return newnode(ele);
    }
    else
    {
        if(ele<root->data)
            root->left = insert_node(root->left, ele);
        else
            root->right = insert_node(root->right, ele);
    }
    return root;
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    int n, x;
    cin>>n;
    node *root = NULL;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        if (i==0)
            root = insert_node(root, x);
        else
            insert_node(root, x);
    }
    inorder(root);
    
    return 0;
}