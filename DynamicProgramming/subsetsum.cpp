#include<bits/stdc++.h>
using namespace std;

/*bool subset(int a[], int n, int sum)
{
	if(sum==0)
		return true;
	if(n==0 && sum!=0)
		return false;
	if(a[n-1]>sum)
		return subset(a, n-1, sum);

	return (subset(a, n-1, sum) || subset(a, n-1, sum-a[n-1]));
}*/

bool subset(int a[], int n, int sum)
{
	bool d[n+1][sum+1];

	for(int i=0; i<=n; i++)
		d[i][0] = true;
	for(int i=1; i<=sum; i++)
		d[0][i] = false;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=sum; j++)
		{
			if(a[i-1]>j)
				d[i][j] = d[i-1][j];
			else
			{
				if(j-a[i-1]>=0)
					d[i][j] = d[i-1][j] || d[i-1][j-a[i-1]];
			}
		}
	}
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=sum; j++)
			cout<<d[i][j]<<"  ";
		cout<<"\n";
	}
}
int main()
{
	int n, sum;
	cin>>n>>sum;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	cout<<subset(a, n, sum);
}