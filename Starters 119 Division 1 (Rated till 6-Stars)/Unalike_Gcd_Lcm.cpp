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

vi seive(int N) {
    vi is_prime(N+1, 1);
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i*i <= N; ++i) {
        if(is_prime[i]) {
            for(int j = i*i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    vi primes;
    FOR1(i, N) if(is_prime[i]) primes.pb(i);
    return primes;
}

vi primes = seive(100000);

vi get_prime_powers(int x) {
    vi prime_powers;
    for(int p: primes) {
        if(p*p > x) break;
        if(x % p == 0) {
            int cnt = 0;
            while(x % p == 0) {
                x /= p;
                cnt++;
            }
            prime_powers.pb(cnt);
        }
    }
    if(x > 1) prime_powers.pb(1);
    return prime_powers;
}

void solve() {
    int x, q; cin >> x >> q;

    vi prime_powers = get_prime_powers(x);
    while (q--) {
        int p; cin >> p;
        if (p == 1) {
            cout << 1 << nl;
            continue;
        }

        ll ans = 1;
        for (int pp: prime_powers) {
            if (pp % p == 0) ans = (ans * 2) % MOD;
        }
        cout << ans << nl;
    }
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}