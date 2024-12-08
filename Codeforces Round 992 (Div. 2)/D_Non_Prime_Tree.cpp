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
    int val;
    int parent = -1;
    int depth = -1;
    vi adj_list;
};

void solve() {
    int n; cin >> n;
    V<Node> tree(n);
    FOR (i, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].adj_list.pb(v);
        tree[v].adj_list.pb(u);
    }

    queue<int> q;
    q.push(0);
    tree[0].depth = 0;
    int l = 2, r = 2 * n;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: tree[u].adj_list) {
            if (tree[v].depth == -1) {
                tree[v].depth = tree[u].depth + 1;
                tree[v].parent = u;
                q.push(v);
            }
        }

        if (tree[u].depth % 2 == 0) {
            tree[u].val = l;
            l += 2;
        } else {
            tree[u].val = r;
            r -= 2;
        }
        if (tree[u].parent != -1 and abs(tree[u].val - tree[tree[u].parent].val) == 2) {
            tree[u].val = tree[tree[u].parent].val - 1;
        }
    }

    FOR (i, n) {
        cout << tree[i].val << ' ';
    }
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