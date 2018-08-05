//One can go only right and bottom!

#include<bits/stdc++.h>
using namespace std;

int c=0;
int m, n;

int fun(int x, int y)
{
	if(x==m-1 || y==n-1)
		return 1;

	return (fun(x+1, y) + fun(x, y+1));
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;

		cout<<fun(0, 0);
	}
}