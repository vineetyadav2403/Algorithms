//https://www.hackerrank.com/challenges/journey-to-the-moon/problem?isFullScreen=true

#include <bits/stdc++.h>

using namespace std;
int n,p;
void dfs(vector<int> a[],vector<bool> &visited, int i, set<int> &s){
    if(!visited[i]){
        visited[i] = true;
        s.insert(i);
        for(auto x: a[i]){
            dfs(a,visited,x,s);
        }
    }
}
int main()
{
    cin>>n>>p;
    vector<int> a[n];
    vector<bool> visited(n,false);
    set<int> s;
    s.clear();
    vector<int> comp;
    for(int i=0 ;i<p;i++){
        int x, y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        dfs(a,visited,i,s);
        if(s.size())
            comp.push_back(s.size());
        s.clear();
    }
    long long sum = 0;
    long long result = 0;
    for(int size : comp)
    {
        result += sum*size;
        sum += size;    
    }
    cout<<result<<endl;
    return 0;
}
