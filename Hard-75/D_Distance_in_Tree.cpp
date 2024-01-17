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
    int parent = -1;
    int depth = 0;
    vi dist_cnts = vi(501, 0);
    vi adj_list;
};

void dfs(int root, V<Node>& tree) {
    for(auto& child: tree[root].adj_list) {
        if(child == tree[root].parent) continue;
        tree[child].parent = root;
        tree[child].depth = tree[root].depth + 1;
        dfs(child, tree);
    }

    tree[root].dist_cnts[0] = 1;
    for(auto& child: tree[root].adj_list) {
        if(child == tree[root].parent) continue;
        for(int i = 0; i < min((int)tree[child].dist_cnts.size(), 500); i++) {
            tree[root].dist_cnts[i + 1] += tree[child].dist_cnts[i];
        }
    }
};

void solve() {
    int n, k; cin >> n >> k;
    V<Node> tree(n);
    FOR(i, n-1) {
        int a, b; cin >> a >> b; a--, b--;
        tree[a].adj_list.pb(b);
        tree[b].adj_list.pb(a);
    }

    dfs(0, tree);

    ll ans = 0;
    FOR(i, n) {
        int cur = i;
        ans += tree[i].dist_cnts[k];
        for(int dist = 0; dist < min(k, tree[i].depth); dist++) {
            int parent = tree[cur].parent;
            if(parent == -1) break;
            ans += tree[parent].dist_cnts[k - dist - 1];
            if(k - dist - 2 >= 0)
                ans -= tree[cur].dist_cnts[k - dist - 2];
            cur = parent;
        }
    }

    cout << ans / 2;
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}