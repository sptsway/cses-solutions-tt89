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
const int N=20;

string a,b;
int dp[N][10][2][2];

int getDp(int i,int prev,bool b,bool zero,string &s) {
    if(i==N) return 1;
    if(dp[i][prev][b][zero]!=-1) return dp[i][prev][b][zero];

    bool _z= zero;
    int ans=0;

    if(!b) {
        for(int j=0;j<=9;j++) {
            if(zero && j!=0) _z= false;
            if(j!=prev || zero) ans+= getDp(i+1,j,0,_z,s);
        }
    } else {
        for(int j=0;j<=s[i]-'0';j++) {
            if(zero && j!=0) _z= false;
            if(j!=prev || zero) {
                if(j==s[i]-'0') ans+= getDp(i+1,j,1,_z,s);
                else ans+= getDp(i+1,j,0,_z,s);
            }
        }
    }
    dp[i][prev][b][zero]=ans;
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        int A,B; cin>>A>>B; A--;
        a= to_string(A);
        b= to_string(B);
        while (a.length()!=N) a='0'+a;
        while (b.length()!=N) b='0'+b;
        memset(dp,-1,sizeof(dp)); int ans1= getDp(0,0,1,1,a);
        memset(dp,-1,sizeof(dp)); int ans2= getDp(0,0,1,1,b);
        cout<<ans2-ans1;
    }
    return 0;
}