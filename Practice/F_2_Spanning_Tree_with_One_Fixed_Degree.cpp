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
    bool adj_root = false;
    int parent = -1;
    vi adj_list;
};

void dfs(int u, V<Node>& graph) {
    for (int v : graph[u].adj_list) {
        if (v == graph[u].parent || graph[v].parent != -1) continue;
        if ((u == 0 && !graph[v].adj_root) || (u != 0 && graph[v].adj_root)) continue;
        graph[v].parent = u;
        dfs(v, graph);
    }
}

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
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            if (size[x] < size[y]) swap(x, y);
            parent[y] = x;
            size[x] += size[y];
            --components;
        }
    }
};

void solve() {
    int n, m, d; cin >> n >> m >> d;
    DSU dsu(n);
    V<Node> graph(n);
    FOR (i, m) {
        int u, v; cin >> u >> v; --u, --v;
        graph[u].adj_list.pb(v);
        graph[v].adj_list.pb(u);
        if (u != 0 && v != 0) {
            dsu.unite(u, v);
        }
    }

    if (d < dsu.components - 1 || d > graph[0].adj_list.size()) {
        cout << "NO";
        return;
    }

    set<int> components;
    for (int v: graph[0].adj_list) {
        if (!components.count(dsu.find(v))) {
            components.insert(dsu.find(v));
            graph[v].adj_root = true;
            d--;
        }
    }

    for (int v: graph[0].adj_list) {
        if (d == 0) break;
        if (graph[v].adj_root == false) {
            graph[v].adj_root = true;
            d--;
        }
    }

    dfs(0, graph);

    cout << "YES" << nl;
    FOR1(i, n-1) {
        cout << graph[i].parent + 1 << ' ' << i + 1 << nl;
    }
}

int main() {
    FAST;
    solve();
    
    return 0;
}