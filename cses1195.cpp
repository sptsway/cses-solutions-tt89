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

int n,m;
vector<int> used[2];
vector<vector<pair<int,int>>> graph;
//type 0 means half not done yet, 1means already done

int getDijkstra(int start,int end) {
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
    pq.push({{0,0},start});

    while (!pq.empty()) {
        auto a= pq.top(); pq.pop();
        int val= a.ff.ff, type= a.ff.ss, i=a.ss;
        if(used[type][i]<=val) continue;
        used[type][i]=val;
        if(i==end) continue;

        for(auto j: graph[i]) {
            if(type) pq.push({{val+j.ss,1},j.ff});
            else {
                pq.push({{val+j.ss,0},j.ff});
                pq.push({{val+j.ss/2,1},j.ff});
            }
        }
    }
    return min(used[0][n],used[1][n]);
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        graph.resize(n+1);
        used[0].resize(n+1,1e18); used[1].resize(n+1,1e18);
        for(int i=0;i<m;i++) {
            int a,b,c; cin>>a>>b>>c;
            graph[a].push_back({b,c});
        }
        cout<<getDijkstra(1,n);
    }
    return 0;
}