#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>a[i][j];

    int dp[n+1][m+1] = {0};

    dp[0][0] = a[0][0];

    for(int i=1; i<n; i++)
        dp[i][0]= a[i][0]+dp[i-1][0];

    for(int i=1; i<m; i++)
        dp[0][i]= a[0][i] + dp[0][i-1];

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
  
                if(abs(a[i][j]+dp[i-1][j]) < abs(a[i][j]+dp[i][j-1]))
                    dp[i][j] = a[i][j]+dp[i-1][j];
                else
                    dp[i][j] = a[i][j]+dp[i][j-1];
        }
    }
    
    cout<<abs(dp[n-1][m-1])+1<<"\n";
    return 0;
} 