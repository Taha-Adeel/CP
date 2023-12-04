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
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c; a--; b--; c--;
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;--u, --v; 
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> p(n, -1);
    vector<int> d(n, -1);

    // Compute path from a to b and c
    function<void(int)> dfs = [&](int u) {
        for (int v: e[u]) {
            if (v == p[u]) continue;
            p[v] = u;
            d[v] = d[u] + 1;
            dfs(v);
        }
    };
    d[a] = 0;
    dfs(a);

    vector<int> pb, pc;
    for (int i = b; i != a; i = p[i]) {
        pb.push_back(i);
    }
    for (int i = c; i != a; i = p[i]) {
        pc.push_back(i);
    }
    reverse(pb.begin(), pb.end());
    reverse(pc.begin(), pc.end());

    int x = 0;
    while (x < pb.size() and x < pc.size()) {
        if (pb[x] != pc[x]) break;
        ++x;
    }

    int y = pb.size() - x;
    int z = pc.size() - x;

    // Check if A can win in first move
    if (find(all(e[a]), c) != e[a].end()) { cout << "A"; return; }

    if (x == 0) {cout << "A"; return;}
    if (y == 0) {cout << "B"; return;}
    if (z == 0) {cout << "C"; return;}

    int min_val = min({x, y, z});
    x -= min_val;
    y -= min_val;
    z -= min_val;

    if (x + y + z == 0) cout << "DRAW";
    else if (x + y == 0) cout << "B";
    else if (x + z == 0) cout << "A";
    else if (y + z == 0) { 
        if (x > 1) cout << "C";
        else cout << "DRAW";
    }
    else if (x == 0) cout << "A";
    else if (y == 0) cout << "B";
    else if (z == 0) { 
        if (x > 1) cout << "C";
        else if (x == y) cout << "DRAW";
        else cout << "A";
    }
}

int main() {
    FAST;
    int t; cin >> t;
    while(t--) {
        solve();
        cout << nl;
    }
    
    return 0;
}