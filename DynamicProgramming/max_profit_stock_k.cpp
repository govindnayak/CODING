	//Can buy-sell atmost k times

	#include<bits/stdc++.h>
	using namespace std;

	int maxProfit(int a[], int n, int k)
	{
		int profit[k+1][n+1];

		for(int i=0; i<=k; i++)
			profit[i][0] = 0;		//Day 1 - No profit
		for(int i=0; i<=n; i++)
			profit[0][i] = 0;		//No transaction

		for(int i=1; i<=k; i++)
		{
			int d = INT_MIN;		//Difference previous

			for(int j=1; j<n; j++)
			{
				d = max(d, profit[i-1][j-1] - a[j-1]);
				profit[i][j] = max(profit[i][j-1], a[j]+d);
			}
		}
		return profit[k][n-1];
	}

	int main()
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		cout<<maxProfit(a, n, k)<<endl;
	}