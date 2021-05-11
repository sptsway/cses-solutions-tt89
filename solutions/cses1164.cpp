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
vector<int> ans;
vector<pair<pair<int,int>,int>> arr;

int solve() {
    sort(arr.begin(),arr.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int sz=0;
    for(int j=0;j<n;j++) {
        auto i= arr[j];
        if(pq.empty()) pq.push({i.ff.ss,++sz}),ans[i.ss]=sz;
        else {
            auto x= pq.top();
            if(x.ff<i.ff.ff) {
                pq.pop();
                pq.push({i.ff.ss,x.ss});
                ans[i.ss]= x.ss;
            } else pq.push({i.ff.ss,++sz}),ans[i.ss]=sz;
        }
    }
    return sz;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        arr.resize(n);
        ans.resize(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i].ff.ff>>arr[i].ff.ss;
            arr[i].ss=i;
        }
        cout<<solve()<<"\n";
        for(int i: ans) cout<<i<<" ";
    }
    return 0;
}