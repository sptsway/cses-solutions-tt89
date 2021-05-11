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
vector<vector<int>> arr;

int getCount(int a,int b,int c,int d) {
    int ans= arr[c][d];
    if(b) ans-= arr[c][b-1];
    if(a) ans-= arr[a-1][d];
    if(a && b) ans+= arr[a-1][b-1];
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q;
        arr.resize(n,vector<int>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                char a; cin>>a;
                if(a=='*') arr[i][j]=1;
                else arr[i][j]=0;
            }
        }
        for(int i=0;i<n;i++) for(int j=1;j<n;j++) arr[i][j]+=arr[i][j-1];
        for(int i=1;i<n;i++) for(int j=0;j<n;j++) arr[i][j]+=arr[i-1][j];
        while (q--) {
            int a,b,c,d; cin>>a>>b>>c>>d;
            a--; b--; c--; d--;
            cout<<getCount(a,b,c,d)<<"\n";
        }
    }
    return 0;
}