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

int n;
vector<int> arr, segt;

void getBuildTree(vector<int> &v) {
    segt.resize(n,0);
    for(int i: v) segt.push_back(1);

    for(int i=n;i<2*n;i++) {
        int j=i;
        while (j!=1) {
            j/=2;
            segt[j]++;
        }
    }
//    for(int i=1;i<2*n;i++) cout<<segt[i]<<" ";
}

void getDeduct(int i) {
    while (i) {
        segt[i]--;
        i/=2;
    }
}

int getRemove(int x) {
    for(int i=1;i<2*n;) {
        if(i>=n) { getDeduct(i); return arr[i-n]; }
        if(segt[i*2]>=x) i*=2;
        else x-=segt[i*2], i=i*2+1;
    }
    return -1;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        int N=n;
        arr.resize(n);
        for(int &i: arr) cin>>i;

        int p= ceil(log2(n));
        n= pow(2,p);
        arr.resize(n);
        getBuildTree(arr);

        for(int j=0;j<N;j++) {
            int x; cin>>x;
            cout<<getRemove(x)<<" ";
        }
    }
    return 0;
}