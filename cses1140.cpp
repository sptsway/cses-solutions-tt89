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
vector<int> dp;
vector<pair<pair<int,int>,int>> arr;

int getSearch(int i,int x) {
    int j= n;
    while (i<j) {
        int m= (i+j)/2;
        if(arr[m].ff.ff<=x) i=m+1;
        else j=m;
    }
    return i;
}

int getDp(int i,int x) {
    if(i==n) return 0;
    if(x>=arr[i].ff.ff) return getDp(getSearch(i,x),x);
    if(dp[i]!=-1) return dp[i];
    dp[i]= max(getDp(i+1,x),getDp(i+1,arr[i].ff.ss)+arr[i].ss);
//    cout<<i<<"@"<<x<<"@"<<dp[i]<<"  ";
    return dp[i];
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        arr.resize(n);
        dp.resize(n,-1);
        for(auto &i: arr) cin>>i.ff.ff>>i.ff.ss>>i.ss;
        sort(arr.begin(),arr.end());
        cout<<getDp(0,0);
    }
    return 0;
}