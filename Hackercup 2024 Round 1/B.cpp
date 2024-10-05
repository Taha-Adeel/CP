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
#define pb push_back

constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

constexpr int MAXN = 2e7 + 100;
vll get_primes(ll n) {
    vll lp(n+1), primes;
    for (ll i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.pb(i);
        }
        for (ll j = 0; j < primes.size() && primes[j] <= lp[i] && i*primes[j] <= n; ++j) {
            lp[i*primes[j]] = primes[j];
        }
    }
    vll twin_primes;
    twin_primes.pb(2);
    for (int i = 1; i < primes.size(); ++i) {
        if (primes[i] - primes[i-1] == 2) {
            twin_primes.pb(primes[i-1]);
        }
    }
    return twin_primes;
}
vll twin_primes = get_primes(MAXN);

void solve() {
    int n; cin >> n;

    if (n < 5) {
        cout << 0;
        return;
    }

    int cnt = upper_bound(all(twin_primes), n-2) - twin_primes.begin();
    cout << cnt;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        cout << "Case #" << t+1 << ": ";
        solve();
        cout << nl;
    }
    
    return 0;
}