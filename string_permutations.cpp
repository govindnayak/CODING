#include<bits/stdc++.h>
using namespace std;

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permute(string s, int l, int r)
{
	if(l==r)
		cout<<s<<"\n";
	else
	{
		for(int i=l; i<=r; i++)
		{
			swap(s[l], s[i]);
			permute(s, l+1, r);
			swap(s[l], s[i]);
		}
	}
}

int main()
{
	string s;
	cin>>s;
	permute(s, 0, s.length()-1);
}