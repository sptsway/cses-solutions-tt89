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

int n,m;
vector<bool> used;
vector<vector<int>> graph;

void getDfs(int i) {
    if(used[i]) return;
    used[i]=1;
    for(int j: graph[i]) getDfs(j);
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        used.resize(n+1);
        graph.resize(n+1);
        for(int i=0;i<m;i++) {
            int a,b; cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<pair<int,int>> v;
        for(int i=1;i<=n;i++) {
            if(!used[i]) {
                getDfs(i);
                if (i!= 1) v.push_back({i,i-1});
            }
        }
        cout<<v.size()<<"\n";
        for(auto i: v) cout<<i.ff<<" "<<i.ss<<"\n";
    }
    return 0;
}