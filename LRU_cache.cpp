#include<bits/stdc++.h>
using namespace std;

int main()
{
	map<int, list<int>::iterator> m;
	list<int> cache;
	int n, csize, x;

	cin>>n>>csize;
	for(int i=0; i<n; i++)
	{
		cin>>x;

		if(m.count(x)==0)
		{
			if(cache.size()==csize)
			{
				int last = cache.back();
				cache.pop_back();
				m.erase(last);
			}
		}
		else
		{
			cache.erase(m[x]);
		}

		cache.push_front(x);
		m[x] = cache.begin();
	}
	for(auto iter: cache)
	{
		cout<<iter<<" ";
	}
}