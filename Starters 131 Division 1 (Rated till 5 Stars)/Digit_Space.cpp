#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

vi get_digit_space(int x) {
    string s = to_string(x);
    sort(all(s));

    vi res;
    if (s[0] != '0') {
        res.pb(stoi(s));
    }

    while(next_permutation(all(s))) {
        if (s[0] == '0') continue;
        res.pb(stoi(s));
    }

    return res;
}

constexpr int MAXN = 1e7;
int lpf[MAXN + 1];
void precompute() {
    iota(lpf, lpf + MAXN + 1, 0);

    // Seive for largest prime factor
    for (int i = 2; i <= MAXN; i++) {
        if (lpf[i] == i) {
            for (int j = i * 2; j <= MAXN; j += i) {
                lpf[j] = i;
            }
        }
    }
}

vi get_prime_factors(int x) {
    vi res;
    while (x > 1) {
        int p = lpf[x];
        res.pb(p);
        while (x % p == 0) {
            x /= p;
        }
    }

    return res;
}

void solve() {
    int x, y; cin >> x >> y;

    vi dx = get_digit_space(x), dy = get_digit_space(y);

    set<int> factors_dx;
    for (int a: dx) {
        vi factors_a = get_prime_factors(a);
        factors_dx.insert(all(factors_a));
    }

    int ans = 1;
    for (int b: dy) {
        for (int p: get_prime_factors(b)) {
            if (factors_dx.count(p)) {
                ans = max(ans, p);
                break;
            }
        }
    }

    cout << ans;
}

int main() {
    precompute();
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
        cout << nl;
    }
    
    return 0;
}