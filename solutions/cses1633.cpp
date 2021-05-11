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

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        int n; cin>>n;
        vector<int> arr(n+1);
        arr[0]=1;
        for(int i=0;i<=n;i++) {
            for(int j=1;j<=6;j++) {
                if(i+j<=n) arr[i+j]+=arr[i],arr[i+j]%=mod;
            }
        }
        cout<<arr[n];
    }
    return 0;
}