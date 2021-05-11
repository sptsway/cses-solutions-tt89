//tt89 ;)
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void testcase(int t) { cout<<"Case #"<<t<<": "; }
void online() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}
const int mod= 1e9+7;

#define ff first
#define ss second

int n,m;
vector<vector<char>> arr;

bool chk(int i,int j) {
    if(i==n || i<0 || j==m || j<0) return false;
    return true;
}

vector<pair<int,int>> getIndx(char ch) {
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]==ch) ans.push_back({i,j});
        }
    }
    return ans;
}

vector<vector<int>> getSteps(char ch) {
    vector<vector<int>> a(n,vector<int>(m,INT_MAX));
    vector<pair<int,int>> v= getIndx(ch);
    queue<vector<int>> q;
    for(auto i: v) q.push({i.ff,i.ss,0});

    while (!q.empty()) {
        auto i= q.front(); q.pop();
        if(a[i[0]][i[1]]!=INT_MAX) continue;
        else if(arr[i[0]][i[1]]=='#') continue;
        a[i[0]][i[1]]=i[2];
        if(chk(i[0]-1,i[1])) q.push({i[0]-1,i[1],i[2]+1});
        if(chk(i[0]+1,i[1])) q.push({i[0]+1,i[1],i[2]+1});
        if(chk(i[0],i[1]-1)) q.push({i[0],i[1]-1,i[2]+1});
        if(chk(i[0],i[1]+1)) q.push({i[0],i[1]+1,i[2]+1});
    }
    return a;
}

string getParent(int i,int j,vector<vector<int>> &a) {
    cout<<"YES\n";
    cout<<a[i][j]<<'\n';
    string ans="";
    while (a[i][j]!=0) {
        if(chk(i-1,j) && a[i-1][j]==a[i][j]-1) ans+='D',i--;
        else if(chk(i+1,j) && a[i+1][j]==a[i][j]-1) ans+='U',i++;
        else if(chk(i,j-1) && a[i][j-1]==a[i][j]-1) ans+='R',j--;
        else if(chk(i-1,j+1) && a[i][j+1]==a[i][j]-1) ans+='L',j++;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string isPossible() {
    vector<vector<int>> b= getSteps('M');
    vector<vector<int>> a= getSteps('A');

    for(int i=0;i<n;i++) if(a[i][0]<b[i][0]) return getParent(i,0,a);
    for(int i=0;i<n;i++) if(a[i][m-1]<b[i][m-1]) return getParent(i,m-1,a);
    for(int i=0;i<m;i++) if(a[0][i]<b[0][i]) return getParent(0,i,a);
    for(int i=0;i<m;i++) if(a[n-1][i]<b[n-1][i]) return getParent(n-1,i,a);
    return "NO";
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        arr.resize(n,vector<char>(m));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
        cout<<isPossible();
    }
    return 0;
}