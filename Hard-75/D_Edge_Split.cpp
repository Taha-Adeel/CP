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

void dfs(int u, V<V<pii>>& g, V<bool>& vis, vi& dep, vi& par, string& s) {
    vis[u] = true;
    for (auto [v,idx]: g[u]) {
        if (vis[v]) continue;
        dep[v] = dep[u] + 1;
        par[v] = u;
        s[idx] = '1';
        dfs(v, g, vis, dep, par, s);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    V<V<pii>> g(n+1);
    V<pii> edges(m);
    string s(m, '0');
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        edges[i] = {u, v};
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    V<bool> vis(n+1, false);
    V<int> dep(n+1, 0), par(n+1, -1);
    dfs(1, g, vis, dep, par, s);
    map<int, int> cnt;
    for (int i = 0; i < m; i++) {
        if(s[i] == '0') {
            cnt[edges[i].first]++;
            cnt[edges[i].second]++;
        }
    }

    if(cnt.size() == 3) {
        int mn = 2 * n + 5, mx = 0;
        for (auto [_,c]: cnt) {
            mn = min(mn, c);
            mx = max(mx, c);
        }

        if(mn == mx && mn == 2) {
            V<pii> can;
            for (auto [v,_]: cnt) can.push_back({dep[v], v});
            sort(can.rbegin(),can.rend());
            int u = can[0].second;
            int i, j; //replace edge i with edge j
            for (auto [v,idx]: g[u]) {
                if (s[idx] == '0') i = idx;
                else if(v == par[u]) j = idx;
            }
            s[i] = '1';
            s[j] = '0';
        }
    }

    cout << s;
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