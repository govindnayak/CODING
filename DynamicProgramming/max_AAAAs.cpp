//Only available options are Print A, ctrl A, ctrl C, ctrl V
//Last set of strokes have to be select, copy and paste...paste...
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin>>N;		//Given no. of key strokes

	if(N<=6)
	{
		cout<<N<<endl;
		exit(0);
	}

	int ans[N+1];

	for(int n=1; n<=6; n++)
		ans[n] = n;

	for(int n=7; n<=N; n++)
	{
		ans[n] = 0;

		for(int i=n-3; i>=1; i++)		//try all the possible break-points
		{
			int curr = (n-i-1)*ans[i];

			if(curr > ans[n])
				ans[n] = curr;
		}
	}

	cout<<ans[n]<<endl;
}