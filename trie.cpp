//Takes O(M) to search!
//Better than balanced BST (M log(N))

#include<bits/stdc++.h>
using namespace std;
#define MAX 26

typedef struct Node
{
	struct Node *child[MAX];
	bool flag;
}node;

node* getnode()
{
	node *n = (node*)malloc(sizeof(node));
	n->flag = false;
	for(int i=0; i<MAX; i++)
		n->child[i] = NULL;
	return n;
}

void insert(node* root, string s)
{
	node* temp = root;
	for(int i=0; i<s.length(); i++)
	{
		int ind = s[i] - 'a';
		if(!temp->child[ind])
			temp->child[ind] = getnode();
		temp = temp->child[ind];
	}
	temp->flag = true;
}

bool search(node* root, string s)
{
	node* temp = root;
	for(int i=0; i<s.length(); i++)
	{
		int ind = s[i] - 'a';
		if(!temp->child[ind])
			return false;
		temp = temp->child[ind];
	}
	if(temp!=NULL and temp->flag==true)
		return true;
	else
		false;
}
int main()
{
	node* root = getnode();
	string a[6] = {"Man", "Dog", "Mandate", "Ctiy", "Computer", "Compact"};
	for(int i=0; i<6; i++)
		insert(root, a[i]);
	
	string key;
	cin>>key;
	cout<<search(root, key)<<"\n";
	
}