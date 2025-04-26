#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<long long, long long>
#define ff first
#define ss second
const int mod = 1e9+7;
int getGCD(int a, int b) {if(a<b) swap(a,b); if(b==0) return a; return getGCD(a%b, b);}
int getAPowB(int a, int b) {if(b==0) return 1; int x=getAPowB(a,b/2); x*= x; x%=mod;if(b%2) x*=a,x%=mod; return x;}

int n;
vector<int> arr,par;

void construct() {
    map<int,int> mp;
    for(int i=1;i<=n;i++) mp[i]=-1;
    for(int i=0;i<n-2;i++) mp[arr[i]]=i;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i: mp) if(i.ss==-1) pq.push(i.ff);

    for(int i=0;i<n-2;i++) {
        int x= pq.top(); pq.pop();
        par[x]=arr[i];
        if(mp[arr[i]]==i) pq.push(arr[i]);
    }

    int a=-1,b=-1;
    for(int i=1;i<=n;i++) {
        if(par[i]) continue;
        if(a==-1) a=i;
        else b=i;
    }
//    cout<<a<<"@"<<b<<" ";
    par[b]=a;
}

signed main() {
	// ifstream fileIn("sample_in.txt");
	// ofstream fileOut("sample_in.txt");
	// cin.rdbuf(fileIn.rdbuf());
    // cout.rdbuf(fileOut.rdbuf());
	fastIO;
	int TT=1;
//	cin>>TT;
	for(int tt=1;tt<=TT;tt++) {
	    cin>>n;
	    arr.clear(); arr.resize(n-2);
	    par.clear(); par.resize(n+1,0);
	    for(int &i: arr) cin>>i;
	    construct();

	    for(int i=1;i<=n;i++) if(par[i]) cout<<i<<" "<<par[i]<<"\n";

	}
	return 0;
}
