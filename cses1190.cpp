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
//vector<int> low,up;
vector<vector<int>> segT;
// segT[i]= {maxPreSum, maxSufSum ,maxSubArrSum, arrSum };

void getBuildUp(int i) {
    while(i) {
        int l= i*2,r=i*2+1;
        segT[i][0]= max(segT[l][0],segT[l][3]+segT[r][0]);
        segT[i][1]= max(segT[r][1],segT[r][3]+segT[l][1]);
        segT[i][3]= segT[l][3] + segT[r][3];

        segT[i][2]= max(max(segT[l][2],segT[r][2]),segT[l][1]+segT[r][0]);
        segT[i][2]= max( max(segT[i][2],segT[i][3]), max(segT[i][0],segT[i][1]));

        i/=2;
    }
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q; int N=n;
        n= pow(2,ceil(log2(n)));
        segT.resize(2*n,{0,0,0,0});
//        low.resize(2*n); up.resize(2*n);

        for(int i=n;i<n+N;i++) {
            int a; cin>>a;
            segT[i]={a,a,a,a};
            getBuildUp(i/2);
        }

        for(int a,b; q-- && cin>>a>>b;) {
            segT[n+a-1]={b,b,b,b}; getBuildUp((n+a-1)/2);
            cout<<max(segT[1][2],0LL)<<"\n";
        }

    }
    return 0;
}