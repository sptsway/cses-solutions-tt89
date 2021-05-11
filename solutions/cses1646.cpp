//tt89 ;)
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void testcase(int t) { cout<<"Case #"<<t<<": "; }
void online() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}
const int mod= 1e9+7;

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        int n,q; cin>>n>>q;
        vector<int> arr(n),sum(n);
        for (int &i: arr) cin>>i;
        sum[0]=arr[0];
        for(int i=1;i<n;i++) sum[i]=sum[i-1]+arr[i];
        while (q--) {
            int a,b; cin>>a>>b; a--;b--;
            cout<<sum[b]-sum[a]+arr[a]<<"\n";
        }
    }
    return 0;
}