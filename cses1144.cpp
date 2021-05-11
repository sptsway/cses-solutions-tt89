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

const int b_size=1000;

int n,N,q;
vector<int> segT,up,low,arr;
unordered_map<int,unordered_map<int,int>> bucket;

void getBuildUp(int i,int val) {
    while (i) {
        segT[i]+=val;
        i/=2;
    }
}

void getBorder(int i) {
    if(i>=N) {
        low[i]=(i-N)*b_size;
        up[i]= (i-N)*b_size + b_size-1;
    }else {
        getBorder(i*2); getBorder(i*2+1);
        low[i]=low[i*2]; up[i]= up[i*2+1];
    }
}

int getBucketCount(int a,int b,int i) {
//    cout<<i<<"@ ";
    int c=0;
    for(auto j: bucket[i]) {
        if(j.first>=a && j.first<=b) c+=j.second;
    }
    return c;
}

int getSalaryCount(int a,int b,int i) {
    if(low[i]>b || up[i]<a) return 0;
    if(i>=N) return getBucketCount(a,b,i-N);
    if(low[i]>=a && up[i]<=b) return segT[i];
    return getSalaryCount(a,b,i*2) + getSalaryCount(a,b,i*2+1);
}

signed main() {
    fastIO;
    int T=1;
    N=1e9;
    N/=b_size;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q;
        N=pow(2,ceil(log2(N)));
        arr.resize(n+1);
        segT.resize(2*N,0);
        low.resize(2*N,0); up.resize(2*N,0);

        getBorder(1);

        for(int i=1;i<=n;i++) {
            cin>>arr[i];
            bucket[arr[i]/b_size][arr[i]]++;
            getBuildUp(N+arr[i]/b_size,1);
        }

//        for(int i=1;i<2*N;i++) {
//            cout<<i<<"--> "<<low[i]<<" "<<up[i]<<"\n";
//        } for(int i=1;i<2*N;i++) {
//            cout<<i<<"--> "<<segT[i]<<"\n";
//        }

        while (q--) {
            char x; int a,b; cin>>x>>a>>b;
            if(x=='!') {
                bucket[arr[a]/b_size][arr[a]]--;
                if(bucket[arr[a]/b_size][arr[a]]==0) bucket[arr[a]/b_size].erase(arr[a]);
                getBuildUp(N+arr[a]/b_size,-1);

                bucket[b/b_size][b]++;
                arr[a]=b; getBuildUp(N+b/b_size,1);
            } else cout<<getSalaryCount(a,b,1)<<"\n";
        }
    }
    return 0;
}