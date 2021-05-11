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

int n,x;
vector<int> arr;

int solve() {
    int ans=0,i=0,j=n-1;
    while (i<j) {
        if(arr[i]+arr[j]<=x) i++,j--;
        else j--;
        ans++;
    }
    if(i==j) ans++;
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>x;
        arr.resize(n);
        for(int &i: arr) cin>>i;
        sort(arr.begin(),arr.end());
        cout<<solve();
    }
    return 0;
}