#include<bits/stdc++.h>
using namespace std;

string ans;

void compute(string s, int k)
{
	if(k==0)
		return;
	int n = s.length();

	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(s[i]<s[j])
			{
				swap(s[i], s[j]);
			
				if(s.compare(ans)>0)
					ans = s;

				compute(s, k-1);

				swap(s[i], s[j]);		//Backtracking
			}
		}
	}
}

int main()
{
	string s; int k;
	cin>>s>>k;
	ans = s;
	compute(s, k);
	cout<<ans<<"\n";
}