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
const int neg_inf= -1e15;

int n,m;
vector<pair<int,pair<int,int>>> edge;
vector<vector<int>> graph;
vector<int> arr,used,par;
unordered_set<int> s;

void getPhase() {
    for(int i=0;i<m;i++) {
        if(arr[edge[i].ff]!=neg_inf) {
            if(arr[edge[i].ss.ff] < arr[edge[i].ff]+edge[i].ss.ss) {
                arr[edge[i].ss.ff]= arr[edge[i].ff]+edge[i].ss.ss;
                par[edge[i].ss.ff]=edge[i].ff;
            }
        }
    }
}

bool getPhaseFinal() {
    for(int i=0;i<m;i++) {
        if(arr[edge[i].ff]!=neg_inf) {
            if(arr[edge[i].ss.ff] < arr[edge[i].ff]+edge[i].ss.ss) {
                arr[edge[i].ss.ff]= arr[edge[i].ff]+edge[i].ss.ss;
                s.insert(edge[i].ss.ff);
                par[edge[i].ss.ff]=edge[i].ff;
            }
        }
    }
    return !s.empty();
}

bool getDfs(int i,int chk) {
    if(i==chk) return true;
    if(used[i]) return false;
    used[i]= true;

    bool ans= false;
    for(int j: graph[i]) {
        ans=ans|getDfs(j,chk);
    }
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        arr.resize(n+1,neg_inf);
        par.resize(n+1,0);
        used.resize(n+1,0);
        graph.resize(n+1);
//        used.resize(n+1,-1);
        for(int i=0;i<m;i++) {
            int a,b,c; cin>>a>>b>>c;
            edge.push_back({a,{b,c}});
            graph[a].push_back(b);
        }
        arr[1]=0;
        for(int i=0;i<n-1;i++) getPhase();
        if(getPhaseFinal()) {
//            cerr<<"YES\n";
            for(int i=0;i<n;i++) {
                unordered_set<int> temp;
                for(int j: s) temp.insert(par[j]);
                s= temp;
            }
//            for(int i: s) cerr<<i<<" ";
            for(int i: s) {
                used.clear(); used.resize(n+1,0);
                if(getDfs(1,i)) {
                    used.clear(); used.resize(n+1,0);
                    if(getDfs(i,n)) arr[n]=-1;
                }
            }
            cout<<arr[n];
        }else cout<<arr[n];
    }
    return 0;
}