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

int x,y;

int solve() {
    int z= max(x,y);
    int ans= (z-1)*(z-1);
    if(z%2) {
        if(z==x) return ans+y;
        return ans+2*z-x;
    }
    if(z==y) return ans+x;
    return ans+2*z-y;
}

signed main() {
    fastIO;
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>x>>y;
        cout<<solve()<<'\n';
    }
    return 0;
}