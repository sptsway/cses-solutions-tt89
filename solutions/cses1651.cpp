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
vector<int> arr,low,up;

void getBuildUp(int a,int b,int i,int val) {
    if(up[i]<a || low[i]>b) return;
    if(low[i]>=a && up[i]<=b) arr[i]+=val;
    else getBuildUp(a,b,i*2,val), getBuildUp(a,b,i*2+1,val);
}

void getBorder(int i) {
    if(i>=n) { low[i]=up[i]=i; return; }
    getBorder(2*i); getBorder(2*i+1);
    low[i]= low[i*2]; up[i]= up[i*2+1];
}

int getPointNum(int a,int i) {
    if(i==a) return arr[i];
    else if(low[i]>a || up[i]<a) return 0;
    return arr[i]+ getPointNum(a,i*2) + getPointNum(a,i*2+1);
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q;
        int N=n;
        n= pow(2,ceil(log2(n)));
        arr.resize(2*n,0);
        low.resize(2*n); up.resize(2*n);
        for(int i=n;i<n+N;i++) cin>>arr[i];
        getBorder(1);
//        for(int i=1;i<n+N;i++) cout<<i<<"@"<<arr[i]<<" "; cout<<"\n";

        for (int a,b,c,d;q-- && cin>>a;) {
            if(a==1) {
                cin>>b>>c>>d;
                getBuildUp(n+b-1,n+c-1,1,d);
            }else {
                cin>>b;
                cout<<getPointNum(n+b-1,1)<<"\n";
            }
        }
    }
    return 0;
}