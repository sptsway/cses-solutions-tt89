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

int solve(int n) {
    if(n==1) return 0;
    if(n==2) return 6;
    if(n==3) return 28;

    int ans=0;
    ans+= (n-4)*(n-4)*(n*n-9);
    ans+= 4*(n-4)*(n*n-7);
    ans+= (2*(n-4)+2*(n-2))*(n*n-5);
    ans+= 8*(n*n-4);
    ans+= 4*(n*n-3);
    return ans/2;
}

signed main() {
    fastIO;
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++) {
        cout<<solve(t)<<"\n";
    }
    return 0;
}