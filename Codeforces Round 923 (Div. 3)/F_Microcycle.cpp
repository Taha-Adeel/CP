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
public:
    vi parent, size;
    int components;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(all(parent), 0);
        components = n;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void join(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            if (size[x] < size[y]) swap(x, y);
            parent[y] = x;
            size[x] += size[y];
            components--;
        }
    }
};

void dfs(int root, int dest, V<vi>& adj, vi& parent) {
    if (root == dest) return;
    for (int u: adj[root]) {
        if (parent[u] == -1) {
            parent[u] = root;
            dfs(u, dest, adj, parent);
        }
    }
}

vi get_path(int u, int v, vi& parent) {
    vi path;
    while (u != v) {
        path.pb(v);
        v = parent[v];
    }
    path.pb(u);
    reverse(all(path));
    return path;
}

void solve() {
    int n, m; cin >> n >> m;
    V<array<int, 3>> edges(m);
    FOR(i, m) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        edges[i] = {w, u, v};
    }

    DSU dsu(n);
    edges.sort_dsc();
    auto last_edge = edges[0];
    for (auto& [w, u, v]: edges) {
        if (dsu.find(u) != dsu.find(v)) {
            dsu.join(u, v);
        } else {
            last_edge = {w, u, v};
        }
    }

    V<vi> adj(n);
    for (auto& [w, u, v]: edges) {
        if (u == last_edge[1] and v == last_edge[2]) continue;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi parent(n, -1);
    parent[last_edge[1]] = last_edge[1];

    dfs(last_edge[1], last_edge[2], adj, parent);

    vi path = get_path(last_edge[1], last_edge[2], parent);

    cout << last_edge[0] << ' ' << path.size() << nl;
    for (int u: path) cout << u + 1 << ' ';
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