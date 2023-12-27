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
    int num_leaves = 0;
    int depth = 0;
    vi adj_list;
};

void dfs(int root, int parent, V<Node>& tree) {
    for(auto& child: tree[root].adj_list) {
        if(child == parent) continue;
        tree[child].depth = tree[root].depth + 1;
        dfs(child, root, tree);
        tree[root].num_leaves += tree[child].num_leaves;
    }
    if(tree[root].adj_list.size() == 1 && root != 0) tree[root].num_leaves = 1;
}

void dfs2(int root, int parent, V<Node>& tree, vi& path, int& ans) {
    path.pb(root);
    for(auto& child: tree[root].adj_list) {
        if(child == parent) continue;
        dfs2(child, root, tree, path, ans);
    }

    if(tree[root].adj_list.size() == 1 && root != 0) {
        int tag_node = path[(tree[root].depth + 1) / 2];
        if(tree[tag_node].adj_list.size() > 1 || tag_node == 0)
            ans = max(ans, tree[tag_node].num_leaves);
    }
    path.pop_back();
}

void solve() {
    int n; cin >> n;
    V<Node> tree(n);
    FOR(i, n-1) {
        int u, v; cin >> u >> v; --u, --v;
        tree[u].adj_list.pb(v);
        tree[v].adj_list.pb(u);
    }

    dfs(0, -1, tree);

    vi path;
    int ans = 0;
    dfs2(0, -1, tree, path, ans);

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