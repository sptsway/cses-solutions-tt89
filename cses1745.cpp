//tt89 ;)
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define clock cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
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
vector<unordered_set<int>> dp;

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        arr.resize(n);
        dp.resize(n+1);
        for(int &i: arr) cin>>i;
        dp[0]={0,arr[0]};

        for(int i=1;i<n;i++) {
            for(int j: dp[i-1]) dp[i].insert(j),dp[i].insert(j+arr[i]);
        }

        vector<int> ans;
        for(int i: dp[n-1]) if(i) ans.push_back(i);
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<"\n";
        for(int i: ans) cout<<i<<" ";
        clock;
    }
    return 0;
}