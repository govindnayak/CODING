#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	int d, m, y;
	cin>>d>>m>>y;

	if(m<3)
		y = y - m;
	int ans = (y + y/4 - y/100 + y/400 + a[m-1] + d)%7;
	cout<<ans<<"\n";
}