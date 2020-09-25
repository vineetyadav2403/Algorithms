//https://www.hackerrank.com/challenges/bfsshortreach/problem?h_r%5B%5D%5B%5D%5B%5D%5B%5D=next-challenge&h_r%5B%5D%5B%5D%5B%5D%5B%5D=next-challenge&h_v%5B%5D%5B%5D%5B%5D%5B%5D=zen&h_v%5B%5D%5B%5D%5B%5D%5B%5D=zen&isFullScreen=false

#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> adj[n+1];
        int sp[n+1];
        for(int k=0;k<=n;k++) sp[k] = -1;
        for(int i=1;i<=m;i++){
            int x,y;
                cin>>x>>y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
        vector<bool> vis(n+1);
        for(int k=0;k<=n;k++) vis[k] = false;
        int p;
        cin>>p;
        queue<int> q;
        q.push(p);
        int count = 1;
        vis[p] = true;
        while(!q.empty()){
            
            int k = q.size();
            while(k--){
                int v = q.front();
                for(auto x:adj[v]){
                    if(!vis[x]){
                        vis[x] = true;
                        sp[x] = count * 6;
                        q.push(x);
                    }
                }
                q.pop();
            }
            
            count++;
        }
        for(int k=1;k<=n;k++){
            if(k!=p){
                cout<<sp[k]<<" ";
            }
        }
        cout<<endl;
    }

    
    return 0;
}
