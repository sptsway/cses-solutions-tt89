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

vector<pair<int,int>> ans;

void getAns(int a,int b,int c,int n) {
    if(n==0) return;
    if(n==1) { ans.push_back({a,c}); return; }
    getAns(a,c,b,n-1);
    ans.push_back({a,c});
    getAns(b,a,c,n-1);
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        int n; cin>>n;
        getAns(1,2,3,n);
        cout<<ans.size()<<"\n";
        for(auto i: ans) cout<<i.ff<<" "<<i.ss<<"\n";
    }
    return 0;
}