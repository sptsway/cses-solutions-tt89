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
vector<int> arr,pref,up,low;

void buildUpArr(int i) {
    while (i) {
        arr[i]=arr[i*2]+arr[i*2+1];
        pref[i]= max(pref[i*2],arr[i*2]+pref[i*2+1]);
        pref[i]= max(pref[i],arr[i]);
        i/=2;
    }
}

void getBounds(int i) {
    if(i>=n) { low[i]=up[i]=i; return; }
    getBounds(i*2); getBounds(i*2+1);
    low[i]=low[i*2]; up[i]= up[i*2+1];
}

vector<int> getMaxPreSum(int a,int b,int i) {
    if(low[i]>b || up[i]<a) return {0,0};
    if(low[i]==a && up[i]==b) return {pref[i],arr[i]};

    vector<int> x,y;
    x= getMaxPreSum(max(a,low[i*2]),min(b,up[i*2]),i*2);
    y= getMaxPreSum(max(a,low[i*2+1]),min(b,up[i*2+1]),i*2+1);

    int pre= max(max(x[0],x[1]+y[0]),x[1]+y[1]);
//    cout<<a-n+1<<"@"<<b-n+1<<"#"<<pre<<" ";
    return {pre,x[1]+y[1]};
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q;
        int N=n;
        n= pow(2,ceil(log2(n)));
        arr.resize(2*n,-1e18); pref.resize(2*n,-1e18);
        up.resize(2*n,0); low.resize(2*n,0);
        for(int i=n;i<n+N;i++) {
            cin>>arr[i];
            pref[i]=arr[i];
            buildUpArr(i/2);
        }
        getBounds(1);
//        for(int i=1;i<2*n;i++) cout<<up[i]<<"@"<<low[i]<<" ";

        for (int a,b,c; q && cin>>a>>b>>c;--q ) {
            if(a==1) pref[n+b-1]=arr[n+b-1]=c, buildUpArr((n+b-1)/2);
            else cout<<max(getMaxPreSum(n+b-1,n+c-1,1)[0],(int)0)<<"\n";
        }
    }
    return 0;
}