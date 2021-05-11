//tt89 ;)
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define clock cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
void testcase(int t) { cout<<"Case #"<<t<<": "; }
void online() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}
const int mod= 1e9+7;

int n,m;
vector<int> arr;
vector<vector<int>> dp;

int getDp(int i,int prev) {
    if(i==n) return 1;
    if(dp[i][prev]!=-1) return dp[i][prev];
    if(arr[i] && abs(prev-arr[i])>1) return 0;
    if(arr[i]) return getDp(i+1,arr[i]);

    dp[i][prev]=getDp(i+1,prev);
    if(prev+1<=m) dp[i][prev]+= getDp(i+1,prev+1),dp[i][prev]%=mod;
    if(prev-1>0) dp[i][prev]+= getDp(i+1,prev-1),dp[i][prev]%=mod;
    return dp[i][prev];
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        arr.resize(n);
        dp.resize(n,vector<int>(m+1,-1));
        for(int &i: arr) cin>>i;
        int ans=0;
        if(!arr[0]) {
            for(int prev=1;prev<=m;prev++) ans+=getDp(1,prev),ans%=mod;
        } else ans= getDp(0,arr[0]);
        cout<<ans;
    }
    return 0;
}