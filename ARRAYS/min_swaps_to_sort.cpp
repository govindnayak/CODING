
int minimumSwaps(vector<int> a) {
    
    int n = a.size();
    vector<bool> visited(n, false);
    pair<int, int> p[n];
    for(int i=0; i<n; i++)
    {
        p[i].first = a[i];
        p[i].second = i;
    }
    sort(p, p+n);
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(visited[i] || p[i].second==i)
            continue;
        int cycle_size = 0;
        int j=i;
        while(!visited[j])
        {
            visited[j]=true;
            j = p[j].second;
            cycle_size++;
        }
        ans+=(cycle_size-1);
    }
    return ans;
}
