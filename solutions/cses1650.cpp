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

int n,q;
vector<int> arr,bit[32];

void getBit() {
    for(int i=1;i<=n;i++) {
        for(int j=0;j<32;j++) {
            if(arr[i]&(1<<j)) bit[j][i]++;
            bit[j][i]+= bit[j][i-1];
        }
    }
}

int getXor(int i,int j) {
    i--;
    int ans=0;
    for(int k=0;k<32;k++) {
        if((bit[k][i]+bit[k][j])%2) ans+= 1<<k;
    }
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q;
        arr.resize(n+1);
        for (int i=1;i<=n;i++) cin>>arr[i];
        for(int i=0;i<32;i++) bit[i].resize(n+1,0);
        getBit();
        while (q--) {
            int a,b; cin>>a>>b;
            cout<<getXor(a,b)<<"\n";
        }
    }
    return 0;
}