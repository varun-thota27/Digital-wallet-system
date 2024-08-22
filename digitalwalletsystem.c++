#include <bits/stdc++.h>
using namespace std;

int userIndex(const vector<pair<int,int>>& v, int id)
{
    for(int i=0;i<(int)v.size();i++)
    {
        if(v[i].first==id)
            return i;
    }
    return -1;
}

bool compare(const pair<int,int>& a, const pair<int,int>& b) 
{
    if(a.second==b.second)
        return a.first<b.first;
    else
        return a.second < b.second;
    
}

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int id,bal;
        cin>>id>>bal;
        v[i]={id,bal};
        mp[id]=bal;
    }
    
    int t;
    cin>>t;
    vector<string> status;
    while(t--)
    {
        int from,to,amt;
        cin>>from>>to>>amt;
        
        int fromIndex= userIndex(v,from);
        int toIndex=userIndex(v,to);
        
        if(fromIndex!=-1 && toIndex!=-1 && mp[from]>=amt)
        {
            mp[from]-=amt;
            mp[to]+=amt;
            status.push_back("Success");
        }
        else
            status.push_back("Failure");
    }
    
    for(const auto& x:status)
        cout<<x<<endl;
    cout<<endl;
    
    for(auto& x:v)
        x.second=mp[x.first];
    
    sort(v.begin(),v.end(),compare);
    
    for(const auto& x:v)
        cout<<x.first<<" "<<x.second<<endl;
    
    return 0;
}
