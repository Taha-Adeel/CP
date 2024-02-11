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

#define FOR(i, n)     for (int i = 0; i < (int)n; ++i)
#define FOR1(i, n)    for (int i = 1; i <= (int)n; ++i)
#define ROF(i, n)     for (int i = (int)n-1; i >= 0; --i)
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
    vi a(n); cin >> a;

    vll dp_left(n, 0), dp_right(n, 0);
    vi max_left(n, 0), max_right(n, 0);
    int cur_max = 0;
    FOR(i, n) {
        if (i) dp_left[i] = dp_left[i - 1];
        if (a[i] <= cur_max) {
            cur_max++;
            dp_left[i] += cur_max - a[i];
        } else {
            cur_max = a[i];
        }
        max_left[i] = cur_max;  
    }

    cur_max = 0;
    ROF(i, n) {
        if (i < n - 1) dp_right[i] = dp_right[i + 1];
        if (a[i] <= cur_max) {
            cur_max++;
            dp_right[i] += cur_max - a[i];
        } else {
            cur_max = a[i];
        }
        max_right[i] = cur_max;
    }

    ll ans = LLONG_MAX;
    FOR (i, n) {
        if (max_left[i] > max_right[i]) {
            if (i < n - 1) ans = min(ans, dp_left[i] + dp_right[i + 1]);
            else ans = min(ans, dp_left[i]);
        } else {
            if (i) ans = min(ans, dp_left[i - 1] + dp_right[i]);
            else ans = min(ans, dp_right[i]);
        }
    }

    cout << ans;
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}