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

int n,q,base;
vector<int> arr,indx;

int getBase() {
    int ans=0;
    for(int i=1;i<n;i++) if(indx[i]<indx[i-1]) ans++;
    return ans+1;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q;
        arr.resize(n+2);
        indx.resize(n+2);
        for(int i=1;i<=n;i++) {
            cin>>arr[i];
            indx[arr[i]]=i;
        }
        arr[0]=indx[0]=0;
        arr[n+1]=indx[n+1]=n+1;
        base= getBase();

        while(q--) {
            int a,b; cin>>a>>b;
            int na= arr[a], nb= arr[b];
            // before swap
            bool xa1=0,xa2=0,xb1=0,xb2=0;
            if(indx[na-1]<indx[na]) xa1=1;
            if(indx[na]<indx[na+1]) xa2=1;
            if(indx[nb-1]<indx[nb]) xb1=1;
            if(indx[nb]<indx[nb+1]) xb2=1;
            // after swap
            swap(arr[a],arr[b]);
            swap(indx[na],indx[nb]);
            
            bool ya1=0,ya2=0,yb1=0,yb2=0;
            if(indx[na-1]<indx[na]) ya1=1;
            if(indx[na]<indx[na+1]) ya2=1;
            if(indx[nb-1]<indx[nb]) yb1=1;
            if(indx[nb]<indx[nb+1]) yb2=1;

//            if(na==nb+1) {
//                if(xa1^ya1) if(xa1) base++; else base--;
//                if(xa2^ya2) if(xa2) base++; else base--;
//                if(xb1^yb1) if(xb1) base++; else base--;
//            }else if(na==nb-1) {
//                if(xa1^ya1) if(xa1) base++; else base--;
//                if(xb1^yb1) if(xb1) base++; else base--;
//                if(xb2^yb2) if(xb2) base++; else base--;
//            }else {
//                if(xa1^ya1) if(xa1) base++; else base--;
//                if(xb1^yb1) if(xb1) base++; else base--;
//                if(xa2^ya2) if(xa2) base++; else base--;
//                if(xb2^yb2) if(xb2) base++; else base--;
//            }
            if(xa1^ya1) if(xa1) base++; else base--;
            if(xb1^yb1) if(xb1) base++; else base--;
            if(na!=nb-1) if(xa2^ya2) if(xa2) base++; else base--;
            if(na!=nb+1) if(xb2^yb2) if(xb2) base++; else base--;

            cout<<base<<"\n";
        }
    }
    return 0;
}