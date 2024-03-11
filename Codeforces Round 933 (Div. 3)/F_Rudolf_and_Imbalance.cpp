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
#define int ll
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vi a(n), d(m); cin >> a >> d;
    V<double> f(k); cin >> f;

    d.sort();
    f.sort();

    int max_diff_i = 0, max_diff = a[1] - a[0], max_diff2 = -1;
    for (int i = 1; i < n - 1; i++) {
        if (a[i + 1] - a[i] >= max_diff) {
            max_diff2 = max_diff;
            max_diff = a[i + 1] - a[i];
            max_diff_i = i;
        } else if (a[i + 1] - a[i] > max_diff2) {
            max_diff2 = a[i + 1] - a[i];
        }
    }

    if (max_diff2 == max_diff) {
        cout << max_diff;
        return;
    }

    int l = a[max_diff_i], r = a[max_diff_i + 1];
    double x = l + (r - l) / 2.0;

    int ans = max_diff;
    for (auto& di: d) {
        double req = x - di;
        int pos = lower_bound(all(f), req) - f.begin();
        double diff1 = 1e18, diff2 = 1e18, diff3 = 1e18;
        if (pos > 0) {
            diff1 = abs(f[pos - 1] - req);
        }
        if (pos < k) {
            diff2 = abs(f[pos] - req);
        }
        if (pos + 1 < k) {
            diff3 = abs(f[pos + 1] - req);
        }

        if (min({diff1, diff2, diff3}) == 1e18) {
            continue;
        }

        int pos_f = 0;
        if (diff1 <= diff2 && diff1 <= diff3) {
            pos_f = pos - 1;
        } else if (diff2 <= diff1 && diff2 <= diff3) {
            pos_f = pos;
        } else {
            pos_f = pos + 1;
        }
        
        int new_val = di + f[pos_f];
        if (new_val <= l || new_val >= r) {
            continue;
        }
        int new_diff = max({new_val - l, r - new_val});
        ans = min(ans, new_diff);
    }
    ans = max(ans, max_diff2);

    cout << ans;
}

signed main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
        cout << nl;
    }
    
    return 0;
}