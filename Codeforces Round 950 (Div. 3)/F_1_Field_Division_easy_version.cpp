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

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vll r(k), c(k);
    FOR (i, k) {
        cin >> r[i] >> c[i];
    }

    map<ll, pll> row_min;
    FOR (i, k) {
        if (row_min.count(r[i]) == 0 or c[i] < row_min[r[i]].first) {
            row_min[r[i]] = {c[i], i};
        }
    }

    ll ans = 0, cur_min = m + 1;
    vi is_suffix_min(k, 0);
    for (auto it = row_min.rbegin(); it != row_min.rend(); it++) {
        auto [row, p] = *it;
        auto [col, idx] = p;
        if (col < cur_min) {
            ans += (cur_min - col) * (n - row);
            cur_min = col;
            is_suffix_min[idx] = 1;
        }
    }
    ans += (cur_min - 1) * n;

    cout << ans << nl;
    cout << is_suffix_min;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
        cout << nl;
    }
    
    return 0;
}