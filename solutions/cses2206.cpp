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

#define ff first
#define ss second

int n,q;
vector<pair<int,int>> arr;
vector<int> low,up;

void getBuildUp(int i) {
    while (i) {
        arr[i].ff= min(arr[i*2].ff,arr[i*2+1].ff+low[i*2+1]-low[i*2]);
        arr[i].ss= min(arr[i*2+1].ss,arr[i*2].ss+ up[i*2+1]-up[i*2]);
        i/=2;
    }
}

void getBorder(int i) {
    if(i>=n) { low[i]=up[i]=i; return;}
    getBorder(i*2); getBorder(i*2+1);
    low[i]= low[i*2]; up[i]= up[i*2+1];
}

void getMinPrice(int i,int x,int &ans) {
    if(low[i]>x) {
        ans= min(ans,arr[i].ff + low[i]-x); return;
    }else if(x>up[i]) {
        ans= min(ans,arr[i].ss + x-up[i]); return;
    }else if(i>=n) {
        ans= min(ans,arr[i].ff); return;
    }
    getMinPrice(i*2,x,ans);
    getMinPrice(i*2+1,x,ans);
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q;
        int N=n;
        n= pow(2,ceil(log2(n)));
        arr.resize(2*n,{INT_MAX,INT_MAX});
        low.resize(2*n); up.resize(2*n);
        getBorder(1);
        for(int i=n;i<n+N;i++) {
            int a; cin>>a;
            arr[i]={a,a};
            getBuildUp(i/2);
        }

//        for(int i=1;i<2*n;i++) cout<<arr[i].ff<<"@"<<arr[i].ss<<" "; cout<<"\n";
        while (q--) {
            int a,b,c; cin>>a;
            if(a==1) {
                cin>>b>>c;
                arr[n+b-1]={c,c}; getBuildUp((n+b-1)/2);
            }else{
                cin>>b; c=INT_MAX;
                getMinPrice(1,n+b-1,c);
                cout<<c<<"\n";
            }
        }
    }
    return 0;
}