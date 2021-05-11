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

const int n=8;
int ans;
char arr[n][n];
vector<int> x,y;

bool getChk(int i,int j) {
    if(arr[i][j]=='*') return false;
    for(int k=0;k<x.size();k++) {
        if(i==x[k] || j==y[k]) return false;
        if(abs(i-x[k])==abs(j-y[k])) return false;
    }
    return true;
}

void getAns(int i) {
    if(i==n) { ans++; return; }
    for(int j=0;j<n;j++) {
        if(getChk(i,j)) {
            x.push_back(i); y.push_back(j);
            getAns(i+1);
            x.pop_back(); y.pop_back();
        }
    }
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        ans=0;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
        getAns(0);
        cout<<ans;
    }
    return 0;
}