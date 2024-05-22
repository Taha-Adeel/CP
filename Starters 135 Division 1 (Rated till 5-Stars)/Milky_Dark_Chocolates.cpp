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
    int n, k; cin >> n >> k;
    vll a(n), b(n); cin >> a >> b;

    V<vll> dp(n, vll(k, 1e15)); // dp_a[i][k] = min overall mood after eating the first i chocolates in k days.
    vll ps_a = a.prefix_sums(), ps_b = b.prefix_sums();
    vll min_a(k, 1e15), min_b(k, 1e15);
    FOR (i, n) {
        dp[i][0] = min(ps_a[i + 1], ps_b[i + 1]);
        min_a[0] = min(min_a[0], dp[i][0] - ps_a[i + 1]);
        min_b[0] = min(min_b[0], dp[i][0] - ps_b[i + 1]);
        for (int j = 1; j < k; j++) {
            if (i == 0) continue;
            dp[i][j] = min(ps_a[i + 1] + min_a[j - 1], ps_b[i + 1] + min_b[j - 1]);
            min_a[j] = min(min_a[j], dp[i][j] - ps_a[i + 1]);
            min_b[j] = min(min_b[j], dp[i][j] - ps_b[i + 1]);
        }
    }

    cout << dp[n - 1][k - 1];
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