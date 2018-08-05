#include<bits/stdc++.h>
using namespace std;

int count(string s)
{
	map<string, int> d;

	for(int i=0; i<s.length(); i++)
	{
		//Odd length substrings palindrome

		for(int j=0; j<=i; j++)
		{
			if(!s[i+j])
				break;
			if(s[i-j]==s[i+j])
			{
				if((i+j+1) - (i-j) > 1)
					d[s.substr(i-j, (i+j+1)-(i-j))]++;
			}
			else
				break;
		}

		//Even length substrings palindrome

		for(int j=0; j<=i; j++)
		{
			if(!s[i+j+1])
				break;
			if(s[i-j]==s[i+j+1])
			{
				if((i+j+2) - (i-j) > 1)
					d[s.substr(i-j, (i+j+2)-(i-j))]++;
			}
			else
				break;
		}
	}
	for(auto iter: d)
		cout<<iter.first<<" "<<iter.second<<"\n";
	return d.size();
}

int main()
{
	string s;
	cin>>s;

	cout<<count(s);
}