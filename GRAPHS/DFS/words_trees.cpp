//print minimum number of characters to be added to T , so that the we can 
//build S using some characters of string T 
//TRY USING 2-D ARRAY FOR STORING VALUES
#include<bits/stdc++.h>
using namespace std;

vector<int> a[100005];
int visited[100005];
char values[100005];
int d[100005][26];		//Use a table to store count of all chars. for a specific node as root

void dfs(int i)
{
	visited[i]=1;
	d[i][values[i]-97]++;

	for (int k=0; k<a[i].size(); k++)
	{
		int s = a[i][k];
		
		if(!visited[s])
		{   
		    dfs(s);

		    for(int j=0; j<26; j++)
			d[i][j]+=d[s][j];
		}
	}
}

int main()
{
	int n,q,x,y;
	cin>>n>>q;

	for(int i=1; i<=n; i++)
		cin>>values[i];
	for(int i=0; i<n-1; i++)
	{
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1);
	while(q--)
	{
		int X, ans=0; string S;
		cin>>X;
		cin>>S;
		int l = S.length();
		int count[26]={0};
		
		for(int i=0; i<l; i++)
			count[S[i]-97]++;
	
		for(int i=0; i<26; i++)
			ans+=(max(0, count[i]-d[X][i]));
		cout<<ans<<endl;
	}

}