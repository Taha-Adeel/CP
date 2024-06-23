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

struct Node {
    bool visited = false;
    set<int> adj_list;
    int t_in = -1, low = -1;
    int child_cnt = 0;
};

void dfs(int root, int parent, V<Node>& graph, map<pii,bool>& edges, int timer = 0) {
    graph[root].visited = true;
    graph[root].t_in = graph[root].low = timer++;
    bool parent_skipped = false;
    for (int child: graph[root].adj_list) {
        if (child == parent && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (graph[child].visited) {
            graph[root].low = min(graph[root].low, graph[child].t_in);
        } else {
            dfs(child, root, graph, edges, timer);
            graph[root].low = min(graph[root].low, graph[child].low);
            if (graph[child].low > graph[root].t_in) {
                edges[{root, child}] = edges[{child, root}] = true;
            }
        }
    }
}

class DSU {
public:
    vi parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(all(parent), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) swap(x, y);
            parent[y] = x;
            size[x] += size[y];
        }
    }

    int size_of(int x) {
        return size[find(x)];
    }
};

void dfs2(int root, int parent, V<Node>& graph) {
    graph[root].visited = true;
    for (int child: graph[root].adj_list) {
        if (child == parent) continue;
        dfs2(child, root, graph);
        graph[root].child_cnt += graph[child].child_cnt;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    V<Node> graph(n);
    map<pii, bool> edges;
    FOR (i, m) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].adj_list.insert(v);
        graph[v].adj_list.insert(u);
        edges[{u, v}] = edges[{v, u}] = false;
    }

    dfs(0, -1, graph, edges);

    DSU dsu(n);
    for (auto& [edge, is_bridge]: edges) {
        if (!is_bridge) {
            dsu.unite(edge.first, edge.second);
        }
    }

    V<Node> new_graph(n);
    for (auto& [edge, is_bridge]: edges) {
        auto [u, v] = edge;
        if (is_bridge) {
            u = dsu.find(u);
            v = dsu.find(v);
            new_graph[u].adj_list.insert(v);
            new_graph[v].adj_list.insert(u);
            new_graph[u].child_cnt = dsu.size_of(u);
            new_graph[v].child_cnt = dsu.size_of(v);
        }
    }

    FOR (i, n) {
        if (!new_graph[i].visited && i == dsu.find(i)) {
            dfs2(i, -1, new_graph);
        }
    }

    ll ans = 1LL * n * (n - 1) / 2;
    for (auto [edge, is_bridge]: edges) {
        auto [u, v] = edge;
        if (is_bridge) {
            u = dsu.find(u);
            v = dsu.find(v);
            ll sz1 = min(new_graph[u].child_cnt, new_graph[v].child_cnt);
            ll sz2 = n - sz1;
            ans = min(ans, 1LL * sz1 * (sz1 - 1) / 2 + 1LL * sz2 * (sz2 - 1) / 2);
        }
    }

    cout << ans;
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