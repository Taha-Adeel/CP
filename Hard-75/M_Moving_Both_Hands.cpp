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
    ll dist1 = 1e15; // When going forward
    ll dist2 = 1e15; // Once reversed
    V<pll> adj_list_out;
    V<pll> adj_list_in;
};

void solve() {
    int n, m; cin >> n >> m;
    V<Node> graph(n);
    FOR (i, m) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        graph[u].adj_list_out.pb({v, w});
        graph[v].adj_list_in.pb({u, w});
    }

    // Djkstra's Algorithm
    using plll = tuple<ll, ll, ll>;
    priority_queue<plll, V<plll>, greater<plll>> pq; // {dist, type, node}
    pq.push({0, 1, 0});
    graph[0].dist1 = 0;
    graph[0].dist2 = 0;
    while (!pq.empty()) {
        auto [dist, type, node] = pq.top(); pq.pop();
        if (type == 1) {
            if (dist > graph[node].dist1) continue;
            for (auto [v, w]: graph[node].adj_list_out) {
                if (graph[v].dist1 > dist + w) {
                    graph[v].dist1 = dist + w;
                    pq.push({graph[v].dist1, 1, v});
                }
            }
            for (auto [v, w]: graph[node].adj_list_in) {
                if (graph[v].dist2 > dist + w) {
                    graph[v].dist2 = dist + w;
                    pq.push({graph[v].dist2, 2, v});
                }
            }
        } else {
            if (dist > graph[node].dist2) continue;
            for (auto [v, w]: graph[node].adj_list_in) {
                if (graph[v].dist2 > dist + w) {
                    graph[v].dist2 = dist + w;
                    pq.push({graph[v].dist2, 2, v});
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        ll dist = min(graph[i].dist1, graph[i].dist2);
        if (dist == 1e15) cout << -1 << ' ';
        else cout << dist << ' ';
    }
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}