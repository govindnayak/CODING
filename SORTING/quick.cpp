#include<bits/stdc++.h>
using namespace std;

vector<int> a;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int left, int right)
{
	int pivot = a[right];
	
	int i = left-1;

	for(int c=left; c<right; c++)
	{
		if(a[c]<=pivot)
		{
			i++;
			swap(&a[c], &a[i]);
		}
	}
	swap(&a[i+1], &a[right]);

	return (i+1);
}

void quick_sort(int l, int r)
{
	if(l<r)
	{
		int p = partition(l, r);

		quick_sort(l, p-1);
		quick_sort(p+1, r);
	}
}

int main()
{
	int n, x;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>x;
		a.push_back(x);
	}

	quick_sort(0, n-1);

	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
}