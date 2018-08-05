#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void merge(int l, int mid, int r)
{
	int n1, n2;
	n1 = mid-l+1;
	n2 = r - mid;

	int left[n1], right[n2];
	
	int i=0, j=0;
	for(int k=l; k<=r; k++)
	{
		if(i<n1)
			left[i++] = a[k];
		else
			right[j++] = a[k];
	}

	i=0; j=0; int k=l;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{	
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		k++;
	}

	while(i<n1)
		a[k++] = left[i++];
	
	while(j<n2)
		a[k++] = right[j++];
}

void merge_sort(int l, int r)
{
	if(l<r)
	{
		int mid = (r+l)/2;
		merge_sort(l, mid);
		merge_sort(mid+1, r);

		merge(l, mid, r);
	}
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
	merge_sort(0, n-1);
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";	
}