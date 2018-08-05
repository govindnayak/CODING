#include<bits/stdc++.h>
using namespace std;

vector<int> a[1000];
int visited[1000];
int d[1000];

void dfs(int i, int depth)
{
    visited[i]=1;
    d[i] = depth;

    for(int j=0; j<a[i].size(); j++)
    {
        if(!visited[a[i][j]])
        {
            dfs(a[i][j], depth+1);
        }
    }
}

int main()
{
    int m,n;
    cin>>n>>m;
    for(int i=0;i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 0);

    for(int i=1; i<=n; i++)
        cout<<d[i]<<" ";
    cout<<endl;
}