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

struct Node{
    int guard = 0; // takes 1 second to pass if guard present
    int time = 1e9;
    vi adj_list;
};

void djkstra(V<Node>& graph, int root) {
    priority_queue<pii, V<pii>, greater<pii>> pq;
    pq.push({0, root});
    graph[root].time = 0;

    while (!pq.empty()) {
        auto [time, node] = pq.top();
        pq.pop();

        if (graph[node].time < time) continue;

        for (auto& child: graph[node].adj_list) {
            int new_time = time + graph[child].guard;
            if (new_time < graph[child].time) {
                graph[child].time = new_time;
                pq.push({new_time, child});
            }
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    V<string> grid(n); cin >> grid;

    V<Node> graph(n*m + 1);
    FOR (i, n) {
        FOR (j, m) {
            graph[i*m + j].guard = grid[i][j] - '0';
            if (i > 0) graph[i*m + j].adj_list.pb((i-1)*m + j);
            if (i < n-1) graph[i*m + j].adj_list.pb((i+1)*m + j);
            if (j > 0) graph[i*m + j].adj_list.pb(i*m + j - 1);
            if (j < m-1) graph[i*m + j].adj_list.pb(i*m + j + 1);
            if (i == 0 || i == n-1 || j == 0 || j == m-1) graph[i*m + j].adj_list.pb(n*m), graph[n*m].adj_list.pb(i*m + j);
        }
    }

    djkstra(graph, n*m);

    int ans = 0;
    for (auto& [guard, time, adj_list]: graph) {
        if (guard) continue;
        ans = max(ans, time);
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