//tt89 ;)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
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

int n,k;
vector<int> arr;

void solve() {
    ordered_set s;
    for(int i=0;i<k-1;i++) s.insert({arr[i],i});
    for(int i=k-1;i<n;i++) {
        s.insert({arr[i],i});
        cout<<s.find_by_order((k-1)/2)->first<<" ";
        s.erase({arr[i-k+1],i-k+1});
    }
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>k;
        arr.resize(n);
        for(int &i: arr) cin>>i;
        solve();
    }
    return 0;
}