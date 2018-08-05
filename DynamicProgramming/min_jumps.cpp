//min jumps needed to reach the end of the array

#include<bits/stdc++.h>
using namespace std;

vector<int> a;
int n;

int recursion(int ind, int count)
{
	if(ind+a[ind]>=n)
	{
		flag = 1;
	}
	else
		return a[ind];

	int m = -1;

	for(int i=0; i<a[ind]; i++)
	{
		m = max(m, recursion(ind+1, count));
	}
	ind = m;

	if(flag==1)
		return count;
	
	count++;
}