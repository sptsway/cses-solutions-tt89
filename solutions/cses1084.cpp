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

int n,m,k;
vector<int> a,b;

int solve() {
    int i=0,j=0,ans=0;
    while (i<n && j<m) {
        if (abs(a[i]-b[j])<=k) ans++,i++,j++;
        else if(a[i]>b[j]) j++;
        else i++;
    }
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m>>k;
        a.resize(n); b.resize(m);
        for(int &i: a) cin>>i;
        for(int &i: b) cin>>i;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        cout<<solve();
    }
    return 0;
}