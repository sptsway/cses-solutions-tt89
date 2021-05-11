//tt89 ;)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
// find_by_order(k)--> returns iterator at index k
// order_of_key(k)--> returns no. of elem strictly less than k
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define clock cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
#define debug(x) cerr<<#x<<"= "<<x<<" ";
#define ff first
#define ss second
void testcase(int t) { cout<<"Case #"<<t<<": "; }
void printInFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}
const int mod= 1e9+7;
const int N= 1e6+1;

vector<int> divs,prime;

void getPrime() {
    prime.resize(N,0);
    for(int i=2;i<N;i++) {
        if(prime[i]) continue;
        for(int j=i*i;j<N;j+=i) if(!prime[j]) prime[j]=i;
    }
}

void getdivsCount() {
    divs.resize(N,0);
    divs[1]=1;
    for(int i=2;i<N;i++) {
        if(!prime[i]) { divs[i]=2; continue; }
        int x= prime[i],y=i/prime[i];
        int c=0;
        while (y%x==0) c++; y/=x;
        int z= divs[i/prime[i]];
        divs[i]= z + (z-c+1);
    }
}

signed main() {
    fastIO;
    int T=1;
    cin>>T;
    getPrime();
    getdivsCount();
    for(int t=1;t<=T;t++) {
        int x; cin>>x;
        cout<<divs[x]<<"\n";
    }
    return 0;
}