#include<bits/stdc++.h>
using namespace std;

int visited[100];
int a[100][100];
int n;
int flag=0;
int c=0;

void dfs(int i)
{
	visited[i] = 1;

	for(int j=0; j<n; j++)
	{
		if (visited[j]==0 && a[i][j]==1)
			dfs(j);
		if (visited[j]==1 && a[i][j]==1)
		{
			flag=1;
			c++;
		}
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	dfs(0);

	if(flag)
		cout<<"YES!"<<" "<<c<<endl;
	else
		cout<<"NO!"<<" "<<c<<endl;
}