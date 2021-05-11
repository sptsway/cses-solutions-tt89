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

const int N=1001;
int n,dp[N][N];
char arr[N][N];

int getDp(int i,int j) {
    if(i<0 || j<0 || i==n || j==n) return 0;
    if(i==n-1 && j==n-1) return arr[i][j]=='.';
    if(arr[i][j]=='*') return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]= getDp(i+1,j) + getDp(i,j+1);
    dp[i][j]%=mod;
    return dp[i][j];
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
        cout<<getDp(0,0);
    }
    return 0;
}