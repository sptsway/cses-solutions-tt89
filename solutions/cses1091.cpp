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

int n,p;
vector<int> arr;
map<int,int> m;

int getAns(int i) {
    if(m.empty()) return -1;
//    cout<<m.begin()->first<<"@";
    if(m.begin()->first>i) return -1;
    if(m.find(i)!=m.end()) {
        m[i]--;
        if(m[i]==0) m.erase(i);
        return i;
    }
    m[i]=0;
    map<int,int>::iterator ptr= m.find(i); ptr--;
    m.erase(i);
    i= ptr->first;
    m[i]--; if(m[i]==0) m.erase(i);
    return i;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>p;
        arr.resize(p);
        for(int i=0;i<n;i++) {
            int a; cin>>a;
            m[a]++;
        }
        for(int &i: arr) cin>>i;
        for(int i: arr) cout<<getAns(i)<<endl;
    }
    return 0;
}