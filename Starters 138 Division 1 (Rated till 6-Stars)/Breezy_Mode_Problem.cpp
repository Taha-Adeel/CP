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
    vi a(n); cin >> a;

    auto freqs = a.freqs();

    vll freq_vals;
    for (auto& [x, f]: freqs) {
        freq_vals.pb(f);
    }
    freq_vals.sort_dsc();
    freq_vals.pb(0);

    ll ans = 0, cnt = 0, cur_freq = freq_vals[0];
    while (cnt < freq_vals.size() and cur_freq) {
        while (cnt < freq_vals.size() && cur_freq == freq_vals[cnt]) {
            cnt++;
        }
        ans += cur_freq * cnt;
        cur_freq--;
    }

    FOR (_, q) {
        int p, x; cin >> p >> x; p--;

        ans -= freqs[a[p]];
        freqs[a[p]]--;
        a[p] = x;
        freqs[a[p]]++;
        ans += freqs[a[p]];

        cout << ans << nl;
    }
}

int main() {
    FAST;
    solve();
    
    return 0;
}