//Govt is worried about citizens. So no of types of N day plan!
//Very efficient fibonacci implementation!

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007

ll ans[2] = {0};
ll a, b, c, d;

void fast_fib(ll n)
{
	if(n==0)
	{
		ans[0] = 0;
		ans[1] = 1;
		return;
	}

	fast_fib(n/2);

	a = ans[0]; 	
	b = ans[1];
	c = 2*b - a;

	if(c<0)
		c+=MOD;

	c = (a*c)%MOD;
	d = (a*a + b*b)%MOD;

	if(n%2==0)
	{
		ans[0] = c;
		ans[1] = d;
	}
	else
	{
		ans[0] = d;
		ans[1] = c+d;
	}
}

int main()
{
	ll n;
	cin>>n;
	a = 0, b = 0, c = 0, d = 0;

	fast_fib(n);
	printf("%lld\n", ans[1]%MOD);

	return 0;
}