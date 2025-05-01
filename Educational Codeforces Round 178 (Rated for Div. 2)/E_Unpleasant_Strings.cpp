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
    string s; cin >> s;

    vi ans(n + 1, n);
    ans[n] = 0;
    vi latest_idx(k, n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < k; j++) {
            ans[i] = min(ans[i], ans[latest_idx[j]] + 1);
        }
        latest_idx[s[i] - 'a'] = i;
    }

    V<vi> next_idx(n + 2, vi(k, n));
    for (int i = n - 1; i >= 0; i--) {
        next_idx[i] = next_idx[i + 1];
        next_idx[i][s[i] - 'a'] = i;
    }

    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        int cur = -1;
        for (int i = 0; i < t.size(); i++) {
            cur = next_idx[cur + 1][t[i] - 'a'];
            if (cur == n) break;
        }
        cout << ans[cur] << nl;
    }
}

int main() {
    FAST;
    solve();
    
    return 0;
}