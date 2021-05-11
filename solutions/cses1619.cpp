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
vector<pair<int,bool>> arr;

int solve() {
    int ans=0,c=0;
    for(auto i: arr) {
        i.ss?c--:c++;
        ans=max(c,ans);
    }
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        for(int i=0;i<n;i++) {
            int a,b; cin>>a>>b;
            arr.push_back({a,0});
            arr.push_back({b,1});
        }
        sort(arr.begin(),arr.end());
        cout<<solve();
    }
    return 0;
}