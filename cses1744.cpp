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
vector<vector<int>> dp;

int getDp(int i,int j) {
    if(i==j) return 0;
    if(i==1 || j==1) return max(i-1,j-1);
    if(dp[i][j]!=-1) return dp[i][j];
    if(dp[j][i]!=-1) return dp[j][i];

    int ans=INT_MAX;
    for(int a=1;a<i;a++) ans=min(ans,getDp(a,j)+getDp(i-a,j)+1);
    for(int b=1;b<j;b++) ans=min(ans,getDp(i,b)+getDp(i,j-b)+1);
    dp[i][j]= ans;
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        int side=max(n,m);
        dp.resize(side+1,vector<int>(side+1,-1));
        cout<<getDp(n,m);
        clock;
    }
    return 0;
}