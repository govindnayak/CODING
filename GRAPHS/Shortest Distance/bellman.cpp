//Bellman Ford for: 1 source to all nodes shortest paths
// O(V.N) - Quite bad! (Worst: O(V^3))

#include<bits/stdc++.h>
using namespace std;
#define INF 2e9

vector<int> a[2005];
int d[2005];
int n, m;

void bellman(int s)
{
	for(int i=0; i<m+2; i++)
		d[i] = INF;

	d[s]=0;

	for(int i=0; i<n-1; i++)
	{
		int j=0;
		while(a[j].size()!=0)	// For number of edges
		{
			if (d[a[j][0]] + a[j][2] < d[a[j][1]]) //0-From 1-Next 2-Weight
			{
				d[a[j][1]] = d[a[j][0]] + a[j][2];
			}

			j++;
		}
	}
}

int main()
{
	int x, y, wt;
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>x>>y>>wt;
		a[i].push_back(x);
		a[i].push_back(y);
		a[i].push_back(wt);
	}

	bellman(1); 	// 1 source to all nodes shortest path!

	for(int i=1; i<=n; i++)
		cout<<d[i]<<endl;

}