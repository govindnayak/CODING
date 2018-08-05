#include<bits/stdc++.h>
using namespace std;

int compute(string s, int n)
{
	bool d[n][n];
	int c[n] = {0};
	for(int i=0; i<n; i++)
		d[i][i] = true;

	for(int k=2; k<=n; k++)
	{
		for(int i=0; i<n-k+1; i++)
		{
			int j = i+k-1;

			if(k==2)
				d[i][j] = s[i]==s[j];
			else
				d[i][j] = s[i]==s[j] && d[i+1][j-1];
		}
	}

	for(int i=0; i<n; i++)
	{
		if(d[0][i])
			c[i] = 0;	
		else
		{
			c[i] = INT_MAX;
			for(int j=0; j<i; j++)
			{
				if(d[j+1][i])
					c[i] = min(c[i], 1+c[j]);
			}
		}
	}
	return c[n-1];
}

int main()
{
	string s = "ababbbabbababa";
	cout<<compute(s, s.length())<<"\n";
}