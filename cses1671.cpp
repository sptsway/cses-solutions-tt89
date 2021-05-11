//tt89 ;)
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define clock cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
#define ff first
#define ss second
void testcase(int t) { cout<<"Case #"<<t<<": "; }
void online() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}
const int mod= 1e9+7;
const int inf = 1e15;

int n,m;
vector<int> dist;
vector<vector<pair<int,int>>> graph;

void getDijkstra(int source) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});

    while (!pq.empty()) {
        auto a= pq.top(); pq.pop();
        if(dist[a.ss]<=a.ff) continue;
        dist[a.ss]=a.ff;

        for(auto j: graph[a.ss]) {
            pq.push({a.ff+j.ss,j.ff});
        }
    }
//    for(int i=1;i<=n;i++) if(dist[i]==inf) dist[i]=-1;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        dist.resize(n+1,inf);
        graph.resize(n+1);
        for(int i=0;i<m;i++) {
            int a,b,c; cin>>a>>b>>c;
            graph[a].push_back({b,c});
//            graph[b].push_back({a,c});
        }
        getDijkstra(1);
        for(int i=1;i<=n;i++) cout<<dist[i]<<" ";

    }
    return 0;
}