#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
ll values[200005];
vector<ll> a[200005];
map<ll, int> visited;
ll ans=0;

ll dfs(int s, int i)
{
    visited[s] = 1;
    ans=max(ans, ans^values[s]);
    for(int j=0; j<a[s].size(); j++)
    {
        if(!visited[a[s][j]] && a[s][j]!=i)
            dfs(a[s][j]);
    }
    visited[s] = 0;
    return ans;
}
int main()
{
    cin>>n;
    bool parent[n+1] = {false};
    for(int i=1; i<=n; i++)
        cin>>values[i];
    for(int i=0; i<n-1; i++)
    {
        ll x, y;
        cin>>x>>y;
        
        a[x].push_back(y);
        a[y].push_back(x);
        parent[x] = true;
    }
    ll sum=0;
    for(int i=2; i<=n; i++)
    {
        ans = 0;
        sum+=dfs(1, i);
    }
    cout<<sum<<"\n";
}