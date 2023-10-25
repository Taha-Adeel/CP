#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()            {std::sort(this->begin(), this->end());}
    void sort_dsc()     {std::sort(this->begin(), this->end(), greater<T>());}
    auto sum()             {T sum = 0; for(auto& i: *this) sum += i; return sum;}
    auto freqs()         {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
    auto indices()        {int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
    auto prefix_sums()     {int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)                for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

class DSU {
    const int n; // Number of nodes
    int nC; // Number of components
    std::vector<int> p;  // Parent
    std::vector<int> sz;  // Size of the component
public:
    DSU(int n): n(n), nC(n) { p.resize(n, -1); sz.resize(n, 1); }
    bool isLeader(int u) const { return p[u] < 0; }
    int size(int u) { return sz[find(u)]; }
    int numComp() const { return nC; }

    int find(int u) { 
        if (isLeader(u)) return u;
        return p[u] = find(p[u]);
    }

    bool merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) std::swap(u, v);
        p[v] = u; nC--;
        sz[u] += sz[v]; sz[v] = 0;
        return true;
    }
};

// x ^ y (mod MOD) (using binary exponentiation)
ll mod_pow(ll a, ll b){
    if(b == 0) return 1;
    return mod_pow(a * a % MOD, b/2) * (b % 2 ? a : 1) % MOD;
}

// Using Fermat's Little Theorem (only works for prime MOD)
ll mod_inverse(ll x) {
    return mod_pow(x % MOD, MOD-2);
}

// x/y (mod MOD)
ll mod_div(ll x, ll y){
    return (x * mod_inverse(y)) % MOD;
}

// Precompute factorials to be used for nCr calculations
#define MxN 1000001
ll factorial[MxN];
void calc_factorials(){
    factorial[0] = 1;
    for(ll i = 1; i < MxN; i++)
        factorial[i] = (factorial[i - 1] * i) % MOD;
}

void solve(){
    int n, m; cin >> n >> m;
    DSU dsu(n);
    FOR(i, m){
        int u, v; cin >> u >> v; --u, --v;
        dsu.merge(u, v);
    }
    vi a(n); cin >> a;

    map<int, map<int, int>> component_freqs;
    map<int, int> component_sizes;
    FOR(i, n){
        int component = dsu.find(i);
        component_freqs[component][a[i]]++;
        component_sizes[component]++;
    }

    ll ans = factorial[n];
    for(auto& [component, freqs]: component_freqs){
        for(auto& [num, freq]: freqs){
            ans = (ans * factorial[freq]) % MOD;
        }
        ans = (ans * mod_inverse(factorial[component_sizes[component]])) % MOD;
    }

    cout << ans;
}

int main(){
    FAST;
    calc_factorials();
    int T;
    cin >> T;
    FOR(t, T){
        solve();
        cout << nl;
    }
    
    return 0;
}