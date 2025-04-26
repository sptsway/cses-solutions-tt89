#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define pii pair<long long, long long>
//#define ff first
//#define ss second
//const int mod = 1e9+7;
int getGCD(int a, int b) {if(a<b) swap(a,b); if(b==0) return a; return getGCD(a%b, b);}
int getAPowB(int a, int b) {if(b==0) return 1; int x=getAPowB(a,b/2); x*= x; if(b%2) x*=a; return x;}

const int MAX_ANC= 30;
const int N= 2e5+1;

int n,q;
int par[N];
int ancestors[MAX_ANC][N];

int logg(int x) {
    int ans=0;
    while(x!=0) x/=2, ans++;
    return ans-1;
}

int climb(int x,int d) {
//    cout<<x<<"@"<<d<<" ";
    if(d==0) return x;
//    if(d==1) return par[x];
//    if(par[x]==x) return x;

    int anc= logg(d);
    int d2= getAPowB(2, anc);
    return climb(ancestors[anc][x], d-d2);
}

void build() {
//    for(int j=0;j<MAX_ANC;j++) ancestors[j].resize(n);

    for(int i=0;i<n;i++) ancestors[0][i]=par[i];
    for(int j=1;j<MAX_ANC;j++) {
        for(int i=0;i<n;i++) {
            int x= ancestors[j-1][i];
            ancestors[j][i]=ancestors[j-1][x];
        }
    }
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
	    cin>>n>>q;
//	    par.resize(n);
	    for(int i=0;i<n;i++) cin>>par[i], par[i]--;
	    build();

	    while(q--) {
	        int x,d; cin>>x>>d;
	        cout<<climb(x-1, d)+1<<"\n";
	    }
	}
	return 0;
}