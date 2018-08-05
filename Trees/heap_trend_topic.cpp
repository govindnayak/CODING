#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

map<ll, ll> newsum;

ll getsum(ll id, ll z, ll p, ll l, ll c, ll s)
{
    newsum[id] = (p*50) + (l*5) + (10*c) + (20*s); 
    return (newsum[id] - z);
}

int main()
{
    ll n, id, z, p, l, c, s;
    cin>>n;

    priority_queue<pair<ll, ll>> q;
    
    for(int i=0; i<n; i++)
    {
        cin>>id>>z>>p>>l>>c>>s;
        q.push(make_pair(getsum(id, z, p, l, c, s), id));
    }
    
    for(int i=0; i<5; i++)
    {
        pair<ll, ll> ans = q.top();
        ll sums, ids;
        ids = ans.second;
        sums = newsum[ids];
        
        cout<<ids<<" "<<sums<<"\n";
        q.pop();
    }   
    
    
}