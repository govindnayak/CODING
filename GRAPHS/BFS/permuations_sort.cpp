//Make a list to ascending order in minimum number of operations
//Operation: Reverse a part of the array (interval prefix)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
map<vi,int> m;
void bfs(vi v,int n)
{
  vi perm;
  for(int i=1;i<=n;i++) perm.push_back(i);
  queue<vi> q;
  q.push(v);
  m[v]=0;
  while(!q.empty())
  {
    vi vec=q.front();
    q.pop();
    for(int i=1;i<=n;i++)
    {
      vi nv=vec;
      reverse(nv.begin(),nv.begin()+i);
      if(!m.count(nv))
      {
        m[nv]=m[vec]+1;
        q.push(nv);
      }
    }
  }
  cout<<m[perm]<<"\n";
}
int main()
{
  int n;
  cin>>n;
  vi vec(n);
  for(int i=0;i<n;i++)  cin>>vec[i];
  bfs(vec,n);
	return 0;
}
