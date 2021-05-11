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

int n,q;
vector<int> sum,segT,low,up,euler,arr;
vector<vector<int>> tree;
unordered_map<int,vector<int>> m;

void getDfs(int i,int p,int val) {
    sum[i]= arr[i]+val;
    for(int j: tree[i]) if(j!=p) getDfs(j,i,sum[i]);
//    cout<<i<<"@"<<sum[i]<<" ";
}

void getEulerTour(int i,int p,int &timer) {
    m[i].push_back(timer++);
    euler.push_back(i);
    for(int j: tree[i]) if(j!=p) getEulerTour(j,i,timer);
    m[i].push_back(timer++);
    euler.push_back(i);
}

void getBuildSegT(int i) {
    if(i>=n) {
        segT[i]=sum[euler[i-n]];
        low[i]=up[i]=i;
        return;
    }
    getBuildSegT(i*2); getBuildSegT(i*2+1);
    low[i]=low[i*2]; up[i]=up[i*2+1];
}

void addRangeSum(int i,int val,int a,int b) {
    if(low[i]>b || up[i]<a) return;
    else if(low[i]==a && up[i]==b) { segT[i]+= val; return; }
    addRangeSum(i*2,val,max(a,low[i*2]),min(b,up[i*2]));
    addRangeSum(i*2+1,val,max(a,low[i*2+1]),min(b,up[i*2+1]));
}

int getPathSum(int i,int a) {
    if(low[i]>a || up[i]<a) return 0;
    if(i>=n) return segT[i];
    return segT[i]+ getPathSum(i*2,a) + getPathSum(i*2+1,a);
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q;
        arr.resize(n+1); sum.resize(n+1);
        for(int i=1;i<=n;i++) cin>>arr[i];
        tree.resize(n+1);
        for(int i=1;i<n;i++) {
            int a,b; cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        int timer=0;
        getDfs(1,0,0);
        getEulerTour(1,0,timer); //cout<<timer<<"@ ";
        n= pow(2,ceil(log2(2*n)));
        segT.resize(2*n,0);
        low.resize(2*n); up.resize(2*n);
        getBuildSegT(1);

//        for(int i=1;i<2*n;i++) cout<<i<<"-> "<<low[i]<<"@"<<up[i]<<" "<<segT[i]<<"\n";

        for(int a,b,c; q-- && cin>>a;) {
            if(a==1) {
                cin>>b>>c;
                int x= n+m[b][0], y= n+m[b][1];
//                cout<<x<<"#"<<y<<"\n";
                addRangeSum(1,c-arr[b],x,y);
                arr[b]=c;
            } else {
                cin>>b;
                cout<<getPathSum(1,n+m[b][0])<<"\n";
//                cout<<m[b][0]<<"#\n";
            }
        }
    }
    return 0;
}