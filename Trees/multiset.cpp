#include<bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> a;
    multiset<int>:: iterator iter;
    map<int, int> d;
    int q;
    cin>>q;
    while(q--)
    {
        int x, y;
        cin>>x;
        
        if(x==1)    //insert given y
        {
            cin>>y;
            a.insert(y);
            if(!d.count(y))
                d[y] = 1;
            else
                d[y]++;
        }
        
        else if(x==2)   //delete given y
        {
            cin>>y;
            if(d.count(y))
            {
                d[y]--;
                iter = a.find(y);
                a.erase(iter);
                if(d[y]==0)
                    d.erase(y);
            }
            else
                cout<<-1<<"\n";
        }
        
        else if(x==3)   //Find max element
        {
            if(!a.empty())
                cout<<*a.rbegin()<<"\n";
            else
                cout<<-1<<"\n";
        }
        
        else            //Find min element
        {
            if(!a.empty())
                cout<<*a.begin()<<"\n";
            else
                cout<<-1<<"\n";
        }
    }
}