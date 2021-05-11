//tt89 ;)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
// find_by_order(k)--> returns iterator at index k
// order_of_key(k)--> returns no. of elem strictly less than k
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define clock cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
#define debug(x) cerr<<#x<<"= "<<x<<" ";
#define ff first
#define ss second
void testcase(int t) { cout<<"Case #"<<t<<": "; }
void printInFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}
const int mod= 1e9+7;

int n;
set<int> s;
vector<int> arr;

int solve() {
    int ans=0;
    for(int i=0,j=0;i<n;i++) {
        if(!s.count(arr[i])) s.insert(arr[i]);
        else {
            while(s.count(arr[i])) s.erase(arr[j++]);
            s.insert(arr[i]);
        }
        ans= max(ans,(int)s.size());
    }
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        arr.resize(n);
        for(int &i: arr) cin>>i;
        cout<<solve();
    }
    return 0;
}