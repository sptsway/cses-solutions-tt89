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
vector<int> ans,used;
vector<vector<int>> graph;

void getDfs(int i,int p,int &b) {
    if(used[i]) {
        ans.push_back(i);
        b= 1;
        return;
    }used[i]=1;

    for(int j: graph[i]) {
        if(j==p) continue;
        getDfs(j,i,b);
        if(b==-1) return;
        else if(b==1) {
            ans.push_back(i);
            if(i==ans[0]) b=-1;
            return;
        }
    }
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        used.resize(n+1,0);
        graph.resize(n+1);
        for(int i=0;i<m;i++) {
            int a,b; cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=1;i<=n;i++) {
            if(used[i]) continue;
            int b= 0; getDfs(i,0,b);
            if(ans.size()) break;
        }
        if(ans.empty()) cout<<"IMPOSSIBLE";
        else {
            cout<<ans.size()<<"\n";
            for(int i: ans) cout<<i<<" ";
        }
    }
    return 0;
}