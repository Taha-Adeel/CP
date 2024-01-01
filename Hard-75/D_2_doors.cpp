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
    int val = (1 << 30) - 1;
    V<pii> adj_list;
};

void solve() {
    int n, q; cin >> n >> q;
    V<Node> graph(n);
    FOR(i, q) {
        int u, v, x; cin >> u >> v >> x; --u, --v;
        graph[u].adj_list.pb({v, x});
        graph[v].adj_list.pb({u, x});
        graph[u].val &= x;
        graph[v].val &= x;
    }

    FOR(i, n) {
        for(int mask = 1; mask < (1 << 30); mask <<= 1) {
            if((graph[i].val & mask) == 0) continue;
            int new_val = graph[i].val ^ mask;
            bool good = true;
            for(auto& [v, x]: graph[i].adj_list) {
                if((new_val | graph[v].val) != x || v == i) {
                    good = false;
                    break;
                }
            }
            if(good) graph[i].val = new_val;
        }
    }

    FOR(i, n) cout << graph[i].val << ' ';
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}