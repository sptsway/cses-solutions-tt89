//tt89 ;)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
// find_by_order(k)--> returns iterator at index k
// odered_of_key(k)--> returns no. of elem stricktly less than k
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

int n,m,k;
vector<multiset<int>> used;
vector<vector<pair<int,int>>> graph;

void getKDijkstra() {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    while (!pq.empty()) {
        auto a= pq.top(); pq.pop();
        if(used[a.ss].size()<k) used[a.ss].insert(a.ff);
        else if(*used[a.ss].rbegin()>a.ff) {
            int x= *used[a.ss].rbegin();
            used[a.ss].erase(used[a.ss].find(x));
            used[a.ss].insert(a.ff);
        }else continue;
        for(auto j: graph[a.ss]) pq.push({a.ff+j.ss,j.ff});
    }
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m>>k;
        graph.resize(n+1);
        used.resize(n+1);
        for(int i=0;i<m;i++) {
            int a,b,c; cin>>a>>b>>c;
            graph[a].push_back({b,c});
        }
        getKDijkstra();
        for(int i: used[n]) cout<<i<<" ";
    }
    return 0;
}