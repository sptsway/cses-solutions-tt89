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
vector<int> used;
set<pair<int,int>> ans;
vector<vector<int>> graph;

bool getDfs(int i) {
    if(used[i]) return false;
    used[i]=1;

    for(int j: graph[i]) {
        if(ans.find({j,i})!=ans.end()) continue;
        if(ans.find({i,j})!=ans.end()) continue;
        if(getDfs(j)) ans.insert({i,j});
        else ans.insert({j,i});
    }
    return true;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        used.resize(n+1,0);
        graph.resize(n+1);
        map<pair<int,int>,int> edge;
        for(int i=0;i<m;i++) {
            int a,b; cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            edge[{a,b}]++;
        }
        for(int i=1;i<=n;i++) if(!used[i]) getDfs(i);
        for(auto i: edge) {
            while (i.ss--) {
                if(ans.find({i.ff.ff,i.ff.ss})!=ans.end()) cout<<i.ff.ff<<" "<<i.ff.ss<<"\n";
                else cout<<i.ff.ss<<" "<<i.ff.ff<<"\n";
            }
        }
    }
    return 0;
}