//
// Created by Swaraj Pradhan on 11/04/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>


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
vector<int> h1, h2;
vector<vector<int>> t1,t2;

int combine_hash(int ph, int rh) {
    int l = (ph)%mod, r= (rh*rh)%mod;
    return (l*r)%mod;
}

int assign_hash(int i, int p, int d, vector<vector<int>> &tree, vector<int> &hash) {
    int c=0,h=combine_hash(1, d);
    for (int &j: tree[i]) {
        if (j == p) continue;
        c += assign_hash(j,i,d+1,tree, hash);
        h = combine_hash(h, hash[j]);
    }
    h = combine_hash(combine_hash(h, tree[i].size()), c+1);
    hash[i]=h;
    return c+1;
}

bool is_iso(int i1, int p1, int i2, int p2) {
    if (h1[i1] != h2[i2]) return false;
    vector<pii> v1,v2;
    for (int j: t1[i1]) {
        if (j==p1) continue;
        v1.emplace_back(h1[j], j);
    }for (int j: t2[i2]) {
        if (j==p2) continue;
        v2.emplace_back(h2[j], j);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (v1.size() != v2.size()) return false;

    for (int j=0;j<v1.size();j++) {
        if (!is_iso(v1[j].second, i1, v2[j].second, i2)) return false;
    }
    return true;
}

bool solve() {
    assign_hash(1,0,1,t1,h1);
    assign_hash(1,0,1,t2,h2);
    return is_iso(1,0,1,0);
    // sort(h1.begin(), h1.end());
    // sort(h2.begin(), h2.end());
    // for (int i=1;i<n+1;i++) cout<<h1[i]<<"@"<<h2[i]<<" ";
    // return ans;
    // return h1[1] == h2[1];
}

signed main() {
    // ifstream fileIn("sample_in.txt");
    // ofstream fileOut("sample_in.txt");
    // cin.rdbuf(fileIn.rdbuf());
    // cout.rdbuf(fileOut.rdbuf());
    fastIO;
    int TT=1;
    cin>>TT;
    for(int tt=1;tt<=TT;tt++) {
        cin>>n;
        t1.clear(); t1.resize(n+1);
        t2.clear(); t2.resize(n+1);
        h1.clear(); h1.resize(n+1);
        h2.clear(); h2.resize(n+1);
        for (int i=1;i<n;i++) {
            int a,b; cin>>a>>b;
            t1[a].emplace_back(b);
            t1[b].emplace_back(a);
        }for (int i=1;i<n;i++) {
            int a,b; cin>>a>>b;
            t2[a].emplace_back(b);
            t2[b].emplace_back(a);
        }
        if (solve()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

