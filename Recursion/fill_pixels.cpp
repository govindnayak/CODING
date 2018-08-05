#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
int m, n;

void fill_pixels(int x, int y, int oldp, int newp)	//replace x with y
{
	if(x<0 || x>=m || y<0 || y>=n)
		return;

	if(a[x][y]==oldp)
		a[x][y]=newp;
	else
		return;

	fill_pixels(x+1, y, oldp, newp);
	fill_pixels(x, y+1, oldp, newp);
	fill_pixels(x, y-1, oldp, newp);
	fill_pixels(x-1, y, oldp, newp);
}

int main()
{
	int s,x1,y1;
	cin>>m>>n;
	cin>>x1>>y1;
	for(int i=0; i<m; i++)
	{
		vector<int> temp;
		for(int j=0; j<n; j++)
		{
			cin>>s;
			temp.push_back(s);
		}
		a.push_back(temp);
	}
	fill_pixels(x1, y1, a[x1][y1], 7);
	cout<<endl<<endl;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

}