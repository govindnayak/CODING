//Optimal route from first node to last node! BFS!

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, x, y;
        cin>>n>>m;
        
        vector<int> a[n+1];
        int visited[n+1], d[n+1];
        for(int i=0; i<=n+1; i++)
            visited[i]=0;
        for(int i=0; i<=n+1; i++)
            d[i]=0;
        queue<int> q;
        for(int i=0; i<m; i++)
        {
            cin>>x>>y; a[x].push_back(y); a[y].push_back(x);
        }
        
        q.push(1);
        
        int c=0, flag=0;
        while(!q.empty() && flag==0)
        {
            int i=q.front(); q.pop();
            visited[i]=1;
            for(int j=0; j<a[i].size(); j++)
            {
                if(!visited[a[i][j]])
                {
                    d[a[i][j]] = d[i]+1;
                    visited[a[i][j]]=1;
                    q.push(a[i][j]);
                }
            }
        }
        for(int i=1; i<=n; i++)
            cout<<d[i]<<endl;
        
    }
}