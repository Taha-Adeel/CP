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
    bool visited = false;
    vi adj_list;
};

void dfs(int u, V<Node>& graph) {
    graph[u].visited = true;
    for (int v: graph[u].adj_list) {
        if (!graph[v].visited) {
            dfs(v, graph);
        }
    }
}

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;

    V<Node> graph(2 * n);
    for (int i = 0; i < n; i++) {
        // A's neighbours
        if (i > 1 && a[i - 1] == '<') {
            graph[i].adj_list.push_back(i - 2);
        }
        if (i < n - 2 && a[i + 1] == '>') {
            graph[i].adj_list.push_back(i + 2);
        }
        if (i && b[i] == '<') {
            graph[i].adj_list.push_back(n + i - 1);
        }
        if (i < n - 1 && b[i] == '>') {
            graph[i].adj_list.push_back(n + i + 1);
        }

        // B's neighbours
        if (i > 1 && b[i - 1] == '<') {
            graph[n + i].adj_list.push_back(n + i - 2);
        }
        if (i < n - 2 && b[i + 1] == '>') {
            graph[n + i].adj_list.push_back(n + i + 2);
        }
        if (i && a[i] == '<') {
            graph[n + i].adj_list.push_back(i - 1);
        }
        if (i < n - 1 && a[i] == '>') {
            graph[n + i].adj_list.push_back(i + 1);
        }
    }
    graph[n - 1].adj_list.push_back(2 * n - 1);
    graph[2*n - 2].adj_list.push_back(2 * n - 1);
    
    dfs(0, graph);

    if (graph[2 * n - 1].visited) {
        cout << "YES";
    } else {
        cout << "NO";
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