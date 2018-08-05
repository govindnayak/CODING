#include<bits/stdc++.h>
using namespace std;
#define N 100005

vector<pair<int, pair<int, int>>> a; //Holds wt, {x, y}
int id[N];
int n, m, wt;

void initialize()
{
	for(int i=1; i<=n; i++)	id[i]=i; 
}

int root(int x)
{
	while(id[x]!=x)
	{
		x = id[id[x]];	
	}
	return x;
}

void merge(int x, int y)
{
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}

int krushkal()
{
	int x, y, cost, mincost=0;

	for(int i=0; i<m; i++)
	{
		x = a[i].second.first;
		y = a[i].second.second;
		cost = a[i].first;

		if(root(x)!=root(y)) 	//check if the selected edge forms cycle
		{
			mincost+=cost;
			merge(x, y);
		}
	}
	return mincost;
}

int main()
{
	int wt, x, y;
	cin>>n>>m;
	initialize();

	for(int i=0; i<m; i++)
	{
		cin>>x>>y>>wt;
		a.push_back(make_pair(wt, make_pair(x, y)));
	}

	sort(a.begin(), a.end()); 	//A Greedy technique!

	cout<<"MinCost: "<<krushkal()<<endl;
}