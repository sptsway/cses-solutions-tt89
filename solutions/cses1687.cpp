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

int n,q;
vector<int> dep;
vector<vector<int>> tree,par;

void getPar(int i,int p) {
    par[i].push_back(p);
    for(int j=1;;j++) {
        int x= par[i][j-1];
        if(par[x].size()<j) break;
        par[i].push_back(par[x][j-1]);
    }

    for(int j: tree[i]) getPar(j,i);
}

void getDepth(int i,int d) {
    dep[i]=d;
    for(int j: tree[i]) getDepth(j,d+1);
}

int getKBoss(int i,int k) {
    if(k>dep[i]) return -1;
    while (k) {
        int x= log2(k);
        i= par[i][x];
        k-=pow(2,x);
    }
    return i;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q;
        tree.resize(n+1);
        par.resize(n+1);
        dep.resize(n+1);
        for(int i=2;i<=n;i++) {
            int a; cin>>a;
            tree[a].push_back(i);
        }
//        getPar(1,0);
        getDepth(1,0);
        for(int j: tree[1]) getPar(j,1);
//        for(int j=1;j<=n;j++) {
//            cout<<j<<"--> ";
//            for(int i: par[j]) cout<<i<<" ";
//            cout<<"\n";
//        }
        while(q--) {
            int x,k; cin>>x>>k;
            cout<<getKBoss(x,k)<<"\n";
        }
    }
    return 0;
}