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
    int subtree_size = 1;
    ll subtree_imp = 0;
    int parent = -1;
    set<pii> heavy_sons; // {-weight, index}
    set<int> adj_list;
};

void dfs(int root, V<Node>& tree) {
    for(auto& i: tree[root].adj_list) {
        if(i == tree[root].parent) continue;
        tree[i].parent = root;
        dfs(i, tree);
        tree[root].subtree_size += tree[i].subtree_size;
        tree[root].subtree_imp += tree[i].subtree_imp;
        tree[root].heavy_sons.insert({-tree[i].subtree_size, i});
    }
}

void solve() {
    int n, m; cin >> n >> m;
    V<Node> tree(n);
    FOR(i, n) cin >> tree[i].subtree_imp;
    FOR(i, n-1) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].adj_list.insert(v);
        tree[v].adj_list.insert(u);
    }

    dfs(0, tree);

    FOR(i, m) {
        int t, x; cin >> t >> x; x--;
        if(t == 1) {
            cout << tree[x].subtree_imp << nl;
        }
        else {
            if(tree[x].subtree_size == 1) continue;
            int fa_x = tree[x].parent, son_x = tree[x].heavy_sons.begin()->second;

            tree[fa_x].adj_list.erase(x);
            tree[fa_x].adj_list.insert(son_x);
            tree[fa_x].heavy_sons.erase({-tree[x].subtree_size, x});
            
            tree[x].parent = son_x;
            tree[x].subtree_size -= tree[son_x].subtree_size;
            tree[x].subtree_imp -= tree[son_x].subtree_imp;
            tree[x].adj_list.erase(fa_x);
            tree[x].heavy_sons.erase({-tree[son_x].subtree_size, son_x});

            tree[son_x].parent = fa_x;
            tree[son_x].subtree_size += tree[x].subtree_size;
            tree[son_x].subtree_imp += tree[x].subtree_imp;
            tree[son_x].adj_list.insert(fa_x);
            tree[son_x].heavy_sons.insert({-tree[x].subtree_size, x});

            tree[fa_x].heavy_sons.insert({-tree[son_x].subtree_size, son_x});
        }
    }
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}