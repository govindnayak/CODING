#include<bits/stdc++.h>
using namespace std;

/*int coins(int a[], int n, int amt)
{
	if(amt==0)		//Has reached a solution
		return 1;

	if(amt<0)
		return 0;		//Not possible!

	if(amt>0 && n<=0)	//If no more coins left, amt is still left
		return 0;

	return coins(a, n-1, amt) + coins(a, n, amt-a[n-1]);
}*/
int coins(int a[], int n, int amt)
{
	int d[amt+1][n];

	for(int i=0; i<n; i++)
		d[0][i] = 1;

	for(int i=1; i<=amt ;i++)
	{
		for(int j=0; j<n; j++)
		{
			int x, y;

			if(i-a[j]<0)
				x = 0;
			else
				x = d[i-a[j]][j];

			if(j<=0)
				y = 0;
			else
				y = d[i][j-1];

			d[i][j] = x+y;
		}
	}
	return d[amt][n-1];
}

int main()
{
	int n, amt;
	cin>>n>>amt;
	int a[n+1];
	for(int i=0; i<n; i++)
		cin>>a[i];

	cout<<coins(a, n, amt)<<endl;
}