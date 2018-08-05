#include<bits/stdc++.h>
using namespace std;

int tree[1005];
vector<int> a;

void build(int node, int start, int end)
{
	if(start==end)
	{
		tree[node] = a[start];
	}
	else
	{
		int mid = (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);

		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

void update(int root, int start, int end, int ind, int val)
{
	if(start==end)
	{
		a[ind]+=val;
		tree[root]+=val;
	}
	else
	{	
		int mid = (start+end)/2;
		
		if(start<=ind && mid>=ind)
			update(2*root, start, mid, ind, val);
		else
			update(2*root+1, mid+1, end, ind, val);
	}
}

int query(int node, int start, int end, int l, int r)
{
	if(l>end || r<start)
		return 0;
	if(l>=start && r<=end)
	{
		return tree[node];
	}

	int mid = (start+end)/2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);
	return p1+p2;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0; i<n-1; i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	build(1, 0, n-1);
	cout<<query(1, 0, n-1, 0, 2);
}