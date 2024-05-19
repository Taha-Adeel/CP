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

ll delta(V<string>& a, V<string>& b) {
    int n = a.size(), m = a[0].size();
    ll res = 0;
    FOR(i, n) FOR(j, m) res += a[i][j] != b[i][j];
    return res;
}

struct Node {
    int parent = -1;
    V<pll> adj_list;
};

// Get MST edge weights using kruskal's algorithm
pair<ll, V<Node>> kruskal(V<Node>& graph, ll c) {
    ll n = graph.size();
    V<tuple<ll, ll, ll>> edges;
    FOR (i, n) {
        for (auto& [v, w]: graph[i].adj_list) {
            edges.pb({w, i, v});
        }
    }
    sort(all(edges));

    V<ll> parent(n);
    iota(all(parent), 0);

    function<ll(ll)> find = [&](ll u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    };

    function<void(ll, ll)> unite = [&](ll u, ll v) {
        u = find(u);
        v = find(v);
        if (u != v) parent[u] = v;
    };

    ll res = 0;
    V<Node> mst(n);
    for (auto& [w, u, v]: edges) {
        if (find(u) != find(v)) {
            res += min(w, c);
            mst[u].adj_list.pb({v, w});
            mst[v].adj_list.pb({u, w});
            unite(u, v);
        }
    }

    return {res, mst};
}

void dfs(V<Node>& graph, V<bool>& visited, int u, vi& order) {
    order.pb(u);
    visited[u] = true;
    for (auto& [v, w]: graph[u].adj_list) {
        if (!visited[v]) {
            graph[v].parent = u;
            dfs(graph, visited, v, order);
        }
    }
}

void solve() {
    ll n, m, k, w; cin >> n >> m >> k >> w;
    V<V<string>> levels(k, V<string>(n)); cin >> levels;

    V<Node> graph(k);
    FOR (i, k) {
        FOR (j, k) {
            if (i == j) continue;
            ll diff = delta(levels[i], levels[j]);
            graph[i].adj_list.pb({j, w * diff});
        }
    }

    auto [res, mst] = kruskal(graph, n * m);
    res += n * m;

    V<bool> visited(k, false);
    vi order;
    dfs(mst, visited, 0, order);

    cout << res << nl;
    FOR (i, k) {
        cout << order[i] + 1 << ' ';
        if (mst[order[i]].parent == -1 || delta(levels[order[i]], levels[mst[order[i]].parent]) * w > n * m) {
            cout << 0 << nl;
        } else {
            cout << mst[order[i]].parent + 1 << nl;
        }
    }
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}