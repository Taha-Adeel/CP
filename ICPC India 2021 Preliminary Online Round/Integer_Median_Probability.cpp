#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()        { std::sort(this->begin(), this->end()); }
    void sort_dsc()    { std::sort(this->begin(), this->end(), greater<T>()); }
    auto sum()         { T sum = 0; for(auto& i: *this) sum += i; return sum; }
    auto freqs()       { map<T, int> freq; for(auto& i: *this) freq[i]++; return freq; }
    auto indices()     { int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii; }
    auto prefix_sums() { int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps; }
    friend ostream& operator<<(ostream& out, const V<T>& v) { for(auto& i: v) out << i << ' '; return out; }
    friend istream& operator>>(istream& in, V<T>& v)        { for(auto& i: v) in >> i; return in; }
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)     for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)    for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)     for(int i = (int)n-1; i >= 0; --i)
#define all(v)        v.begin(), v.end()
#define rall(v)       v.rbegin(), v.rend()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 998244353;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

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
    return (x % MOD * mod_inverse(y)) % MOD;
}

// Precompute factorials to be used for nCr calculations
#define MxN int(5e5 + 5)
ll factorial[MxN];
void calc_factorials(){
    factorial[0] = 1;
    for(ll i = 1; i < MxN; i++)
        factorial[i] = (factorial[i - 1] * i) % MOD;
}

// nCr (mod MOD)
ll mod_nCr(ll n, ll r){
    return mod_div(factorial[n], factorial[r] * factorial[n-r]);
}

void solve(){
    int n, m; cin >> n >> m;

    // If n is odd, probability is 1
    if(n%2 == 1) {cout << 1; return;}

    // n is even now
    ll k = n/2 - 1;

    // Precompute summation y values
    V<ll> summation(m+3, 0);
    for(int y = m; y > 0; y--)
        summation[y] = (summation[y+2] + mod_pow(m - y + 1, k)) % MOD;
    
    ll ans = 0;
    FOR1(x, m){
        ans += mod_pow(x, k) * summation[x+2] * 2 % MOD;
        ans += mod_pow(x, k) * mod_pow(m - x + 1, k) % MOD;
        ans %= MOD;
    }
    ans = mod_div(ans, mod_pow(m, n));

    cout << ans;
}

int main(){
    FAST;
    calc_factorials();
    solve();
    cout << nl;
    
    return 0;
}