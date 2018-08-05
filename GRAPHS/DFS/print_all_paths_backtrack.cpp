#include<bits/stdc++.h>
using namespace std;
int m, n;
vector<int> a[10005];
int visited[10005];


void dfs(int i, int path[], int ind)
{
	visited[i]=1;
	path[ind] = i;
	ind++;

	if(i==n)
	{
		for(int i=0; i<ind; i++)
			cout<<path[i]<<" ";
		cout<<"\n";
	}

	for(int j=0; j<a[i].size(); j++)
	{
		if(!visited[a[i][j]])
		{
			dfs(a[i][j], path, ind);
		}

	}
	ind--;
	visited[i]=0;
}

int main()
{
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		int x, y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	int path[n+1];
	dfs(1, path, 0);


}