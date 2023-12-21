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

class DSU {
    int n; // # Nodes
    vi parent;
    vi _size;

public:
    int num_comps; // # Components
    DSU(int n): n(n), num_comps(n), parent(vi(n, -1)), _size(vi(n, 1)) {}
    int size(int u) { return _size[comp(u)]; }
    int comp(int u) {
        if(parent[u] == -1) return u;
        return parent[u] = comp(parent[u]);
    }

    bool merge(int u, int v) {
        u = comp(u); v = comp(v);
        if(u == v) return false;
        if(size(u) < size(v)) swap(u, v);
        parent[v] = u; num_comps--;
        _size[u] += _size[v]; _size[v] = 0;
        return true;
    }
};

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    DSU dsu(n);
    vi degree(n, 0);
    set<pii> edges;
    FOR(i, n) {
        dsu.merge(i, --a[i]);
        auto [u, v] = minmax(i, a[i]);
        if(edges.count({u, v}) == 0) {
            edges.insert({u, v});
            degree[u]++, degree[v]++;
        }
    }

    map<int, int> comps;
    FOR(i, n)
        if(degree[i] == 2) comps[dsu.comp(i)]++;
    
    int min_ans = 1, max_ans = dsu.num_comps;
    for(auto& [comp, edges]: comps)
        if(edges == dsu.size(comp)) min_ans++;

    cout << min(min_ans, max_ans) << ' ' << max_ans;
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