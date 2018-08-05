#include<bits/stdc++.h>
using namespace std;

int n, m=-1000;
vector<int> a;

void counting()
{
	int ans[n];

	int count[9+1];
	memset(count, 0, sizeof(count));

	for(int i=0; i<n; i++)
		count[a[i]]++;

	for(int i=1; i<=9; i++)
		count[i]+=count[i-1];

	for(int i=0; i<n; i++)
	{
		ans[count[a[i]]-1] = a[i];
		count[a[i]]--;
	}

	for(int i=0; i<n; i++)
		a[i] = ans[i];
}

int main()
{
	int x;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>x;
		a.push_back(x);
	}
	counting();
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
}