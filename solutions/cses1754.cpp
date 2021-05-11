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

int a,b;

bool solve() {
    if(a<b) swap(a,b);
    if((a+b)%3) return 0;
    if(b*2<a) return 0;
    return 1;
}

signed main() {
    fastIO;
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>a>>b;
        if(solve()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}