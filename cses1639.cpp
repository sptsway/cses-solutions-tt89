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

int n,m;
string a,b;
vector<vector<int>> dp;

int getDp(int i,int j) {
    if(i==n || j==m) return max(n-i,m-j);
    if(dp[i][j]!=-1) return dp[i][j];

    if(a[i]==b[j]) dp[i][j]= getDp(i+1,j+1);
    else dp[i][j]= min(getDp(i+1,j+1),min(getDp(i+1,j),getDp(i,j+1)))+1;
    return dp[i][j];

}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>a>>b;
        n= a.length(); m=b.length();
        dp.resize(n,vector<int>(m,-1));
        cout<<getDp(0,0);
    }
    return 0;
}