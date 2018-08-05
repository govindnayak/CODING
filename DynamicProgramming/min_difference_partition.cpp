#include<bits/stdc++.h>
using namespace std;
/*int partition(int a[], int n, int sum, int ans)
{
	if(n==0)
		return abs((ans-sum)-sum);

	return min(partition(a, n-1, sum+a[n-1], ans), partition(a, n-1, sum, ans));
}*/

int partition(int a[], int n, int sum)
{
	bool d[n+1][sum+1];
	
	for(int i=0; i<=n; i++)
		d[i][0] = true;
	for(int i=1; i<=sum; i++)
		d[0][i] = false;		//same as subset sum problem

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=sum; j++)
		{
			d[i][j] = d[i-1][j];

			if(a[i-1]<=j)
				d[i][j] = d[i][j] || d[i-1][j-a[i-1]];
		}
	}

	int ans;
	for(int j=sum/2; j>=0; j--)
	{
		if(d[n][j]==true)
		{
			ans = sum-(2*j);
			break;			//Find the smallest difference with largest j value
		}
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	int a[n], sum=0;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	cout<<partition(a, n, sum)<<"\n";
}