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
const int inf = 1e15;

int n,x;
vector<int> w,v,dp;

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>x;
        w.resize(n); v.resize(n);
        int sum=0;
        for(int &i: w) cin>>i;
        for(int &i: v) cin>>i,sum+= i;
        dp.resize(sum+1,inf);
        dp[0]=0;

        for(int i=0;i<n;i++) {
            for(int j= sum;j>=v[i];j--) {
                dp[j]= min(dp[j],dp[j-v[i]]+w[i]);
            }
        }
        int ans=0;
        for(int i=sum;i>=0;i--) {
            if(dp[i]<=x) { ans=i;break; }
        }
        cout<<ans;
    }
    return 0;
}