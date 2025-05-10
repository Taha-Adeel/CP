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
    set<int> adj_list;
    bool deleted = false;
};

void solve() {
    int n; cin >> n;
    V<Node> a(n);
    FOR (i, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        a[u].adj_list.insert(v);
        a[v].adj_list.insert(u);
    }

    V<tuple<int, int, int>> ans;
    
    auto get_diameter = [&](int u) {
        set<int> visited;
        queue<pii> q;
        q.push({u, 0});
        visited.insert(u);
        int max_dist = 0, farthest_node = u;
        while (!q.empty()) {
            auto [node, dist] = q.front(); q.pop();
            if (dist > max_dist) {
                max_dist = dist;
                farthest_node = node;
            }
            for (auto& v: a[node].adj_list) {
                if (!visited.contains(v)) {
                    visited.insert(v);
                    q.push({v, dist + 1});
                }
            }
        }
    };
    
    FOR (i, n) {
        if (a[i].deleted) continue;
        
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