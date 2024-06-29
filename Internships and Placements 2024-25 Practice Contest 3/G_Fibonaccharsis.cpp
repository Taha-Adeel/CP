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

#define int long long
#define FOR(i, n)     for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)    for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)     for(int i = (int)n-1; i >= 0; --i)
#define all(v)        v.begin(), v.end()
#define pb push_back

constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

vi fibonaci;
void precompute() {
    fibonaci = {0, 1};
    while (fibonaci.back() < 2e5) {
        fibonaci.pb(fibonaci.back() + fibonaci[fibonaci.size() - 2]);
    }
}

// Returns {1, x, y} such that a * x + b * y = 1
tuple<int, int, int> extended_euclid(int a, int b) {
    if (b == 0) return {a, 1, 0};
    int g, x, y;
    tie(g, x, y) = extended_euclid(b, a % b);
    return {g, y, x - (a / b) * y};
}

void solve() {
    int n, k; cin >> n >> k;

    if (k > fibonaci.size()) {
        cout << 0;
        return;
    }

    int a = fibonaci[k - 2], b = fibonaci[k - 1];
    int g = gcd(a, b);

    if (n % g != 0) {
        cout << 0;
        return;
    }

    a /= g;
    b /= g;
    n /= g;

    auto [g1, x, y] = extended_euclid(a, b);
    x *= n;
    y *= n;

    // Smallest x0 such that x0 >= 0
    int x0 = (x >= 0) ? x % b : (x % b + b) % b;
    int y0 = (n - a * x0) / b;

    if (y0 < 0 or x0 > y0) {
        cout << 0;
        return;
    }

    cout << (y0 - x0) / (a + b) + 1;
}

signed main() {
    precompute();
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
        cout << nl;
    }
    
    return 0;
}