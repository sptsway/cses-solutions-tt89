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

int n,m;
char arr[1001][1001];
string ans;

void getBfs(int i,int j) {
    queue<pair<int,int>> q;
    q.push({i,j});
    while (!q.empty()) {
        auto a= q.front(); q.pop();
        int i=a.ff,j=a.ss;
        if(i<0 || j<0 || i==n || j==m) continue;
        if(arr[i][j]!='.') continue;
        arr[i][j]='#';

        q.push({i+1,j}); q.push({i-1,j});
        q.push({i,j+1}); q.push({i,j-1});
    }
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
        int ans=0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(arr[i][j]=='.') ans++, getBfs(i,j);
        cout<<ans;
    }
    return 0;
}