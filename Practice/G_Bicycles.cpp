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

void solve() {
    int n, m; cin >> n >> m;
    V<V<pll>> adj(n);
    FOR(i, m) {
        int a, b, c; cin >> a >> b >> c; --a; --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    vll slowness(n); cin >> slowness;

    V<vll> dist(n, vll(n, 1e18));
    dist[0][0] = 0;
    
    priority_queue<array<ll, 3>, V<array<ll, 3>>, greater<array<ll, 3>>> pq;
    pq.push({dist[0][0], 0, 0});
    while(!pq.empty()) {
        auto [expected, i, j] = pq.top(); pq.pop();
        if(dist[i][j] != expected) continue;
        if(i == n - 1) { cout << dist[i][j]; return; }
        
        for(auto& [ti, w]: adj[i]) {
            int tj = (slowness[j] < slowness[ti] ? j : ti);
            if (dist[i][j] + w * slowness[j] < dist[ti][tj]) {
                dist[ti][tj] = dist[i][j] + w * slowness[j];
                pq.push({dist[ti][tj], ti, tj});
            }
        }
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