#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define mp make_pair
#define fs first
#define sn second
#define cor(x) (((x%mod)+mod)%mod)
#define vec(T) vector<T>
#define printv(v) for(auto i: v)cout<<i<<" ";cout<<"\n";
#define scanv(v) for(auto& i: v)cin>>i;
#define ast(v,n) assert(v.size()==n)
 
typedef long long int ll;
 
template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const int mod = 1e9+7;
 
//void precomp(){}
int add(int x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}
 
int mul(int x, int y){
    return (x * 1ll * y) % mod;
}
 
int binpow(int x, int y){
    int z = 1;
    while(y){
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}
 
int inv(int x){
    return binpow(x, mod - 2);
}
 
int divide(int x, int y){
    return mul(x, inv(y));
}

const int N = 1e6+7;
 
int fact[N];
 
void precomp(){
    fact[0] = 1;
    for(int i = 1; i < N; i++)
    fact[i] = mul(fact[i - 1], i);
}
 
int P(int n, int k){
	if(n<k)return 0;
    return divide(fact[n], fact[n - k]);
}

int C(int n, int k){
	if(n<k)return 0;
	return divide(fact[n],mul(fact[k],fact[n-k]));
}

void solve(){
    vector<int> v(26,0);
    string s;
    cin>>s;

    for(auto i: s){
    	v[i-'a']++;
    }

    int res=fact[s.size()];
    for(auto i: v){
    	res=divide(res,fact[i]);
    }

    cout<<res<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);

    precomp();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // time_t start,end;
    // time(&start);
    
    //int tc;cin>>tc;while(tc--)
    solve();
    
    // time(&end);

    // double time_taken = double(end-start);
    // cout<<"Time taken by program is : "<<fixed<<time_taken<<setprecision(5)<<" sec.\n";
    
    return 0;
}