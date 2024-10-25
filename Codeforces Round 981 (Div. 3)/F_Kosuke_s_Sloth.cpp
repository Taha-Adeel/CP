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

// Get the nth fibonacci number modulo mod using matrix exponentiation
ll get_fib(ll n, int mod) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    array<ll, 4> F = {1, 1, 1, 0};
    auto mul = [&](array<ll, 4> a, array<ll, 4> b) {
        return array<ll, 4>{ (a[0]*b[0] + a[1]*b[2]) % mod, (a[0]*b[1] + a[1]*b[3]) % mod,
                             (a[2]*b[0] + a[3]*b[2]) % mod, (a[2]*b[1] + a[3]*b[3]) % mod };
    };
    auto pow = [&](array<ll, 4> a, ll n) {
        array<ll, 4> res = {1, 0, 0, 1};
        while (n) {
            if (n & 1) res = mul(res, a);
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    };
    return pow(F, n-1)[0];
}

constexpr int MAXN = 1e5 + 5;
int lpf[MAXN];
void init_lpf() {
    for (int i = 2; i < MAXN; i++) {
        if (lpf[i] == 0) {
            for (int j = i; j < MAXN; j += i) {
                if (lpf[j] == 0) {
                    lpf[j] = i;
                }
            }
        }
    }
}

vi get_divisors(int n) {
    vi divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.pb(i);
            if (i * i != n) {
                divs.pb(n / i);
            }
        }
    }
    divs.sort();
    return divs;
}

int period[MAXN];
void init_period() {
    period[1] = 1; period[2] = 3; period[3] = 4; period[4] = 6; period[5] = 5;
    for (int i = 6; i < MAXN; i++) {
        int p = lpf[i];
        if (p != i) {
            int prev = i / p;
            ll min_period = lcm(period[prev], period[p]);
            for (ll pp = min_period; ; pp += min_period) {
                if (get_fib(pp, i) == 0) {
                    period[i] = pp;
                    break;
                }
            }
        } else {
            if (i % 5 == 1 || i % 5 == 4) {
                for (int d: get_divisors(i - 1)) {
                    if (get_fib(d, i) == 0) {
                        period[i] = d;
                        break;
                    }
                }
            } else {
                for (int d: get_divisors(2 * (i + 1))) {
                    if (get_fib(d, i) == 0) {
                        period[i] = d;
                        break;
                    }
                }
            }
        }
    }
}

void solve() {
    ll n, k; cin >> n >> k;

    cout << (n % MOD) * (period[k] % MOD) % MOD;
}

int main() {
    FAST;
    init_lpf();
    init_period();

    int T; cin >> T;
    FOR(t, T) {
        solve();
        cout << nl;
    }
    
    return 0;
}