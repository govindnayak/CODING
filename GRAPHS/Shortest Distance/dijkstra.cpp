//This is not normal dijkstra! We're using priority queues to inrease efficiency!
//Usually it is O(V^2)
//With min-priority-queues, it is O(V + E logV)
//Holy shit! It's just like BFS!

#include<bits/stdc++.h>
using namespace std;
#define MAX 10005

vector<pair<int, int>> a[MAX];
int d[MAX];
int visited[MAX];

void dijkstra()
{
	fill(visited, visited+MAX, 0);
	fill(d,d+MAX,INT_MAX);

	d[1]=0; 	//source
	multiset<pair<int, int>> s; 	//min-priority-queue

	s.insert({0, 1}); 	//(dist, node) 

	while(!s.empty())
	{
		pair<int, int> p = *s.begin(); 		//Just like queues in BFS!
		s.erase(s.begin());

		int i = p.second;
		int wt = p.first;

		if(!visited[i])
		{
			visited[i] = 1;

			for(int j=0; j<a[i].size(); j++)
			{
				int node = a[i][j].first;
				int w = a[i][j].second;

				if(d[i] + w < d[node])
				{
					d[node] = d[i]+w;	
					s.insert( {d[node], node} );
				}
			}
		}
	}
}

int main()
{
	int n, m;
	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int x, y, wt;
		cin>>x>>y>>wt;

		a[x].push_back(make_pair(y, wt));
		a[y].push_back(make_pair(x, wt));
	}

	dijkstra();

	for(int i=0; i<=n; i++)
		cout<<d[i]<<endl;
}