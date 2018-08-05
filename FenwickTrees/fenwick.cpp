#include<bits/stdc++.h>
using namespace std;
int bit[100], n;

void update(int i, int val)
{
	while(i<=n)
	{
		bit[i]+=val;
		i+= i & (-i);
	}
}

int sum(int i)
{
	int sums = 0;
	while(i>0)
	{
		sums+=bit[i]; 
		i-= i & (-i);
	}
	return sums;
}

int get_sum(int i, int j)
{
	return (sum(j) - sum(i-1));
}

int main()
{
	int x, beg, end;
	int a[] = {1,2,3,4,5,6};
	n = 6;

	for(int i=1;i<=n;i++)
	{
		update(i, a[i-1]);
	}
	cout<<"Fenwick: ";
	for(int i=1;i<=n;i++)
		cout<<bit[i]<<" ";

	cout<<endl<<sum(4)<<endl;
	cout<<get_sum(1, 6)<<endl;

}