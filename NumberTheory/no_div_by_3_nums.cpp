//Find the smallest n-digit number divisible by all the 3 numbers a,b,c!

#include<bits/stdc++.h>
using namespace std;

int LCM(int a, int b, int c)
{
	int ans = (a*b)/(__gcd(a, b));
	return (ans*c)/(__gcd(ans, c));
}
int compute(int n, int a, int b, int c)
{
	int lcm = LCM(a, b, c);
	int d = pow(10, n-1); 	//smallest n-digit number

	int rem = d%(lcm);

	if(rem==0)
		return d;

	d = d + (lcm-rem);

	//check if the number stays n-digit only
	if(d<pow(10, n))
		return d;
	else
		return -1;
}
int main()
{
	int n, a, b, c;
	cin>>a>>b>>c>>n;
	cout<<compute(n, a, b, c)<<"\n";
}
