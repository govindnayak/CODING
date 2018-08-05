#include<bits/stdc++.h>
using namespace std;

void prime(int n)
{
	while(n%2==0)		//print all 2's that divide n 
	{
		cout<<2<<" ";
		n = n/2;
	}

	for(int i=3; i<=sqrt(n); i=i+2)	//i = i+2	
	{
		while(n%i==0)
		{
			cout<<i<<" ";
			n = n/i;
		}
	}

	if(n>2)		//one extra case to be handled
		cout<<n<<"\n";
}

int main()
{
	int n;
	cin>>n;
	prime(n);
}