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
    vi adj_list;
};

int ans(int root, V<Node>& tree) {
    int n = tree.size();
    vi heights(n, 0);
    auto dfs = [&](auto&& self, int u, int p) -> void {
        for (auto v: tree[u].adj_list) {
            if (v == p) continue;
            self(self, v, u);
            heights[u] = max(heights[u], 1+heights[v]);
        }
    };

    dfs(dfs, root, -1);

    return 2 * (n-1) - heights[root];
}

vi path(int u, int v, V<Node>& tree) {
    int n = tree.size();
    vi parent(n, -1);
    auto dfs = [&](auto&& self, int u, int p) -> void {
        for (auto v: tree[u].adj_list) {
            if (v == p) continue;
            parent[v] = u;
            self(self, v, u);
        }
    };

    dfs(dfs, u, -1);

    vi path;
    while (v != u) {
        path.pb(v);
        v = parent[v];
    }
    path.pb(u);
    reverse(all(path));

    return path;
}

void solve() {
    int n, a, b; cin >> n >> a >> b; --a; --b;
    V<Node> tree(n);
    FOR (i, n-1) {
        int u, v; cin >> u >> v; --u; --v;
        tree[u].adj_list.pb(v);
        tree[v].adj_list.pb(u);
    }

    if (a == b) {
        cout << ans(a, tree);
        return;
    }

    vi path_a = path(b, a, tree);
    int root = path_a[path_a.size() / 2];
    cout << ans(root, tree) + path_a.size() / 2;
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