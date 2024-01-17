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

class DSU {
    int n;
    vi parent, size;
public:
    DSU(int n) {
        this->n = n;
        parent.resize(n);
        size.resize(n);
        FOR(i, n) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int get_size(int x) {
        return size[find(x)];
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vi h(n); cin >> h;
    V<array<int, 3>> edges(m);
    FOR(i, m) {
        int u, v; cin >> u >> v; --u, --v;
        edges[i] = {max(h[u], h[v]), u, v};
    }
    int q; cin >> q;
    V<array<int, 4>> queries;
    FOR(i, q) {
        int a, b, e; cin >> a >> b >> e; --a, --b;
        queries.pb({h[a] + e, a, b, i});
    }

    // Offline queries
    sort(all(queries));
    sort(all(edges));
    
    DSU dsu(n);
    int ei = 0;
    V<bool> ans(q);
    for(auto& [qh, a, b, i]: queries) {
        while(ei < m && edges[ei][0] <= qh) {
            dsu.unite(edges[ei][1], edges[ei][2]);
            ++ei;
        }
        ans[i] = dsu.same(a, b);
    }

    FOR(i, q) cout << (ans[i] ? "YES" : "NO") << nl;
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