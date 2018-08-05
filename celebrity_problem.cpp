#include<bits/stdc++.h>
using namespace std;

int a[20][20];

int knows(int x, int y)
{
	return a[x][y];
}

int celebrity(int n)
{
	stack<int> s;

	for(int i=0; i<n; i++)
		s.push(i);

	int A = s.top();	s.pop();
	int B = s.top(); 	s.pop();

	while(s.size()>1)
	{
		if(knows(A, B))
		{
			A = s.top();
			s.pop();
		}
		else
		{
			B = s.top();
			s.pop();
		}
	}

	int C = s.top(); 	s.pop();

	if(knows(C, B))
		C = B;
	if(knows(C, A))
		C = A;

	for(int i=0; i<n; i++)
	{
		if(i!=C && !knows(i, C) || knows(C, i))
			return -1;
	}
	return C;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>a[i][j];

	cout<<celebrity(n)<<"\n";	
}