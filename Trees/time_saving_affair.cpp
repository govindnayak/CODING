#include <bits/stdc++.h>

using namespace std;
#define MAX 10005
long leastTimeToInterview(int n, int k, int m) 
{
    vector<pair<int, int>> a[MAX];
    long visited[MAX], d[MAX], parent[MAX];
    fill(d, d+MAX, INT_MAX);  fill(visited, visited+MAX, 0);
    for(int i=0; i<m; i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        a[x].push_back({w, y});
        a[y].push_back({w, x});
    }
    
    multiset<pair<int, int>> s;
    s.insert({0, 1});
    d[1] = 0;
    
    while(!s.empty())
    {
        pair<int, int> p = *s.begin();
        s.erase(s.begin());
        
        int i = p.second;
        if(visited[i])
            continue;
        visited[i]=1;
        
        for(int j=0; j<a[i].size(); j++)
        {
            int node = a[i][j].second;
            int w = a[i][j].first;
            
            if(d[node]>d[i]+w)
            {
                d[node] = d[i]+w;
                /////////////////////////////
                if(d[node]/k%2!=0 && node!=n)
                    d[node]+=k-d[node]%k;
                /////////////////////////////
                s.insert({d[node], node});
            }
        }
    }
    return d[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = leastTimeToInterview(n, k, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
