#include<bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve() {
    int n,m;cin>>n>>m;
    vector<vector<int>> vc(n+5);
    vector<int> vis(n+5,0),col(n+5,0);

    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            q.push(i);
            vis[i]=true;
            col[i]=1;
            while(!q.empty()){
                auto tp = q.front();q.pop();
                for(auto u:vc[tp]){
                    if(!vis[u]){
                        vis[u]=true;
                        col[u] = 3-col[tp];
                        q.push(u);
                    }else if(col[u] == col[tp]){
                        cout<<"IMPOSSIBLE\n";
                        return;
                    }
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<col[i]<<' ';
    }
    cout<<'\n';
}

signed main() {
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}