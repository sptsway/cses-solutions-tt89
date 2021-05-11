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

int n;
vector<pair<int,int>> arr;

int solve() {
    int ans=0,prev=0;
    for(auto i: arr) {
        if(i.ss>=prev) ans++,prev=i.ff;
    }
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        arr.resize(n);
        for(int i=0;i<n;i++) cin>>arr[i].ss>>arr[i].ff;
        sort(arr.begin(),arr.end());
        cout<<solve();
    }
    return 0;
}