//Just insert the element into the priority queue, it is in max_heap!

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int x, y, z, s;

	priority_queue<int> q;

	for(int i=0; i<n; i++)
	{
		cin>>s;
		q.push(s);

		if(q.size()<3)
			cout<<-1<<"\n";
		else
		{
			x = q.top();
			q.pop();

			y = q.top();
			q.pop();

			z = q.top();
			q.pop();

			cout<<x*y*z<<"\n";

			q.push(x);
			q.push(y);
			q.push(z);
		}
	}
}