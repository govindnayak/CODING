#include<bits/stdc++.h>
using namespace std;
#define MAX 1005

char a[MAX][MAX];
int n, m, d1, d2;
int cost[MAX][MAX];

typedef struct node
{
    int x, y;
};

int valid(int x, int y)
{
    if (x<=0 || y<=0 || x>n || y>n)     return 0;
    if(a[x][y]=='*' || cost[x][y]!=0)    return 0;
    else
    return 1;
}

void bfs(node s)
{
    queue<node> q;
    q.push(s);
    cost[s.x][s.y]=0;
    
    while(!q.empty())
    {
        node temp = q.front();
        q.pop();
        
        int x1=temp.x, y1=temp.y;

        if(valid(x1+1, y1))
        {
            node v;
            v.x = x1+1; v.y = y1;
            q.push(v);
            cost[x1+1][y1]=cost[x1][y1]+1;
        }
        if(valid(x1-1, y1))
        {
            node v;
            v.x = x1-1; v.y = y1;
            q.push(v);
            cost[x1-1][y1]=cost[x1][y1]+1;
        }
        if(valid(x1, y1+1))
        {
            node v;
            v.x = x1; v.y = y1+1;
            q.push(v);
            cost[x1][y1+1]=cost[x1][y1]+1;
        }
        if(valid(x1, y1-1))
        {
            node v;
            v.x = x1; v.y = y1-1;
            q.push(v);
            cost[x1][y1-1]=cost[x1][y1]+1;
        }
    }
}

int main()
{
    int q, x1, y1;
    cin>>n>>m>>q;
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>a[i][j];
    cin>>x1>>y1;
    
    node s;
    s.x=x1, s.y=y1;
    memset(cost,0,sizeof(cost));

    bfs(s);
    while(q--)
    {
        cin>>d1>>d2;
        if(cost[d1][d2]!=0)
            cout<<cost[d1][d2]<<"\n";
        else
            cout<<-1<<"\n";
    }
    
}   