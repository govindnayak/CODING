#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int flag[MAX];
int tree[MAX];
int max_level = 0;

void print_right(int node, int level)
{
	if(!flag[node] && level>max_level)
	{
		cout<<tree[node]<<"\n";
		flag[node] = 1;
		max_level = level;
	}

	if(tree[2*node+1]!=0)
		print_right(2*node+1, level+1);
	if(tree[2*node]!=0)
		print_right(2*node, level+1);
}

void print_left(int node, int level)
{
	if(!flag[node] && level>max_level)
	{
		cout<<tree[node]<<"\n";
		flag[node] = 1;
		max_level = level;
	}

	if(tree[2*node]!=0)
		print_left(2*node, level+1);
	if(tree[2*node+1]!=0)
		print_left(2*node+1, level+1);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(flag, 0, sizeof(flag));
		for(int i=1; i<=n; i++)
		{
			cin>>tree[i];
		}

		max_level = 0;
		print_right(1, 1);
		max_level = 0;
		print_left(1, 1);
		cout<<"\n";
	}
	return 0;
}