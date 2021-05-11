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

string s;
int arr[26]={};

string solve() {
    int n= s.length();
    string ans(n,' ');
    int one=0,indx=-1;
    for(int i=0;i<26;i++) if(arr[i]%2!=0) one++,indx=i;
    if(one>1) return "NO SOLUTION";
    else if(one) arr[indx]--, ans[n/2]=indx+'A';

    int i=0,j=n-1;
    for(int k=0;k<26;k++) {
        while (i<j && arr[k]) {
            ans[i]=ans[j]=k+'A';
            i++; j--; arr[k]-=2;
        }
    }
    return ans;
}

signed main() {
    fastIO;
    int T=1;
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>s;
        for(char i: s) arr[i-'A']++;
        cout<<solve();
    }
    return 0;
}