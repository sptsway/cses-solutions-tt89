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
const int inf = 1e15;
const int N=501;

int n,m,q;
int dist[N][N];

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=inf;
        for(int i=0;i<m;i++) {
            int a,b,c; cin>>a>>b>>c;
            dist[a][b]= min(dist[a][b],c);
            dist[b][a]= min(dist[b][a],c);
        }

        for (int i = 1; i <= n; i++) dist[i][i] = 0;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <=n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for(int a,b; q-- && cin>>a>>b;) {
            if(dist[a][b]==inf) dist[a][b]=-1;
            cout<<dist[a][b]<<"\n";
        }
    }
    return 0;
}