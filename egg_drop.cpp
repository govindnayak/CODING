#include<bits/stdc++.h>
using namespace std;

/*int egg_drop(int n, int k)
{
	if(k==0 || k==1)
		return k;
	if(n==1)
		return k;
	int min_trial = INT_MAX, ans;

	for(int x=1; x<=k; x++)
	{
		ans = max(egg_drop(n-1, x-1), egg_drop(n, k-x));
		min_trial = min(min_trial, ans);
	}
	return min_trial+1;
}*/
int egg_drop(int n, int k)
{
	int d[n+1][k+1];
	for(int i=0; i<=n; i++)
	{
		d[i][0] = 0;
		d[i][1] = 1;
	}
	for(int i=0; i<=k; i++)
		d[1][i] = i;
	int ans;

	for(int i=2; i<=n; i++)
	{
		for(int j=2; j<=k; j++)
		{
			d[i][j] = INT_MAX;
			for(int x=1; x<=j; x++)
			{
				ans = 1 + max(d[i-1][x-1], d[i][j-x]);
				d[i][j] = min(d[i][j], ans);
			}			
		}
	}
	return d[n][k];
}

int main()
{
	int n, k;
	cin>>n>>k;
	cout<<egg_drop(n, k);
}