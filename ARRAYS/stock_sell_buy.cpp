//Can sell or buy any number of times
#include<bits/stdc++.h>
using namespace std;

typedef struct interval
{
	int sell, buy;
};

void stocks(int a[], int n)
{
	interval ans[n];

	int i=0, count=0;

	while(i<n-1)
	{
		while(i<n-1 && a[i]>=a[i+1])
			i++;

		ans[count].buy = i++;	//Local minima

		while(i<n && a[i]>=a[i-1])
			i++;

		ans[count].sell = i-1;	//Local maxima

		count++;
	}

	vector<int> result;		//may be if atmost 2 times!
	if(count==0)
		cout<<"No solution possible!\n";
	else
	{
		for(int i=0; i<count; i++)
		{
			cout<<a[ans[i].buy]<<" "<<a[ans[i].sell]<<"\n";
			result.push_back(a[ans[i].sell] - a[ans[i].buy]);
		}
	}
	sort(result.begin(), result.end(), greater<int>());
	for(auto iter: result)
		cout<<iter<<" ";
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	stocks(a, n);

	return 0;
}