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
    int n, q; cin >> n >> q;

    V<vll> rects(1001, vll(1001, 0));
    FOR(i, n) {
        int h, w; cin >> h >> w;
        rects[h][w] += h * w; 
    }

    V<vll> ps(1001, vll(1001, 0)); // ps[i][j] = sum of grid rects[0..i][0..j]
    FOR1(i, 1000) {
        FOR1(j, 1000) {
            ps[i][j] = ps[i][j - 1] + rects[i][j];
        }
    }
    FOR1(j, 1000) {
        FOR1(i, 1000) {
            ps[i][j] += ps[i - 1][j];
        }
    }

    while(q--) {
        int hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb;

        ll ans = ps[hb - 1][wb - 1];
        ans -= ps[hb - 1][ws];
        ans -= ps[hs][wb - 1];
        ans += ps[hs][ws];

        cout << ans << nl;
    }
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}