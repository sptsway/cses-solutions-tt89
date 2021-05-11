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
queue<pair<pair<int,int>,char>> q;

pair<int,int> getChar(char ch) {
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(arr[i][j]==ch) return {i,j};
    return {-1,-1};
}

void getPar(int i,int j) {
    while (arr[i][j]!='A') {
        char ch=arr[i][j];
        ans+= ch;
        if(ch=='D') i--;
        else if(ch=='U') i++;
        else if(ch=='L') j++;
        else if(ch=='R') j--;
    }
}

bool getBfs() {
    pair<int,int> s= getChar('A'), e= getChar('B');
    if(s.ff==-1 || e.ff==-1) return 0;
    q.push({{s.ff,s.ss},'A'});
    arr[s.ff][s.ss]='.';

    while (!q.empty()) {
        auto a= q.front(); q.pop();
        int i=a.ff.ff,j=a.ff.ss;
        if(i<0 || j<0 || i==n || j==m) continue;
        char ch=a.ss;
        if(arr[i][j]=='B') {
            arr[i][j]=ch; getPar(i,j); return 1;
        }
        if(arr[i][j]!='.') continue;
        arr[i][j]=ch;

        q.push({{i+1,j},'D'}); q.push({{i-1,j},'U'});
        q.push({{i,j+1},'R'}); q.push({{i,j-1},'L'});
    }
    return 0;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];

        if(getBfs()) {
            cout<<"YES\n";
            reverse(ans.begin(),ans.end());
            cout<<ans.length()<<"\n";
            cout<<ans;
        }else cout<<"NO\n";
    }
    return 0;
}