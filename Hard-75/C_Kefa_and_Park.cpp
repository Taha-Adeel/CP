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
    int cat = 0;
    int cats_prev = 0;
    vi adj_list;
};

void dfs(int cur, int parent, V<Node>& tree, int& ans, int m) {
    if (tree[cur].cat) tree[cur].cats_prev = tree[parent].cats_prev + 1;
    else tree[cur].cats_prev = 0;
    if (tree[cur].cats_prev > m) return;
    if (tree[cur].adj_list.size() == 1 && cur != 1) ans++;
    for(auto& child: tree[cur].adj_list) {
        if (child == parent) continue;
        dfs(child, cur, tree, ans, m);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    V<Node> tree(n+1);
    FOR1(i, n) cin >> tree[i].cat;
    FOR(i, n-1) {
        int u, v; cin >> u >> v;
        tree[u].adj_list.pb(v);
        tree[v].adj_list.pb(u);
    }

    int ans = 0;
    dfs(1, 0, tree, ans, m);

    cout << ans;
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}