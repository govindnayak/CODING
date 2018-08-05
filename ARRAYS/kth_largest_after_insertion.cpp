#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin>>n>>k;
	int a[n];
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
		if(i<k-1)
		{
			cout<<-1<<" ";
			if(i<=k-1)
				q.push(a[i]);
		}
	}
	cout<<q.top()<<" ";
	for(int i=k; i<n; i++)
	{
		int m = q.top();
		if(a[i]>m)
		{
			q.pop();
			q.push(a[i]);
			cout<<q.top()<<" ";
		}
		else
			cout<<m<<" ";
	}
}