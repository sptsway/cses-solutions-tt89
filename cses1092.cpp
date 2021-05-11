//tt89 ;)
#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
#define int long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define clock cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
void testcase(int t) { cout<<"Case #"<<t<<": "; }
void online() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
}
const int mod= 1e9+7;

int n;
unordered_set<int> a,b;

bool solve() {
    int s=n*(n+1)/2,s1=0,s2=0;
    if(s%2) return false;
    for(int i=1;i<=n;i++) {
        if(i%2) a.insert(i),s1+=i;
        else b.insert(i),s2+=i;
    }
    if(abs(s1-s2)%2) return false;
    if (s1>s2) {
        vector<int> va,vb;
        va.push_back(1); a.erase(1);
        s1--; s2++;
        int cur=2;
        while (s1>s2) {
            int x= cur+1,y= cur;
            a.erase(x); b.erase(y);
            s1--; s2++;
            va.push_back(x); vb.push_back(y);
            cur+=2;
        }
        for(int i: va) b.insert(i);
        for(int i: vb) a.insert(i);
    } else if (s1<s2) {
        vector<int> va,vb;
        int cur=1;
        while (s1<s2) {
            int x= cur,y= cur+1;
            a.erase(x); b.erase(y);
            s1++; s2--;
            va.push_back(x); vb.push_back(y);
            cur+=2;
        }
        for(int i: va) b.insert(i);
        for(int i: vb) a.insert(i);
    }
    return true;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n;
        if(solve()) {
            cout<<"YES\n";
            cout<<a.size()<<"\n"; for(int i: a) cout<<i<<" "; cout<<"\n";
            cout<<b.size()<<"\n"; for(int i: b) cout<<i<<" "; cout<<"\n";
        } else cout<<"NO\n";
    }
    return 0;
}