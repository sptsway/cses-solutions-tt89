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

int n,m;
vector<int> ans,dep;
vector<vector<int>> tree,par;

void getDepth(int i,int p,int d) {
    dep[i]=d;
    for(int j: tree[i]) {
        if(j!=p) getDepth(j,i,d+1);
    }
}

void getPar(int i,int p) {
    par[i].push_back(p);
    for(int j=1;par[par[i][j-1]].size()>=j;j++) {
        par[i].push_back(par[par[i][j-1]][j-1]);
    }

    for(int j: tree[i]) if(j!=p) getPar(j,i);
}

int getKUp(int i,int k) {
    if(dep[i]<k) return 0;
    if(k==0) return i;
    if(k==1) return par[i][0];
    int j= log2(k);
    return getKUp(par[i][j],k-pow(2,j));
}

int getLCA(int a,int b) {
    if(dep[a]>dep[b]) a= getKUp(a,dep[a]-dep[b]);
    else if(dep[a]<dep[b]) b= getKUp(b,dep[b]-dep[a]);
    if(a==b) return a;
    else if(par[a][0]==par[b][0]) return par[a][0];

    int j;
    for(j=1;j<par[a].size();j++) {
        if(par[a][j]==par[b][j]) break;
    }
    return getLCA(par[a][j-1],par[b][j-1]);
}

int getAns(int i,int p) {
    for(int j: tree[i]) {
        if(j!=p) ans[i]+= getAns(j,i);
    }
    return ans[i];
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m;
        tree.resize(n+1); par.resize(n+1);
        ans.resize(n+1,0); dep.resize(n+1);
        for(int i=1;i<n;i++) {
            int a,b; cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        getDepth(1,0,0);
        for(int j: tree[1]) getPar(j,1);
//        cout<<getKUp(4,2);

//        for(int i=1;i<=n;i++) {
//            cout<<i<<"---> ";
//            for(int j: par[i]) cout<<j<<" ";
//            cout<<"\n";
//        }
        for(int i=0;i<m;i++) {
            int a,b; cin>>a>>b;
            int c= getLCA(a,b);
//            cout<<c<<endl;
            ans[a]++; ans[b]++; ans[c]--;
            if(c!=1) ans[par[c][0]]--;
        }
        getAns(1,0);
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }
    return 0;
}