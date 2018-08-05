//Using Ferment's little theorem 
//uses MODULAR EXPONENTIATION

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power(ll a, ll n, ll p) 	// a^n mod p using modular exponentitation!
{
	int res = 1;
	a = a % p;

	while(n>0)
	{
		if(n%2!=0)
			res = (res*a)%p;

		n = n/2;
		a = (a*a)%p;
	}
	return res;
}

int isPrime(ll n)
{
	if(n<=1 || n==4)
		return 0;
	if(n==2 || n==3)
		return 1;

	int k=3;
	while(k--)
	{
		ll a = 2 + rand()%(n-4);
		if(power(a, n-1, n)!=1)
			return 0;
	}
	return 1;
}

int main()
{
	int num;
	cin>>num;
	cout<<isPrime(num)<<endl;
	return 0;
}	