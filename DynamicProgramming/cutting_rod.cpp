#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int price[n+2];

	for(int i=0; i<n; i++)
		cin>>price[i];

	int ans[n+1];
	ans[0] = 0;

	for(int i=1; i<=n; i++)
	{
		int m = INT_MIN;

		for(int j=0; j<i; j++)
			m = max(m, price[j]+ans[i-j-1]);

		ans[i] = m;
	}

	cout<<ans[n];
}