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
    int subtree_can_save = 0; // max number of nodes that can be saved in the subtree if the root of the subtree is infected
    vi adj_list;
};

void dfs(int root, int parent, V<Node>& tree) {
    vi children;
    for(auto& child: tree[root].adj_list) {
        if(child == parent) continue;
        dfs(child, root, tree);
        tree[root].subtree_size += tree[child].subtree_size;
        children.pb(child);
    }

    if(children.size() == 1)
        tree[root].subtree_can_save = tree[children[0]].subtree_size - 1;
    else if(children.size() == 2) {
        int c1 = children[0], c2 = children[1];
        tree[root].subtree_can_save = max(tree[c1].subtree_can_save + tree[c2].subtree_size - 1, tree[c2].subtree_can_save + tree[c1].subtree_size - 1);
    }
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

    cout << tree[0].subtree_can_save;
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