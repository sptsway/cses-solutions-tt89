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

pair<bool,int> getDfs(int i,int p) {
    bool b= false;
    int c=0;
    for(int j: tree[i]) {
        if(j!=p) {
            pair<bool,int> x= getDfs(j,i);
            c+= x.second; b= b||x.first;
        }
    }
    if(!b) return {true,c};
    return {false,c+1};
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
        pair<int,int> ans=getDfs(1,0);
        cout<<ans.second;
    }
    return 0;
}