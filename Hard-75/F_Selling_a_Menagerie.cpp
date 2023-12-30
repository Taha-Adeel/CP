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
    int cost;
    int indegree = 0;
    int next;
    bool visited = false;
};

void solve() {
    int n; cin >> n;
    vector<Node> nodes(n);
    FOR(i, n) {
        cin >> nodes[i].next;
        nodes[i].next--;
        nodes[nodes[i].next].indegree++;
    }
    FOR(i, n) cin >> nodes[i].cost;

    vi topological_order;
    queue<int> q;
    FOR(i, n) {
        if(nodes[i].indegree == 0) {
            q.push(i);
            nodes[i].visited = true;
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        topological_order.pb(u + 1);
        int v = nodes[u].next;
        nodes[v].indegree--;
        if(nodes[v].indegree == 0) {
            q.push(v);
            nodes[v].visited = true;
        }
    }

    // Now only cycles remain
    FOR(i, n) if(!nodes[i].visited) {
        int u = i;
        int min_cost = nodes[u].cost, min_cost_node = u;
        int v = nodes[u].next;
        while(v != u) {
            if(nodes[v].cost < min_cost) {
                min_cost = nodes[v].cost;
                min_cost_node = v;
            }
            v = nodes[v].next;
        }

        // Add the cycle starting from min_cost_node->next
        u = min_cost_node;
        v = nodes[min_cost_node].next;
        while(!nodes[v].visited) {
            topological_order.pb(v + 1);
            nodes[v].visited = true;
            v = nodes[v].next;
        }
    }

    cout << topological_order;
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