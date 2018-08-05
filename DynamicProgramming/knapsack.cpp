//Solve 0/1 Knapsack problem using Dynamic Programming 

#include<bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
	return (a>b?a:b);
}

int main()
{

	int n, x, y, wt, min=1000;
	cin>>n;
	int w[n], v[n];
	for(int i=0;i<n;i++)
	{
		cin>>w[i]>>v[i];

		if(w[i]<min)
			min = w[i];
	}
	cin>>wt;

	int dp[n][wt+1];

	if(min>wt)
	{
		cout<<0<<endl;
		exit(0);
	}

	dp[0][0] = 0;
	for(int i=1; i<=wt; i++)
		dp[0][i] = 1;

	for(int i=1; i<n;i++)
	{
		for(int j=0;j<=wt;j++)
		{
			if(j==0)
				dp[i][j] = 0;

			if(j<w[i])
				dp[i][j] = dp[i-1][j];
			else
			{
				dp[i][j] = max(v[i]+dp[i-1][j-w[i]], dp[i-1][j]);
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=wt;j++)
		{
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}

}	