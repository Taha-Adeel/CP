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
    vi adj_list;
    ll min_even_dist = INT_MAX;
    ll min_odd_dist = INT_MAX;
};

void bfs(int start, V<Node>& graph) {
    queue<tuple<int, ll, ll>> q;
    graph[start].min_even_dist = 0;
    graph[start].min_odd_dist = INT_MAX;
    q.push({start, 0, INT_MAX});

    while (!q.empty()) {
        auto [u, dist_e, dist_o] = q.front(); q.pop();
        for (int v : graph[u].adj_list) {
            bool pushed = false;
            if (dist_o + 1 < graph[v].min_even_dist) {
                graph[v].min_even_dist = dist_o + 1;
                pushed = true;
            }
            if (dist_e + 1 < graph[v].min_odd_dist) {
                graph[v].min_odd_dist = dist_e + 1;
                pushed = true;
            }
            if (pushed) {
                q.push({v, dist_o + 1, dist_e + 1});
            }
        }
    }
}

void solve() {
    int n, m, l; cin >> n >> m >> l;
    vll a(l); cin >> a;
    V<Node> graph(n);
    FOR (i, m) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].adj_list.pb(v);
        graph[v].adj_list.pb(u);
    }

    graph[0].min_even_dist = 0;
    bfs(0, graph);

    a.sort();
    ll total = a.sum();

    ll min_odd = INT_MAX;
    for (int i = 0; i < l; i++) {
        if (a[i] % 2) {
            min_odd = min(min_odd, a[i]);
        }
    }

    ll max_even_sum = (total % 2 == 0) ? total : total - min_odd;
    ll max_odd_sum = (total % 2 == 1) ? total : total - min_odd;

    string ans(n, '0');
    ans[0] = '1';
    FOR (i, n) {
        if (graph[i].min_even_dist <= max_even_sum) {
            ans[i] = '1';
        }
        if (graph[i].min_odd_dist <= max_odd_sum) {
            ans[i] = '1';
        }
    }

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