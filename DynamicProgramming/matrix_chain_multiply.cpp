#include<bits/stdc++.h>
using namespace std;

int compute(int a[], int i, int j)
{
	if(i==j)
		return 0;

	int count, ans = INT_MAX;

	for(int k=i; k<j; k++)
	{
		count = compute(a, i, k) + compute(a, k+1, j) + a[i-1]*a[j]*a[k];
		ans = min(ans, count);
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<compute(a, 1, n-1)<<"\n";
}