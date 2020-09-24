#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
int n,m, lib,road;
void dfs(vector<int> a[],vector<bool> &visited,set<int> &s,int &i){
    if(!visited[i]){
        visited[i] = true;
        s.insert(i);
        for(auto j:a[i]){
            dfs(a, visited,s,j);
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int cost = 0;
        cin>>n>>m>>lib>>road;
        vector<int> a[n+1];
        vector<bool> visited(n+1,false);
        set<int> s;
        FOR(i,m){
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for(int i=1;i<=n;i++){
            dfs(a,visited,s,i);
            if(s.size()!=0){
                if(road < lib)
                    cost +=(road*(s.size() - 1))+lib;
                else
                    cost = cost + (lib *(s.size() - 1))+lib;
            }
            s.clear();
        }
        cout<<cost<<endl;
    }
    return 0;
}
