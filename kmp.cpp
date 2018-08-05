//Knuth-Morries-Pratt 
#include<bits/stdc++.h>
using namespace std;
int table[20];

void build_table(string s, int m)
{
	int j=0, i=1;
	table[0] = 0;

	while(i<m && j<i)
	{
		if(s[i]==s[j])
		{
			table[i] = j + 1;
			i++; j++;
			continue;
		}
		else
		{
			if(j==0)
			{
				table[i] = 0;
				i++;
				continue;
			}
			else
			{
				j = table[j-1];
			}
		}
	}
	for(int i=0; i<m; i++)
		cout<<table[i]<<" ";
}
int kmp(string s, string p, int n, int m)
{
	int j = 0, flag = -1;
	for(int i=0; i<n; i++)
	{
		if(s[i]==p[j])
		{
			j++;
		}
		else
		{
			if(j!=0)
				j = table[j-1];
			else
				continue;
		}
	}
	if(j==m)
		return 1;
	else
		return 0;
}
int main()
{
	string s, p;
	cin>>s>>p;
	int m = p.length(), n = s.length(); 
	int table[m];
	build_table(p, m);
	cout<<kmp(s, p, n, m)<<"\n";
}