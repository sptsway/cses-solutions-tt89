//
// Created by Swaraj Pradhan on 10/04/26.
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

int n,m;
vector<int> deg,ans;
vector<vector<int>> gph;

void solve() {
	ans.clear();
	priority_queue<int> pq;
	for (int i=1;i<n+1;i++) if (deg[i]==0) pq.push(i);

	while (!pq.empty()) {
		int a= pq.top(); pq.pop();
		ans.push_back(a);

		for (int i: gph[a]) {
			if (--deg[i]  ==0) pq.push(i);
		}
	}
	reverse(ans.begin(), ans.end());
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
		cin>>n>>m;
		deg.resize(n+1, 0);
		gph.resize(n+1);
		while (m--) {
			int in,out; cin>>in>>out; // out -> in
			gph[out].push_back(in);
			deg[in]++;
		}

		solve();
		for (int i: ans) cout<<i<<" ";
	}
	return 0;
}


/*
input:
n m
18 16
edges:
6 8
3 1
5 1
4 12
10 16
12 7
11 1
16 14
13 7
17 8
18 14
14 2
15 3
9 15
7 2
8 7
ans: 9 15 3 5 11 1 4 6 17 8 12 13 7 10 16 18 14 2
*/