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
const int mod= 2e9+14;

int n,sum;
vector<vector<int>> dp;

int getDp(int i,int x) {
    if(x<0) return 0;
    if(x>i*(i+1)/2) return 0;
    if(i==0) return x==0;
    if(dp[i][x]!=-1) return dp[i][x];
    dp[i][x]= getDp(i-1,x) + getDp(i-1,x-i);
    dp[i][x]%=mod;
    return dp[i][x];
}

int solve() {
    sum=n*(n+1)/2;
    if(sum%2) return 0;
    dp.resize(n+1,vector<int>(sum/2+1,-1));
    return getDp(n,sum/2);
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        cout<<solve()/2;
    }
    return 0;
}