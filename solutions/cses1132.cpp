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

int n;
vector<vector<int>> tree;
vector<int> high,dist;

int getHigh(int i,int p) {
    int x=0;
    for(int j: tree[i]) {
        if(j!=p) x= max(x,getHigh(j,i)+1);
    }
    high[i]=x;
    return x;
}

void getMaxDist(int i,int p,int d) {
    int mx1=-1,mx2=-1;
    for(int j: tree[i]) {
        if(j!=p) {
            if(mx1<high[j]) mx2=mx1,mx1=high[j];
            else if(mx2<high[j]) mx2=high[j];
        }
    }
    mx1++; mx2++;
    dist[i]= max(d,mx1);
    if(mx2) {
        for(int j: tree[i]) {
            if(j!=p) {
                if(high[j]+1==mx1) getMaxDist(j,i,max(mx2,d)+1);
                else getMaxDist(j,i,max(mx1,d)+1);
            }
        }
    }else {
        for(int j: tree[i]) {
            if(j!=p) getMaxDist(j,i,d+1);
        }
    }
//    cout<<i<<"@"<<mx1<<"@"<<d<<" ";
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        tree.resize(n+1);
        high.resize(n+1);
        dist.resize(n+1);
        for(int i=1;i<n;i++) {
            int a,b; cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        getHigh(1,0);
//        for(int i=1;i<=n;i++) cout<<high[i]<<" "; cout<<"\n";
        getMaxDist(1,0,0);
        for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
    }
    return 0;
}