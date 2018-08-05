#include<bits/stdc++.h>
using namespace std;
/*
For BST:

int lca(int a[], int root, int node1, int node2)
{
	if(a[root]==0)
		return 0;

	if(a[root]>node1 && a[root]>node2)
		return lca(a, 2*root, node1, node2); 	//both on left

	if(a[root]<node1 && a[root]<node2)
		return lca(a, 2*root+1, node1, node2); 	//both on right

	return root;	//if 1 on left, 1 on right, answer!
}
*/
int a[1005];

int lca(int a[], vector<int> &path, int node, int root)
{
	if(a[root]==0)
		return 0;

	path.push_back(a[root]);

	if(a[root]==node)
		return 1;

	int left = 2*root; int right = 2*root+1;

	if((a[left]!=0 && lca(a, path, node, left)) || (a[right]!=0 && lca(a, path, node, right)))
		return 1;

	path.pop_back();
	return 0;
}

int main()
{
	int n, n1, n2;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];

	int root = a[1];
	
	cin>>n1>>n2;
	vector<int> path1;
	vector<int> path2;

	if(!lca(a, path1, n1, root) || !lca(a, path2, n2, root))
	{
		cout<<"Not found!"<<endl;
		exit(0);
	}
	int ans;

	for(int i=0, j=0; i<path1.size(), j<path2.size(); i++, j++)
	{
		if(path1[i]!=path2[j])
			break;
		ans = path1[i];
	}
	
	cout<<ans<<endl;
	
}	