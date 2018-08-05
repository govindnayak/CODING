#include<bits/stdc++.h>
using namespace std;

vector<int> a[100005];
int visited[100005];

void dfs(int i)
{
	visited[i]=1;
	cout<<i<<" ";

	for(int j=0; j<a[i].size(); j++)
	{
		if (!visited[a[i][j]])
		{
			dfs(a[i][j]);
		}
	}
}

int main()
{
	int n, m, x, y;
	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	for(int i=1; i<=n; i++)
	{
		if(!visited[i])
		{
			dfs(i);
			cout<<endl;
		}
	}
}