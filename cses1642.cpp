//tt89 ;)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
// find_by_order(k)--> returns iterator at index k
// odered_of_key(k)--> returns no. of elem stricktly less than k
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
int a[4];
vector<int> arr;
map<int,pair<int,int>> m;

bool setIt(int p,int q,int r,int s) {
    a[0]=p+1,a[1]=q+1,a[2]=r+1,a[3]=s+1;
    return 1;
}

bool solve() {
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) m[arr[i]+arr[j]]={i,j};
    for(int i=0;i<n;i++) {
        if(i && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++) {
            int y= x-arr[i]-arr[j];
            if(m.find(y)==m.end()) continue;
            if(m[y].ff==i || m[y].ss==i || m[y].ff==j || m[y].ss==j) continue;
            return setIt(i,j,m[y].ff,m[y].ss);
        }
    }
    return 0;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>x;
        arr.resize(n);
        for(int &i: arr) cin>>i;
        if(solve()) {
            cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3];
        }else cout<<"IMPOSSIBLE\n";
    }
    return 0;
}