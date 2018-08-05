#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	char c;
	int freq;
	struct node *left, *right;
}node;

bool compare(node* a, node* b)
{
	return (a->freq)>(b->freq);
}

node* getnode(char s, int count)
{
	node* n = new node;
	n->c = s;
	n->freq = count;
	n->left = NULL;	n->right = NULL;
	return n;
}

void printtree(node* root, string ans)
{
	if(root!=NULL)
	{
		if(root->c!='$')
			cout<<root->c<<" "<<ans<<"\n";
		printtree(root->left, ans+"0");
		printtree(root->right, ans+"1");
	}
}

void huffman(vector<char> data, vector<int> freq)
{
	priority_queue<node*, vector<node*>, function<bool(node*, node*)>> q(compare);		//min-heap
	int n = data.size();
	node* root;

	for(int i=0; i<n; i++)
		q.push(getnode(data[i], freq[i]));

	while(q.size()!=1)
	{
		node* left = q.top(); 	q.pop();
		node* right = q.top(); 	q.pop();

		root = getnode('$', (left->freq + right->freq));
		root->left = left;
		root->right = right;
		q.push(root);
	}

	printtree(q.top(), "");		//Second paramter for binary string
}

int main()
{
	int n;
	cin>>n;
	vector<char> data(n);
	vector<int> freq(n);
	for(int i=0; i<n; i++)
		cin>>data[i];
	for(int i=0; i<n; i++)
		cin>>freq[i];
	huffman(data, freq);
}