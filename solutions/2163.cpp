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

int n, k;

struct node{
int x;
    node(int x): x(x) {}
};

class segT{
int N;
int pointer;
vector<int> v;

    void add(int x) {
        while(x) v[x]++, x/=2;
    }

    void deduct(int x) {
        while(x) v[x]--, x/=2;
    }


    int leftPos(int x,int d) {
        if(v[x]<d) return -1;

        while(x<N) {
            if(v[x*2]>=d) x*=2;
            else {
                d-= v[x*2];
                x=x*2+1;
            }
        }
        return x;
    }

public:
    void print() {
        for(int i=1;i<2*N;i++) {
            if(i<N) cout<<v[i]<<"@ ";
            else if(i==pointer+N) cout<<v[i]<<"x ";
            else cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
    segT(int n) {
        N= pow(2,ceil(log2(n)));
        v.resize(2*N, 0);
        for(int i=N;i<N+n;i++) this->add(i);
        pointer=n-1;
    }

    int size() {
        return v[1];
    }

    void remove(int x) {
        return deduct(x+N);
    }

    // cur pointer
    int jump(int d) {
        if(this->size()==0) return -1;
        if(this->size()==1) {
            pointer=-1;
            return leftPos(1,1)-N;
        }
        d%= this->size();
        if(d==0) {
            if(v[pointer+N]) return pointer;

//            pointer= leftPos(1,this->size())-N;
            jump(1);
            return jump(this->size()-1);
        }
        int x= (pointer+N)/2,prev=(pointer+N);
//        cout<<x<<"@"<<prev<<"@"<<d<<"__";

        while(x && d!=0) {
            if(prev==x*2) {
                if(v[x*2+1]<d) d-= v[x*2+1];
                else {
                    x=x*2+1; break;
                }
            }
            prev=x;
            x/=2;
        }

//        cout<<x<<"@"<<d<<" ";
        if(x==0) {
//            cout<<pointer+1<<"@"<<d<<" ";
            return pointer=leftPos(1, d)-N;
        }
        return pointer=leftPos(x, d)-N;
    }
};

signed main() {
	// ifstream fileIn("sample_in.txt");
	// ofstream fileOut("sample_in.txt");
	// cin.rdbuf(fileIn.rdbuf());
    // cout.rdbuf(fileOut.rdbuf());
	fastIO;
	int TT=1;
//	cin>>TT;
	for(int tt=1;tt<=TT;tt++) {
	    int n,k; cin>>n>>k;
	    segT tree = segT(n);
//	    tree.print();

        while(tree.size()!=0) {
            int x= tree.jump(k+1);
            tree.remove(x);
	        cout<<x+1<<" ";
//	        tree.print();
	    }
	}

	return 0;
}
