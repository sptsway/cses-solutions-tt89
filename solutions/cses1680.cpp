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
vector<int> ans,child,used;
vector<vector<int>> graph;

int getDfs(int i) {
    if(i==1) { used[i]=1; return 1; }
    if(used[i]!=INT_MIN) return used[i];
    int mx=0;
    for(int j: graph[i]) {
        if(mx<getDfs(j)) mx=used[j],child[i]=j;
    }
    if(mx) used[i]=mx+1;
    else used[i]--;
    return used[i];
}

bool solve() {
    int cur=n;
    getDfs(n);
    if(used[1]<0) return 0;
    while (cur) {
        ans.push_back(cur);
        cur=child[cur];
    }
    reverse(ans.begin(),ans.end());
    return 1;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        used.resize(n+1,INT_MIN);
        child.resize(n+1,0);
        graph.resize(n+1);
        for(int i=0;i<m;i++) {
            int a,b; cin>>a>>b;
            graph[b].push_back(a);
        }
        if(solve()) {
            cout<<ans.size()<<"\n";
            for(int i: ans) cout<<i<<" ";
        } else cout<<"IMPOSSIBLE\n";
    }
    return 0;
}