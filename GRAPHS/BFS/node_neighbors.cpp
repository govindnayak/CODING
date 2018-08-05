//Find number of nodes at a distance 'x' from the given node in the query!

#include<bits/stdc++.h>
using namespace std;

vector<int> a[100005];
int visited[100005];
int d[100005]; int c;

void bfs(int s, int x)
{
    queue<int> q;
    q.push(s);
    visited[s]=1;
    c = 0;
    d[s]=0;
    while(!q.empty())
    {
        int i=q.front(); q.pop();
        for(int j=0; j<a[i].size(); j++)
        {
            if(!visited[a[i][j]])
            {
                d[a[i][j]] = d[i]+1;
                visited[a[i][j]]=1;
                q.push(a[i][j]);
                
                if(d[a[i][j]]==x)
                    c++;
            }
        }
    }
}

int main()
{
    int n, m, t, x;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v; a[u].push_back(v); a[v].push_back(u);
    }
    cin>>t;
    
    while(t--)
    {
        int s;
        cin>>s>>x;
        bfs(s, x);
        cout<<c<<"\n";

        for(int i=0; i<=n+1; i++)
            visited[i]=0;
        for(int i=0; i<=n+1; i++)
            d[i]=0;
        
    }
    
}
