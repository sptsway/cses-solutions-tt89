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
vector<vector<int>> tree; 
map<pair<int,int>,int> dp;

int getDp(int i,int p) {
    int c=1;
    for(int j: tree[i]) {
        if(j!=p) {
            int x= getDp(j,i);
            dp[{i,j}]=x;
            c+= x;
        }
    }
    return c;
}

int getAns() {
    for(int i=1;i<=n;i++) {
        bool ans= true;
        for(int j: tree[i]) {
            if(dp.find({i,j})!=dp.end()) {
                if(dp[{i,j}]>n/2) { ans=false; break; }
            }else {
                if(n-dp[{j,i}]>n/2) { ans=false; break; }
            }
        }
        if(ans) return i;
    }
    return 0;
}

signed main() {
    fastIO;
    int T=1;
    // cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        tree.resize(n+1);
        for(int i=1;i<n;i++) {
            int a,b; cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        getDp(1,0);
        cout<<getAns();
    }
    return 0;
}