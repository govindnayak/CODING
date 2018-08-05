//Inorder traversal of a BST gives sorted array
//Do inorder traversal of the given tree and solve: min swaps needed to sort an array!
//To do this, detect the num of cycles in the array (graph)

#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

int a[MAX], b[MAX], visited[MAX];
int n, k=1;

void inorder(int x)
{
	if(2*x<=n)
		inorder(2*x);
	b[k++] = a[x];
	if(2*x+1<=n)
		inorder(2*x+1);
}

int main()
{
	int ans = 0;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
		
    inorder(1);
	pair<int, int> pos[n];
	
	for(int i=1; i<=n; i++)
	{
		pos[i].first = b[i];
		pos[i].second = i;
	}
	
    sort(pos, pos+n+1);		//remember
    
	for(int i=1; i<=n; i++)
	{
		if(visited[i] || pos[i].second==i)
			continue;

		int j = i;
        int c = 0;
		while(!visited[j])		//cycle detection
		{
		    visited[j]=1;
			j = pos[j].second;
			c++;
		}
		ans+=(c-1);		//Formula: Sum of cycles - 1
	}
	
	cout<<ans;
	return 0;
}