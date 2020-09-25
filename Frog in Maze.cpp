#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
int n,m,k;
int succ=0,fail = 0;
pair<int,int> tunnel[21][21];
void dfs(vector<vector<char>> &adj,vector<vector<bool>> &vis,int i,int j){
    if(i>=0&&i<n&&j>=0&&j<m&&!vis[i][j]){
        if(adj[i][j]=='%'){
            succ++;
            return;
        }else if(adj[i][j]=='*'){
            vis[i][j]= true;
            adj[i][j] = k;
            fail++;
            return;
        }else if(adj[i][j]=='#'){
            vis[i][j] = true;
            return;
        }else if(adj[i][j]=='t'){
            vis[i][j] = true;
            if(!vis[tunnel[i][j].first][tunnel[i][j].second]){
                dfs(adj,vis,tunnel[i][j].first,tunnel[i][j].second);
                dfs(adj,vis,i+1,j);
                dfs(adj,vis,i-1,j);
                dfs(adj,vis,i,j+1);
                dfs(adj,vis,i,j-1);
            }
            
        }else{
            vis[i][j]=true;
            dfs(adj,vis,i+1,j);
            dfs(adj,vis,i-1,j);
            dfs(adj,vis,i,j+1);
            dfs(adj,vis,i,j-1);
            //fail++;
        }

    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    vector<vector<char>> adj(n,vector<char>(m+1,'\0'));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    cin>>ws;
    FOR(i,n)FOR(j,m) cin>>adj[i][j];
    int x,y;
    FOR(i,n){
        for(int j=0;adj[i][j]!='\0';j++){
            if(adj[i][j]=='A'){
                x = i; 
                y = j;
            }
        }
    }
    for(int i=0;i<k;i++){
        int tx1,tx2,ty2,ty1;
        cin>>tx1>>ty1>>tx2>>ty2;
        
        tunnel[tx1-1][ty1-1].first = tx2-1;
        tunnel[tx1-1][ty1-1].second = ty2-1;
        tunnel[tx2-1][ty2-1].first = tx1-1;
        tunnel[tx2-1][ty2-1].second = ty1-1;
        adj[tx1-1][ty1-1] = 't';
        adj[tx2-1][ty2-1] = 't';
    } 
   // cout<<k;
    dfs(adj,vis,x,y);
    if(succ){
        float t = (float)succ/(succ+fail);
        cout<<succ<<fail<<endl;
    }else{
        cout<<0<<endl;
    }
    

    FOR(i,n){
        FOR(j,m)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }
    // FOR(i,n){
    //     FOR(j,m)
    //         cout<<tunnel[i][j].second<<" ";
    //     cout<<endl;
    // }
    return 0;
}
