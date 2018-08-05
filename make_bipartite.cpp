#include<bits/stdc++.h>
using namespace std;

vector<int> a[100];
int flag[100];

void dfs(int i)
{
    for(int j=0; j<a[i].size(); j++)
    {
        int node = a[i][j];
        if(flag[i]==flag[node])
        {
            cout<<"IMPOSSIBLE\n";
            exit(0);
        }
        if(flag[node]==0)
        {
            if(flag[i]==1)
                flag[node] = 2;
            else
                flag[node] = 1;
            dfs(node);
        }
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        if(!flag[i])
        {
            flag[i] = 1;
            dfs(i);
        }
    }
    for(int i=1; i<=n; i++)
        if(flag[i]==1)  cout<<i<<" ";
    cout<<endl;
    for(int i=1; i<=n; i++)
        if(flag[i]==2)  cout<<i<<" ";
    cout<<endl;
}