//tt89 ;)
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void testcase(int t) { cout<<"Case #"<<t<<": "; }
void online() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}
const int mod= 1e9+7;

int n;
vector<vector<int>> tree1,tree2;
map<pair<int,int>,int> m;

int getDfs1(int i,int p) {
    int s=0,c=1;
    for(int j: tree1[i]) {
        if(j!=p) s++,c+=getDfs1(j,i);
    } m[{s,c}]++;
    return c;
}

int getDfs2(int i,int p) {
    int s=0,c=1;
    for(int j: tree2[i]) {
        if(j!=p) s++,c+=getDfs2(j,i);
    } m[{s,c}]--;
    return c;
}

bool getIso() {
    for(auto i: m) {
//        cout<<i.first<<"@"<<i.second<<" ";
        if(i.second!=0) return false;
    }
    return true;
}

signed main() {
    fastIO;
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        m.clear();
        tree1.clear(); tree1.resize(n+1);
        tree2.clear(); tree2.resize(n+1);
        for(int i=1;i<n;i++) {
            int a,b; cin>>a>>b;
            tree1[a].push_back(b);
            tree1[b].push_back(a);
        }for(int i=1;i<n;i++) {
            int a,b; cin>>a>>b;
            tree2[a].push_back(b);
            tree2[b].push_back(a);
        }
        getDfs1(1,0);
        getDfs2(1,0);
        if(getIso()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}