#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void heapify(int a[], int i, int n)
{
	int largest = i;
	int left = 2*i;
	int right = 2*i+1;

	if(left<n && a[left]>a[largest])
		largest = left;
	if(right<n && a[right]>a[largest])
		largest = right;

	if(i!=largest)
	{
		swap(&a[i], &a[largest]);
		heapify(a, largest, n);
	}
}

void heap_sort(int a[], int n)
{
	for(int i=n/2; i>=1; i--)	//Only all the internal nodes!
		heapify(a, i, n);

	for(int i=n; i>=1; i--)
	{
		swap(&a[i], &a[1]); 	//Send max root to the end of the array!
		heapify(a, 1, i);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1; i<=n; i++)
		cin>>a[i];
	heap_sort(a, n);

	for(int i=1; i<=n; i++)
		cout<<a[i]<<" ";
}