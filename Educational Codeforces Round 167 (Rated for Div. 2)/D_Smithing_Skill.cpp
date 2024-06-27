#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()        { std::sort(this->begin(), this->end()); }
    void sort_dsc()    { std::sort(this->begin(), this->end(), greater<T>()); }
    auto sum()         { T sum = 0; for(auto& i: *this) sum += i; return sum; }
    auto freqs()       { map<T, long long> freq; for(auto& i: *this) freq[i]++; return freq; }
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

void solve() {
    int n, m; cin >> n >> m;
    vll a(n), b(n), c(m); cin >> a >> b >> c;

    vll d(n);
    FOR (i, n) {
        d[i] = a[i] - b[i];
    }

    vi idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) {
        return d[i] < d[j] or (d[i] == d[j] and a[i] < a[j]);
    });

    map<ll, ll> freqs_old = c.freqs(), freqs_new;

    ll ans = 0, min_a = INT_MAX;
    for (auto i: idx) {
        if (a[i] >= min_a) continue;
        min_a = a[i];
        for (auto& [cj, f]: freqs_old) {
            if (a[i] <= cj) {
                ll k = (cj - a[i] + d[i]) / d[i];
                ans += 2 * k * f;
                freqs_new[cj - k * d[i]] += f;
            } else {
                freqs_new[cj] += f;
            }
        }
        freqs_old = freqs_new;
        freqs_new = {};
    }

    cout << ans;
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}