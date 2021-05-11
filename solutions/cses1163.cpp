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

int n,len;
set<int> s;
map<int,int> m;
vector<int> arr;

int getQ(int x) {
    s.insert(x);
    set<int>::iterator it= s.find(x);
    int prev= *(--it);
    it++;it++; int next=*it;
    m[next-prev]--;
    if(m[next-prev]==0) m.erase(next-prev);
    m[next-x]++; m[x-prev]++;
    return m.rbegin()->first;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>len>>n;
        s.insert(0); s.insert(len);
        m[len]=1;
        while(n--) {
            int a; cin>>a;
            cout<<getQ(a)<<" ";
        }
    }
    return 0;
}