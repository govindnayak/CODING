#include<bits/stdc++.h>
using namespace std;

/*int min_coins(int a[], int n, int amt)
{
	if(amt==0)
		return 0;
	int ans = INT_MAX;
	for(int i=0; i<n; i++)
	{
		if(a[i]>amt)
			continue;
		int count = min_coins(a, n, amt-a[i]);
		if(count!=INT_MAX)
			ans = min(ans, count+1);
	}
	return ans;
}*/
int min_coins(int a[], int n, int amt)
{
	int d[amt+1];
	d[0] = 0;
	for(int i=1; i<=amt; i++)
		d[i] = INT_MAX;

	for(int i=1; i<=amt; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(a[j]<=i)
			{
				int count = d[i-a[j]];
				if(count!=INT_MAX)
					d[i] = min(d[i], count+1);
			}
		}
	}
	return d[amt];
}

int main()
{
	int n, amt;
	cin>>n>>amt;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<min_coins(a, n, amt)<<"\n";

}