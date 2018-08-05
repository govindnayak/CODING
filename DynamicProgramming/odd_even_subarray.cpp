#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll,ll> mp;
ll ans(string s)
{  
    ll res=0,oc=0,zc=0;
    mp[0]=1;
    for(ll i=0;i<ll(s.length());i++)
    { if(s[i]=='1')
       oc++;
       else
       zc++;
       ll tmp=oc-zc;
       res+=mp[tmp];
       mp[tmp]++;
    }
    return res;
}
 
int main()
{ 
     string s="";
     ll n;
     cin>>n;
     while(n--)
     { 
         ll k;
         cin>>k;
         if(k%2==0)
         s+='1';
         else
         s+='0';
     }
     cout<<ans(s);
     return 0;
}
Language: C++14