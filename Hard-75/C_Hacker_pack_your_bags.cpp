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
    int n, x; cin >> n >> x;
    vi l(n), r(n), c(n); FOR (i, n) cin >> l[i] >> r[i] >> c[i];

    map<int, V<pii>> mp;
    FOR (i, n) {
        mp[r[i] - l[i] + 1].pb({i, c[i]});
    }

    for (auto& [k, v]: mp) {
        sort(all(v), [&](pii i, pii j) { return l[i.first] < l[j.first]; });
        for (int i = v.size() - 2; i >= 0; i--) {
            v[i].second = min(v[i].second, v[i + 1].second);
        }
    }

    int ans = INT_MAX;
    for (auto& [k, v1]: mp) {
        if (mp.count(x - k) == 0) continue;
        auto& v2 = mp[x - k];
        for (int i = 0, j = 0; i < v1.size(); i++) {
            while (j < v2.size() && l[v2[j].first] <= r[v1[i].first]) j++;
            if (j < v2.size()) {
                ans = min(ans, c[v1[i].first] + v2[j].second);
            }
        }
    }

    cout << (ans == INT_MAX ? -1 : ans);
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}