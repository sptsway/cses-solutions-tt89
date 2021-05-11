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

int n;
vector<int> dp;

int getDp(int x) {
    if(!x) return 0;
    if(dp[x]!=-1) return dp[x];
    int num=x,ans=INT_MAX;

    while (num) {
        if(num%10!=0) ans= min(ans,getDp(x-num%10)+1);
        num/=10;
    }
    dp[x]=ans;
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        dp.resize(n+1,-1);
        cout<<getDp(n);
//        clock
    }
    return 0;
}