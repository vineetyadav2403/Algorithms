//https://www.hackerrank.com/challenges/synchronous-shopping/problem?h_r=next-challenge&h_v=zen&isFullScreen=false

#include <bits/stdc++.h>

using namespace std;
const int INF = 1000000000;
int n,m,k;
int x,y,z;
int dist[1000+10][1024 + 10];
int a[1000+10];

set<pair<int,pair<int,int>>> s;
vector<pair<int,int>> adj[1000+10];

inline void push(int vn,int vm,int vv){
    if(dist[vn][vm]<=vv)
        return;
    pair<int,pair<int,int>> mp = make_pair(dist[vn][vm],make_pair(vn,vm));
    if(s.find(mp)!=s.end())
        s.erase(s.find(mp));
    dist[vn][vm] = vv;

    mp.first = vv;

    s.insert(mp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    
    for(int i=1;i<=n;i++){
        int fish;
        cin>>fish;
        for(int j=1;j<=fish;j++){
            cin>>x;
            a[i]|=(1<<(x-1));
        }
    }
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<k);j++)
            dist[i][j] = INF;
    }
    push(1,a[1],0);

    while(s.size() > 0){
        int vn = s.begin()->second.first;
        int vm = s.begin()->second.second;
        s.erase(s.begin());
        for(int i=0;i<adj[vn].size();i++){
            push(adj[vn][i].first, vm | a[adj[vn][i].first],dist[vn][vm] + adj[vn][i].second);

        }
    }
    int ret = INF;
    for(int i=0;i<(1<<k);i++){
        for(int j=i; j< (1<<k);j++){
            if((i|j)==((1<<k) - 1)){
                ret = min(ret,max(dist[n][i],dist[n][j]));
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}
