//Beautiful!

#include<bits/stdc++.h>
using namespace std;

map<int, int> l, r;

int main()
{
	int n, k;
	cin>>n>>k;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
		r[a[i]]++;		//keep a count
	}
	int ans = 0;
	for(int i=0; i<n; i++)
	{
		r[a[i]]--;

		if(a[i]%k==0)		//Taking as middle element
		{
			ans+= (l[a[i]/k]) * (r[a[i]*k]);	//To its left and right
		}

		l[a[i]]++;
	}
	cout<<ans<<endl;
}