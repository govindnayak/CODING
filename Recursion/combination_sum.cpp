//This is like DFS!

#include<bits/stdc++.h>
using namespace std;

vector<int> a;
vector<vector<int>> result;
vector<int> ans;

void combination(int sum, int ind)
{
	if(sum==0)
	{
		result.push_back(ans);
		return;
	}

	for(int i=ind; i<a.size(); i++)
	{
		if(a[i]>sum)
			break;

		ans.push_back(a[i]);
		combination(sum-a[i], i);
		ans.erase(ans.end()-1);		//pop_back to BACKTRACKING!
	}
}


int main()
{
	int n, sum;

	cin>>n;
	for(int i=0; i<n; i++)
	{
		int x; cin>>x; 
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	cin>>sum;
	combination(sum, 0);

	for(auto i: result)
	{
		for(auto j: i)
			cout<<j<<" ";
		cout<<endl;
	}
}