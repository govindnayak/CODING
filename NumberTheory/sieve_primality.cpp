//Print all the prime numbers less than n. 

#include<bits/stdc++.h>
using namespace std;

void sieve(int n)
{
	bool flag[n+1];
	fill(flag, flag+n+1, true);

	for(int p=2; p*p<=n; p++) 	//p less than root(n)
	{
		if(flag[p]==true)
		{
			for(int i=2*p; i<=n; i+=p)	// 2p, 3p, 4p,......
			{
				flag[i] = false;
			}
		}
	}

	for(int i=2; i<=n; i++)
	{
		if(flag[i]==true)		// check primality of n here!
			cout<<i<<" ";
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;

	sieve(n);
}