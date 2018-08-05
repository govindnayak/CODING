#include<bits/stdc++.h>
using namespace std;

int getSum(int bit[], int i)
{
	int sum=0;
	while(i>0)
	{
		sum+=bit[i];
		i-=(i&(-i));
	}
	return sum;
}

void update(int bit[], int i, int val, int n)
{
	while(i<=n)
	{
		bit[i]+=val;
		i+=(i&(-i));
	}
}

int main()
{
	int n, max_ele=INT_MIN;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
		if(a[i]>max_ele)
			max_ele = a[i];
	}
	int bit[max_ele+1]={0};
	int ans = 0;
	for(int i=n-1; i>=0; i--)
	{
		ans+=getSum(bit, a[i]-1);
		update(bit, a[i], 1, max_ele);
	}
	cout<<ans<<endl;
}