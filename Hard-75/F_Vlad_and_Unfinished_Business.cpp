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
    bool must_visit = false;
    int subtree_size = 1;
    int depth = 0;
    vi adj_list;
};

void dfs(int root, int parent, V<Node>& tree) {
    for (int child: tree[root].adj_list) {
        if (child == parent) continue;
        tree[child].depth = tree[root].depth + 1;
        dfs(child, root, tree);
        tree[root].must_visit |= tree[child].must_visit;
        if (tree[child].must_visit) tree[root].subtree_size += tree[child].subtree_size;
    }
}

void solve() {
    int n, k; cin >> n >> k;

    V<Node> tree(n);
    int x, y; cin >> x >> y; x--; y--;
    tree[x].must_visit = true;
    tree[y].must_visit = true;

    for (int i = 0; i < k; i++) {
        int z; cin >> z; z--;
        tree[z].must_visit = true;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        tree[u].adj_list.pb(v);
        tree[v].adj_list.pb(u);
    }

    dfs(x, -1, tree);

    int ans = 2 * (tree[x].subtree_size - 1) - tree[y].depth;

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