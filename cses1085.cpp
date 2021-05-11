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
vector<int> arr;

bool getGreedy(int x) {
    int c=0,s=0;
    for(int i: arr) {
        s+=i;
        if(s>x) c++,s=i;
        if(s>x) return false;
    }
    if(c>=k) return false;
    return true;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>k;
        arr.resize(n);
        for(int &i: arr) cin>>i;
        int l=1,h=accumulate(arr.begin(),arr.end(),0LL);
        while (l<h) {
            int m= (l+h)/2;
            if(getGreedy(m)) h=m;
            else l= m+1;
        }
        cout<<l;
    }
    return 0;
}