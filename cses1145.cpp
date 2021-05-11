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

int n;
vector<int> arr;

void getReplace(int x,vector<int> &seq) {
    int i=0,j=seq.size()-1;
    while (i<j) {
        int m= (i+j)/2;
        if(seq[m]<x) i=m+1;
        else j=m;
    }
    seq[i]=x;
}

int solve() {
    vector<int> seq;
    for(int i: arr) {
        if(seq.empty()) seq.push_back(i);
        else if(*seq.rbegin()<i) seq.push_back(i);
        else getReplace(i,seq);
    }
    return seq.size();
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