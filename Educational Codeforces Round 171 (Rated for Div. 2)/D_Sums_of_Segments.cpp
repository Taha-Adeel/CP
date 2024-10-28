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
    int n; cin >> n;
    vll a(n); cin >> a;

    vll sum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        sum[i] = sum[i + 1] + (n - i) * a[i];
    }
    vll ps = a.prefix_sums();
    vll ps_sum = sum.prefix_sums();
    
    auto ans = [&](ll x) {
        // Find largest i s.t. (i * (2 * n - i + 1)) / 2 <= x;
        ll l = 0, r = n;
        while (l < r) {
            ll m = (l + r + 1) / 2;
            if ((m * (2 * n - m + 1)) / 2 <= x) {
                l = m;
            } else {
                r = m - 1;
            }
        }

        ll rem = x - (l * (2 * n - l + 1)) / 2;
        if (rem == 0) {
            return ps_sum[l];
        }

        ll al = l + 1, ar = al + rem - 1, bl = ar + 1;
        ll res = ps_sum[l] + (sum[al - 1] - (sum[bl - 1] + (ps[ar] - ps[al - 1]) * (n - bl + 1)));

        return res;
    };

    int q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r;
        cout << ans(r) - ans(l - 1) << nl;
    }
}

int main() {
    FAST;
    int T = 1;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}