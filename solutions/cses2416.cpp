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

const int N= 1e6+10;

int n,q;
//vector<vector<int>> arr;
//vector<int> low,up;
int arr[N][4],low[N],up[N];

int getMinMoves(int a,int b,int i,int &x) {
//    cout<<a<<"_"<<b<<"_"<<x<<" ";
    if(low[i]>b || up[i]<a) return 0;
    else if(low[i]==a && up[i]==b) {
        if(arr[i][0]>=x) {
            x= arr[i][1]; //cout<<"#"<<x<<"-"<<i<<"# ";
            return arr[i][2];
        }
        else if(arr[i][1]<=x) return arr[i][3]+ (x-arr[i][1])*(b-a+1);
    }
    int y= getMinMoves(max(a,low[i*2]),min(b,up[i*2]),i*2,x);
//    if(a==low[i*2]) x= max(x,arr[i*2][1]);
    int z= getMinMoves(max(a,low[i*2+1]),min(b,up[i*2+1]),i*2+1,x);

//    cout<<i<<"@"<<a<<"-"<<b<<"-"<<x<<"-"<<y<<"-"<<z<<" ";

    return y+z;
}

void getBuildUp(int i) {
//    while (i) {
        arr[i][0]= arr[i*2][0];
        arr[i][1]= max(arr[i*2][1],arr[i*2+1][1]);

        if(arr[i*2][1]<=arr[i*2+1][0]) arr[i][2]= arr[i*2][2]+arr[i*2+1][2];
        else {
            int x= arr[i*2][1];
            arr[i][2]= arr[i*2][2]+getMinMoves(low[i*2+1],up[i*2+1],i*2+1,x);
        }

        arr[i][3]= arr[i*2][3] + (arr[i][1]-arr[i*2][1])*(up[i*2]-low[i*2]+1) +
                arr[i*2+1][3] + (arr[i][1]-arr[i*2+1][1])*(up[i*2+1]-low[i*2+1]+1);

//        i/=2;
//    }
}

void getBorder(int i) {
    if(i>=n) { low[i]=up[i]=i; return;}
    getBorder(i*2); getBorder(i*2+1);
    low[i]= low[i*2]; up[i]= up[i*2+1];
}

signed main() {
    fastIO;
    int T=1;
//    cout<<N<<"@\n";
//    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>q;
        int m=n;
        n= pow(2,ceil(log2(n)));
//        arr.resize(2*n,vector<int>(4));
//        low.resize(2*n); up.resize(2*n);
        for(int i=1;i<2*n;i++) arr[i][0]=arr[i][1]=0,arr[i][2]=arr[i][3]=0;
        getBorder(1);
        for(int i=n;i<n+m;i++) {
            int a; cin>>a;
            arr[i][0]=arr[i][1]=a;
            arr[i][2]=arr[i][3]=0;
//            getBuildUp(i/2);
        }
        for(int i=n-1;i>0;i--) getBuildUp(i);

//        cout<<"\n";
//        for(int i=1;i<2*n;i++) {
//            cout<<i<<"---> "<<low[i]<<"-"<<up[i]<<"-  ";
//            for(int j=0;j<4;j++) cout<<arr[i][j]<<" ";
//            cout<<endl;
//        }//cout<<"\n\n\n";

        for(int a,b;q--;) {
            cin>>a>>b;
            int x= arr[n+a-1][0]; //cout<<x<<"# ";
            cout<<getMinMoves(n+a-1,n+b-1,1,x)<<"\n";
        }
    }
    return 0;
}