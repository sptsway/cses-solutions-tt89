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

int n,N,q;
vector<int> euler,segT,arr,low,up;
unordered_map<int,vector<int>> m;
vector<vector<int>> tree;

void getEulerTour(int i,int p) {
    euler.push_back(i);
    for(int j: tree[i]) if(j!=p) getEulerTour(j,i);
    euler.push_back(i);
}

void getBuildUp(int i,int val) {
    while (i) {
        segT[i]+=val;
        i/=2;
    }
}

void getBorder(int i) {
    if(i>=N) low[i]=up[i]=i;
    else{
        getBorder(i*2); getBorder(i*2+1);
        low[i]=low[i*2]; up[i]=up[i*2+1];
    }
}

int getSubTreeSum(int a,int b,int i) {
    if(low[i]>b || up[i]<a) return 0;
    else if(a<=low[i] && b>=up[i]) return segT[i];
    return getSubTreeSum(a,b,i*2) + getSubTreeSum(a,b,i*2+1);
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q;
        tree.resize(n+1);
        arr.resize(n+1);
        for(int i=1;i<=n;i++) cin>>arr[i];
        for(int i=1;i<n;i++) {
            int a,b; cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        getEulerTour(1,0);
        N= euler.size(); N= pow(2,ceil(log2(N)));
        segT.resize(2*N,0);
        low.resize(2*N); up.resize(2*N);
        getBorder(1);
        for(int i=0;i<euler.size();i++) {
            m[euler[i]].push_back(i);
//            cout<<euler[i]<<" ";
        }for(int i=1;i<=n;i++) {
            getBuildUp(N+m[i][0],arr[i]);
            getBuildUp(N+m[i][1],arr[i]);
        }

//        cout<<"\n";
//        for(int i=1;i<2*N;i++) cout<<segT[i]<<" "; cout<<"\n";

        for(int a,b,c; q-- && cin>>a;) {
            if(a==1) {
                cin>>b>>c;
//                cout<<N+m[b][0]<<"@"<<N+m[b][1]<<" ";
                getBuildUp(N+m[b][0],c-arr[b]);
                getBuildUp(N+m[b][1],c-arr[b]);
                arr[b]=c;
            } else {
                cin>>b;
//                cout<<N+m[b][0]<<"@"<<N+m[b][1]<<" ";
                cout<<getSubTreeSum(N+m[b][0],N+m[b][1],1)/2<<"\n";
            }
        }
    }
    return 0;
}