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
vector<string> ans;

void getAns(int i,bool b,string &s) {
    if(i==n) { ans.push_back(s); return; }
    if(b) {
        s[i]='1'; getAns(i+1,!b,s);
        s[i]='0'; getAns(i+1,b,s);
    } else {
        s[i]='0'; getAns(i+1,b,s);
        s[i]='1'; getAns(i+1,!b,s);
    }
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        string s(n,' ');
        getAns(0,0,s);
        for(string i: ans) cout<<i<<"\n";
    }
    return 0;
}