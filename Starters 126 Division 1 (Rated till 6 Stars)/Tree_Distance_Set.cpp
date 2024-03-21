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
    char color = 'W';
    vi adj_list;
};

vi get_diameter(V<Node>& tree) {
    int n = tree.size();
    vi dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    int farthest = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: tree[u].adj_list) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                farthest = v;
            }
        }
    }

    fill(all(dist), -1);
    q.push(farthest);
    dist[farthest] = 0;
    vi parent(n, -1);
    int farthest2 = farthest;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: tree[u].adj_list) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v] = u;
                farthest2 = v;
            }
        }
    }

    vi diameter;
    while (farthest2 != -1) {
        diameter.pb(farthest2);
        farthest2 = parent[farthest2];
    }

    return diameter;
}

void solve() {
    int n; cin >> n;
    V<Node> tree(n);
    FOR(i, n - 1) {
        int u, v; cin >> u >> v; u--; v--;
        tree[u].adj_list.pb(v);
        tree[v].adj_list.pb(u);
    }

    vi diameter = get_diameter(tree);
    int d = diameter.size(), cnt = 0;
    for (int i = 0; i < d; i++) {
        if (i < d / 2) {
            tree[diameter[i]].color = 'R';
            cnt++;
        } else {
            tree[diameter[i]].color = 'B';
            cnt--;
        }
    }

    for (int i = 0; i < n; i++) {
        if (tree[i].color == 'W') {
            if (cnt <= 0) {
                tree[i].color = 'R';
                cnt++;
            } else {
                tree[i].color = 'B';
                cnt--;
            }
        }
    }

    string ans = "";
    for (int i = 0; i < n; i++) {
        ans += tree[i].color;
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