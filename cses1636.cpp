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

int n,x;
vector<int> arr,dp;

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>x;
        arr.resize(n);
        dp.resize(x+1,0);
        for(int &i: arr) cin>>i;

        dp[0]=1;
        for(int i: arr) {
            for(int j=0;j<=x;j++) {
                if(i+j<=x && dp[j]) dp[i+j]+=dp[j],dp[i+j]%=mod;

            }
        }
        cout<<dp[x];
    }
    return 0;
}