#include<bits/stdc++.h>
using namespace std;

bool isAdjacent(string &a, string &b)
{
	int c = 0;
	for(int i=0; i<a.length(); i++)
	{
		if(a[i]!=b[i])
			c++;
	}
	if(c==1)
		return true;
	else
		return false;
}
int bfs(string &start, string &end, set<string> &d)
{
	queue<pair<string, int>> q;
	q.push(make_pair(start, 1));

	while(!q.empty())
	{
		pair<string, int> p = q.front(); q.pop();
		string s = p.first;
		int level = p.second;

		for(auto iter: d)
		{
			string a = iter;
			if(isAdjacent(s, a))
			{
				q.push(make_pair(a, level+1));
				//cout<<a<<" "<<level+1<<endl;
				d.erase(iter);
				if(a==end)
					return level+1;
			}
		}
	}
	return 0; 
}
int main()
{
	set<string> d;
	d.insert("poon");
	d.insert("plee");
	d.insert("same");
	d.insert("poie");
	d.insert("poin");
	d.insert("plea");
	string start = "toon";
	string end = "plea";
	cout<<bfs(start, end, d)<<"\n";			
}