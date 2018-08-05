//Make maximum profit

#include<bits/stdc++.h>
using namespace std;

typedef struct job
{
	int start, end, profit;
};

int compare(job a, job b)
{
	return (a.end<b.end);
}
//Get the latest job before index "ind"
int binary_search(job a[], int ind)
{
	int low = 0; int high = ind-1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		
		if(a[mid].end<=a[ind].start)
		{
			if(a[mid+1].end<=a[ind].start)		//Get the latest job before ind
				low = mid + 1;
			else
				return mid;
		}	
		else
			high = mid - 1;
	}
	return -1;
}

int schedule(job a[], int n)
{
	sort(a, a+n, compare);	//Sort based on end time

	int d[n] = {0};
	d[0] = a[0].profit;

	for(int i=1; i<n; i++)
	{
		int ans = a[i].profit;
		int ind = binary_search(a, i);

		if(ind!=-1)
			ans+=d[ind];
		
		d[i] = max(ans, d[i-1]);
	}
	return d[n-1];
}
int main()
{
	int n;
	cin>>n;
	job a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i].start>>a[i].end>>a[i].profit;
	}
	cout<<schedule(a, n)<<endl;
}