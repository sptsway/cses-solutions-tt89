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

const int n=7;
int ans;
string s;
vector<vector<int>> arr;

bool chk(int i,int j) {
    if(i<0 || j<0 || i==n || j==n) return 0;
    else if(arr[i][j]) return 0;
    return 1;
}

void getArr(int i,int j,int k) {
    if(i==n-1 && j==0) {
        if(k==n*n -1) ans++;
        return;
    }

    if(chk(i-1,j) && chk(i+1,j) && !chk(i,j-1) && !chk(i,j+1)) return;
    if(!chk(i-1,j) && !chk(i+1,j) && chk(i,j-1) && chk(i,j+1)) return;
    if(i==n-1 && j==n-1 && !chk(i,j-1)) return;

    arr[i][j]=1;

    if(s[k]=='L' || s[k]=='?') if(j-1>=0 && arr[i][j-1]==0) getArr(i,j-1,k+1);
    if(s[k]=='R' || s[k]=='?') if(j+1<n && arr[i][j+1]==0) getArr(i,j+1,k+1);
    if(s[k]=='D' || s[k]=='?') if(i+1<n && arr[i+1][j]==0) getArr(i+1,j,k+1);
    if(s[k]=='U' || s[k]=='?') if(i-1>=0 && arr[i-1][j]==0) getArr(i-1,j,k+1);

    arr[i][j]=0;
    return;
}

//if(s[k]=='L' || s[k]=='?') if(chk(i,j-1)) getArr(i,j-1);
//if(s[k]=='R' || s[k]=='?') if(chk(i,j+1)) getArr(i,j+1);
//if(s[k]=='D' || s[k]=='?') if(chk(i+1,j)) getArr(i+1,j);
//if(s[k]=='U' || s[k]=='?') if(chk(i-1,j)) getArr(i-1,j);

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>s; ans=0;
        arr.resize(n,vector<int>(n,0));
        getArr(0,0,0);
        cout<<ans<<'\n';
        clock;
    }
    return 0;
}