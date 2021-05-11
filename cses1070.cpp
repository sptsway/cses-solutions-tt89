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

int n;
vector<int> arr;

bool solve() {
    if(n==2 || n==3) return 0;
    for(int i=2;i<=n;i+=2) arr.push_back(i);
    for(int i=1;i<=n;i+=2) arr.push_back(i);
    return 1;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        if(solve()) for(int i: arr) cout<<i<<" ";
        else cout<<"NO SOLUTION";
    }
    return 0;
}