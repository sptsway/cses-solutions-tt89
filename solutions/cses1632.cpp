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

int n,k;
vector<pair<int,int>> arr;
map<int,int> m;

int solve() {
    int ans=0;
    for(auto i: arr) {
        i= {i.ss,i.ff};
        map<int,int>::iterator it= m.upper_bound(i.ff);
        if(it==m.begin()) continue;
        it--;
        if(it->ff<=i.ff) {
//            cerr<<it->ff<<"@"<<it->ss<<" ";
            it->ss--; if(it->ss==0) m.erase(it);
            m[i.ss]++; ans++;
        }
    }
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>k;
        arr.resize(n);
        for(auto &i: arr) cin>>i.ss>>i.ff;
        sort(arr.begin(),arr.end());
        m[0]=k;
        cout<<solve();
    }
    return 0;
}