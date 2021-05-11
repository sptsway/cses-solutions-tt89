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
vector<int> arr,up,low;

void getBuildUp(int i) {
    while (i) {
        arr[i]= max(arr[i*2],arr[i*2+1]);
        i/=2;
    }
}

void getBorder(int i) {
    if(i>=n) { low[i]=up[i]=i; return; }
    getBorder(2*i); getBorder(2*i+1);
    low[i]= low[i*2]; up[i]= up[i*2+1];
}

int getRoomNo(int a,int i) {
    if(arr[i]<a) return 0;
    if(i>=n) { arr[i]-=a ; return i-n+1; }
    int x;
    if(arr[i*2]>=a) x= getRoomNo(a,i*2);
    else x= getRoomNo(a,i*2+1);

    arr[i]= max(arr[i*2],arr[i*2+1]);
    return x;
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
        up.resize(2*n); low.resize(2*n);
        for(int i=n;i<n+N;i++) {
            cin>>arr[i]; getBuildUp(i/2);
        }
        getBorder(1);
//        for(int i=1;i<2*n;i++) cout<<low[i]<<"@"<<up[i]<<" "; cout<<"\n";
//        for(int i=1;i<2*n;i++) cout<<arr[i]<<" "; cout<<"\n";
        for(int a;q && cin>>a;--q) {
            cout<<getRoomNo(a,1)<<" ";
        }
    }
    return 0;
}