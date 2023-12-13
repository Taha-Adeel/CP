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
    int n, m; cin >> n >> m;
    V<vi> grid(n, vi(m)); cin >> grid;

    int path_len = n + m - 1;
    if (path_len % 2) { cout << "NO"; return; }

    V<vi> dp_max(n, vi(m, INT_MIN));
    V<vi> dp_min(n, vi(m, INT_MAX));
    dp_max[0][0] = dp_min[0][0] = grid[0][0];
    FOR(i, n) FOR(j, m) {
        if(i) dp_max[i][j] = max(dp_max[i][j], dp_max[i-1][j] + grid[i][j]),
                dp_min[i][j] = min(dp_min[i][j], dp_min[i-1][j] + grid[i][j]);
        if(j) dp_max[i][j] = max(dp_max[i][j], dp_max[i][j-1] + grid[i][j]),
                dp_min[i][j] = min(dp_min[i][j], dp_min[i][j-1] + grid[i][j]);
    }

    if((ll) dp_max[n-1][m-1] * dp_min[n-1][m-1] <= 0) cout << "YES";
    else cout << "NO";
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