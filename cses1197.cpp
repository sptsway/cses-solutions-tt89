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
const int inf= 1e15;

int n,m;
vector<pair<int,pair<int,int>>> edge;
vector<int> arr,used,par;

int getPhase() {
    int phase= -1;
    for(int i=0;i<m;i++) {
//        if(arr[edge[i].ff]!=inf) {
            if(arr[edge[i].ss.ff] > arr[edge[i].ff]+edge[i].ss.ss) {
                arr[edge[i].ss.ff]= arr[edge[i].ff]+edge[i].ss.ss;
                phase= edge[i].ss.ff;
                par[edge[i].ss.ff]=edge[i].ff;

//                cout<<i<<"@ ";
            }
//        }
    }
    return phase;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        arr.resize(n+1,inf);
        par.resize(n+1);
//        used.resize(n+1,-1);
        for(int i=0;i<m;i++) {
            int a,b,c; cin>>a>>b>>c;
            edge.push_back({a,{b,c}});
        }
//        arr[1]=0;
        int x=-1;
        for(int i=0;i<n;i++) x=getPhase();
//        cout<<x<<"@";
        if(x!=-1) {
            cout<<"YES\n";
            for(int i=0;i<n;i++) x= par[x];
            vector<int> ans={x};
            int cur= x;
            while (true) {
                if(cur==x && ans.size()>1) break;
                cur=par[cur];
                ans.push_back(cur);
            }
            reverse(ans.begin(),ans.end());
            for(int i: ans) cout<<i<<" ";
        }else cout<<"NO\n";
    }
    return 0;
}