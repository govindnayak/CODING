//Node x will be in the subtree of node y if and only if intime of node x is greater than intime of 
//node y and outtime of node x is less than outtime of node y. That mean tin[x]>tin[y] and tout[x]<tout[y]
//We maintain a timer t to keep track of every node's in-out time
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define f first
#define se second
ll mod=1000000007;
vector<int> v[200001];
ll in[200001];
ll out[200001];
int vis[200001];
ll t=1;
void dfs(int n)
{
    vis[n]=1;
    in[n]=t;
    t++;
    for(int i=0;i<v[n].size();i++)
    {
        if(vis[v[n][i]]==0)
        {
            dfs(v[n][i]);
        }
    }
    out[n]=t;
    t++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll q;
    cin>>n>>q;
    for(int i=0;i<=n;i++)
        vis[i]=0;
 
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1);
    while(q--)
    {
        cin>>x>>y;
        if(in[x]<in[y]&&out[x]>out[y])
            cout<<"YES"<<"\n";
        else if(in[x]>in[y]&&out[x]<out[y])
            cout<<"YES"<<"\n";
        else
            cout<<"no"<<"\n";
    }
    return 0;
}
