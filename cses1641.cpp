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
int a[3];
vector<pair<int,int>> arr;

bool setIt(int i,int j,int k) {
    a[0]=i+1,a[1]=j+1,a[2]=k+1;
    return 1;
}

bool solve() {
    for(int i=0;i<n;i++) {
        int j=i+1,k=n-1;
        while (j<k) {
            int sum=arr[i].ff+arr[j].ff+arr[k].ff;
            if(sum==x) return setIt(arr[i].ss,arr[j].ss,arr[k].ss);
            else if(sum>x) k--;
            else j++;
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
        for(int i=0;i<n;i++) {
            cin>>arr[i].ff; arr[i].ss=i;
        } sort(arr.begin(),arr.end());
        if(solve()) {
            cout<<a[0]<<" "<<a[1]<<" "<<a[2];
        }else cout<<"IMPOSSIBLE\n";
    }
    return 0;
}