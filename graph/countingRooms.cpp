#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

void solve() {
    int n,m;cin>>n>>m;
    vector<vector<int>> vc(n+2);
    vector<int> vis(n+2,0),dis(n+2,INF);

    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    dis[1]=0;
    vis[1]=true;
    while(!q.empty()){
        auto tp = q.front();q.pop();
        for(auto u:v[tp]){
            if(!vis[u]){
                q.push(u);
                if(dis[u]>dis[tp]+1){
                    dis[u]=dis[tp]+1;
                }
            }
        }
    }
    if(dis[n]==INF){
        cout<<"IMPOSSIBLE";
        return;
    }
    fill(vis.begin(),vis.end(),0);
    vector<int> ans;
    while(!q.empty()){
        q.pop();
    }
    q.push(n);
    while(!q.empty()){
        auto tp = q.front();q.pop();
        ans.push_back(tp);
        for(auto u: v[tp]){
            if(dis[u] == dis[tp]-1){
                q.push(u);
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto u:ans)cout<<u<<' ';cout<<'\n';
}

signed main () {
    int t=1;cin>>t;
    while(t--){
        solve();
    }
}
