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

int getDiameter(int i,int p,int &ans) {
    int mx1=0,mx2=0;
    for(int j: tree[i]) {
        if(j!=p) {
            int y= getDiameter(j,i,ans);
            if(y>mx1) mx2=mx1, mx1=y;
            else if(y>mx2) mx2=y;
        }
    }
    ans= max(ans,mx1+mx2);
    return mx1+1;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        tree.resize(n+1);
        for(int i=1;i<n;i++) {
            int a,b; cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        int ans=0;
        getDiameter(1,0,ans);
        cout<<ans;
    }
    return 0;
}