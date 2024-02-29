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
    int leaf_cnt = 0;
    int depth = 0;
    int min_leaf_depth = INT_MAX;
    bool good = false;
    int ans1 = 0; // Max leaves u can reach and still return to root
    int ans2 = 1; // Max leaves when not returning to root (>= ans1)
    int ans3 = 0; // Max leaves u can reach and still return to current node
    vi adj;
};

void dfs1(int root, int parent, V<Node>& tree) {
    for (int child: tree[root].adj) {
        if (child == parent) continue;
        tree[child].depth = tree[root].depth + 1;
        dfs1(child, root, tree);
        tree[root].leaf_cnt += tree[child].leaf_cnt;
        tree[root].min_leaf_depth = min(tree[root].min_leaf_depth, tree[child].min_leaf_depth);
    }
    if (tree[root].adj.size() == 1) {
        tree[root].leaf_cnt = 1;
        tree[root].min_leaf_depth = tree[root].depth;
    }
}

void dfs2(int root, int parent, V<Node>& tree, int k) {
    for (int child: tree[root].adj) {
        if (child == parent) continue;
        if (tree[child].min_leaf_depth <= tree[root].depth + k) {
            tree[child].good = true;
        }
        dfs2(child, root, tree, k);
        if (tree[child].good) {
            tree[root].ans1 += tree[child].ans1;
        }
    }
    if (tree[root].adj.size() == 1 && root != 0) {
        tree[root].ans1 = 1;
        tree[root].ans3 = 1;
    }
}

void dfs3(int root, int parent, V<Node>& tree) {
    int ans3_sum = 0;
    for (int child: tree[root].adj) {
        if (child == parent) continue;
        dfs3(child, root, tree);
        ans3_sum += tree[child].ans3;
    }
    for (int child: tree[root].adj) {
        if (child == parent) continue;
        tree[root].ans2 = max(tree[root].ans2, ans3_sum - tree[child].ans3 + tree[child].ans2);
    }
}

void solve() {
    int n, k; cin >> n >> k;
    V<Node> tree(n);
    FOR(i, n - 1) {
        int u, v; cin >> u >> v; u--; v--;
        tree[u].adj.pb(v);
        tree[v].adj.pb(u);
    }

    dfs1(0, -1, tree);
    
    tree[0].good = true;
    dfs2(0, -1, tree, k);

    dfs3(0, -1, tree);

    cout << tree[0].ans2;
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