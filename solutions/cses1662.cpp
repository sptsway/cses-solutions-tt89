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

int n,x;
vector<int> arr;

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n; x=n;
        arr.resize(n);
        for(int &i: arr) cin>>i;
        map<int,int> m;
        int s=0,ans=0;

        for(int i=0;i<n;i++) {
            s+= arr[i];
            if(s%x==0) ans+= m[0]+1;
            else {
                if(m.find(s%x)!=m.end()) ans+=m[s%x];
                if(s>0) if(m.find(s%x-x)!=m.end()) ans+= m[s%x-x];
                if(s<0) if(m.find((s%x+x)%x)!=m.end()) ans+= m[(s%x+x)%x];
//                cout<<s%x<<"@"<<x-s%x<<" ";
            }
            m[s%x]++;
        }
        cout<<ans;
    }
    return 0;
}