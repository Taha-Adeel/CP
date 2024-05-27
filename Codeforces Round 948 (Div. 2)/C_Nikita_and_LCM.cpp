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

vi primes; // Primes uptil sqrt(10^9)
void sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.pb(i);
    }
}

V<pii> getPrimeFactors(int n) {
    V<pii> factors;
    for(auto& p: primes) {
        if(p*p > n) break;
        if(n%p == 0) {
            int cnt = 0;
            while(n%p == 0) {
                n /= p;
                cnt++;
            }
            factors.pb({p, cnt});
        }
    }
    if(n > 1) factors.pb({n, 1});
    return factors;
}

void setDivisors(vi& divisors, int i, int n, const V<pii>& factors) {
    if(i == factors.size()) {
        divisors.pb(n);
        return;
    }
    auto [p, cnt] = factors[i];
    FOR1(j, cnt) {
        setDivisors(divisors, i+1, n, factors);
        n *= p;
    }
    setDivisors(divisors, i+1, n, factors);
}

map<int, vi> divisors_dp;
vi getDivisors(int n) {
    if(divisors_dp.count(n)) return divisors_dp[n];
    auto factors = getPrimeFactors(n);
    vi divisors;
    setDivisors(divisors, 0, 1, factors);
    sort(divisors.begin(), divisors.end());
    return divisors_dp[n] = divisors;
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    a.sort();
    set<int> a_set(all(a));
    ll lcm_all = 1;
    FOR (i, n) {
        if (lcm_all <= 1e9) {
            lcm_all = lcm(lcm_all, a[i]);
        }
    }
    if (lcm_all > 1e9 || a_set.count(lcm_all) == 0) {
        cout << n;
        return;
    }
    
    ll ans = 0;
    for (int x: getDivisors(lcm_all)) {
        if (a_set.count(x)) continue;
        ll lcm_cur = 1, cur_ans = 0;
        FOR (i, n) {
            if (x % a[i] == 0) {
                lcm_cur = lcm(lcm_cur, a[i]);
                cur_ans++;
            }
        }
        if (lcm_cur == x) {
            ans = max(ans, cur_ans);
        }
    }

    cout << ans;
}

int main() {
    sieve(sqrt(1e9) + 5);
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
        cout << nl;
    }
    
    return 0;
}