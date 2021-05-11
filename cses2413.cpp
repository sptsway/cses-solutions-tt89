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

int n;
vector<int> a,b,arr;

void get1(int n) {
    a[0]=0; b[0]=0;
//    a[1]=1; b[1]=1;
    for(int i=1;i<=n;i++) {
        a[i]=b[i-1]+1;
        b[i]= b[i-1]+a[i];
        a[i]%=mod; b[i]%=mod;
    }
}

void get2(int n) {
    arr[0]=0; b[0]=0;
//    arr[1]=2; b[1]=2;
//    arr[2]=8;
//    for(int i=3;i<=n;i++) {
//        arr[i]=1;
//        for(int j=1;j<i;j++) {
//            arr[i]+= arr[j]*arr[i-j];
//        }
        arr[i]= a[i]*a[i]; arr[i]%=mod;
//        arr[i]+= a[i-1]*a[i-1]; arr[i]%=mod;
        arr[i]+= b[i-1]+1; arr[i]%=mod;
        b[i]= b[i-1]+arr[i]; b[i]%=mod;
    }
}

signed main() {
    fastIO;
    int T=1;
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        a.resize(n+1); b.resize(n+1);
        arr.resize(n+1);
        get1(n);
        get2(n);
        cout<<a[n]<<"@ ";
        cout<<arr[n]<<"\n";
    }
    return 0;
}