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
    int depth = 0, height = 0;
    int max_height1 = 0, max_height2 = 0;
    int max_height1_idx = -1, max_height2_idx = -1;
    int max_up_dist = 0;
    int dist; // dist = max(max_height1, max_up_dist)
    vi adj_list;
};

void dfs(int cur, V<Node>& tree) {
    for(auto& child: tree[cur].adj_list) {
        if(child == tree[cur].parent) continue;
        tree[child].parent = cur;
        tree[child].depth = tree[cur].depth + 1;

        dfs(child, tree);
        
        tree[cur].height = max(tree[cur].height, tree[child].height + 1);
        if(tree[child].height + 1 >= tree[cur].max_height1) {
            tree[cur].max_height2 = tree[cur].max_height1;
            tree[cur].max_height1 = tree[child].height + 1;
            tree[cur].max_height2_idx = tree[cur].max_height1_idx;
            tree[cur].max_height1_idx = child;
        }
        else if(tree[child].height + 1 > tree[cur].max_height2) {
            tree[cur].max_height2 = tree[child].height + 1;
            tree[cur].max_height2_idx = child;
        }
    }
}

void dfs2(int cur, V<Node>& tree) {
    tree[cur].dist = max(tree[cur].max_height1, tree[cur].max_up_dist);
    for(auto& child: tree[cur].adj_list) {
        if(child == tree[cur].parent) continue;
        if(tree[cur].max_up_dist >= tree[cur].max_height1) tree[child].max_up_dist = tree[cur].max_up_dist + 1;
        else if(child == tree[cur].max_height1_idx) tree[child].max_up_dist = tree[cur].max_height2 + 1;
        else tree[child].max_up_dist = tree[cur].max_height1 + 1;
        dfs2(child, tree);
    }
}

void solve() {
    ll n, k, c; cin >> n >> k >> c;
    V<Node> tree(n);
    FOR(i, n-1) {
        int u, v; cin >> u >> v; --u; --v;
        tree[u].adj_list.pb(v);
        tree[v].adj_list.pb(u);
    }

    dfs(0, tree);
    dfs2(0, tree);

    ll ans = 0;
    FOR(i, n)
        ans = max(ans, tree[i].dist * k - tree[i].depth * c);
    
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