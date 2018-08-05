//Find min number of operations to convert string 1 to string 2 (insert, delete, replace)
//Remember it's not a simple set difference operation. It's DP!

#include<bits/stdc++.h>
using namespace std;
/*
int recursion(string s1, string s2, int m, int n)
{
	if(m==0)
		return n;
	if(n==0)
		return m;
	if(s1[m-1]==s2[n-1])
		return recursion(s1, s2, m-1, n-1);

	return 1+min(recursion(s1, s2, m-1, n), recursion(s1, s2, m, n-1), recursion(s1, s2, m-1, n-1));
}
*/
int dynamic(string s1, string s2, int m, int n)
{
    int d[m+1][n+1];
    
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0)
                d[i][j] = j;
            else if(j==0)
                d[i][j] = i;
            else if(s1[i-1]==s2[j-1])
                d[i][j] = d[i-1][j-1];
            
            else
                d[i][j] = 1 + min(d[i-1][j-1], d[i][j-1], d[i-1][j]);
        }
    }
    return d[m][n];
}