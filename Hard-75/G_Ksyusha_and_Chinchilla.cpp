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
    int present = 1;
    int parent = -1;
    vi adj_list;
};

void dfs(int cur, V<Node>& tree, V<pii>& ans, bool& possible) {
    if(!possible) return;
    
    int child_cnt = 0;
    for(auto& child: tree[cur].adj_list) {
        if(child == tree[cur].parent) continue;
        tree[child].parent = cur;
        dfs(child, tree, ans, possible);
        child_cnt += tree[child].present;
    }

    if(child_cnt == 0) return;
    else if(child_cnt > 2) {
        possible = false;
    }
    else if(child_cnt == 2) {
        tree[cur].present = 0;
        if(tree[cur].parent != -1)
            ans.pb({cur, tree[cur].parent});
    }
    else if(child_cnt == 1) {
        if(tree[cur].parent == -1) {
            possible = false;
        }
        else {
            tree[cur].present = 2;
        }
    }
}

void solve() {
    int n; cin >> n;
    V<Node> tree(n);
    map<pii, int> edges;
    FOR(i, n-1) {
        int u, v; cin >> u >> v; u--; v--;
        tree[u].adj_list.pb(v);
        tree[v].adj_list.pb(u);
        edges[{u, v}] = i + 1;
        edges[{v, u}] = i + 1;
    }

    if(n % 3) { cout << -1 << nl; return; }

    V<pii> ans;
    bool possible = true;
    dfs(0, tree, ans, possible);

    if(!possible) { cout << -1 << nl; return; }
    
    cout << ans.size() << nl;
    for(auto& p: ans)
        cout << edges[p] << ' ';
    cout << nl;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}