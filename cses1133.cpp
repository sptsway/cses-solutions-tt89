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
vector<vector<int>> tree,dist,cnt;
vector<int> ans;

pair<int,int> getDist(int i,int p) {
    int sum=0,c=1;
    for(int j: tree[i]) {
        if(j!=p) {
            pair<int,int> y=getDist(j,i);
            dist[i].push_back(y.first);
            cnt[i].push_back(y.second);
            sum+=y.first; c+=y.second;
        } else {
            dist[i].push_back(-1);
            cnt[i].push_back(-1);
        }
    }
    return {sum+c,c};
}

void getSumDist(int i,int p,int s) {
    int l= tree[i].size();
    int x=0;
    for(int j=0;j<l;j++) {
        if(tree[i][j]!=p) x+= dist[i][j];
    }
    ans[i]=x+s;
    for(int j=0;j<l;j++) {
        if(tree[i][j]!=p) getSumDist(tree[i][j],i,x+s+(n-cnt[i][j])-dist[i][j]);
    }
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        tree.resize(n+1);
        cnt.resize(n+1);
        dist.resize(n+1);
        ans.resize(n+1,0);
        for(int i=1;i<n;i++) {
            int a,b; cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        getDist(1,0);
//        for(int i=1;i<=n;i++) {
//            int l= tree[i].size();
//            for(int j=0;j<l;j++) cout<<dist[i][j]<<"@"<<cnt[i][j]<<" ";
//            cout<<"\n";
//        }
        getSumDist(1,0,0);
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }
    return 0;
}