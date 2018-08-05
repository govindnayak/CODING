//Use BackTracking in DFS!
//Find no. of unique paths available. Here 0's are 1's and 1's are 0's in input graph 
#include<bits/stdc++.h>
using namespace std;

int n, c=0;
int a[30][30];
int visited[30][30];
int d[4][2] = {(-1, 0), (1, 0), (0, -1), (0, 1)};

int isvalid(int x, int y)
{
	return (x>=0 && y>=0 && x<n && y<n && a[x][y]==0);
}

void dfs(int x, int y)
{
	visited[x][y]=1;
	if(x==n-1 && y==n-1)
	{
		c++;
		visited[x][y]=0;
		return;
	}

	for(int j=1; j<4; j++)
	{
		int x1 = x+d[j][0], y1=y+d[j][1];
		if(isvalid(x1, y1) && !visited[x][y])
			dfs(x1 ,y1);
	}

	visited[x][y]=0;		//BACKTRACKING! REMEMBER!
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; i++)
			for(j=0; j<n; j++)
				cin>>a[i][j];
		c = 0;
		dfs(0,0);

		cout<<c<<endl;
	}
}