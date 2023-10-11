#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()			{std::sort(this->begin(), this->end());}
    void sort_dsc() 	{std::sort(this->begin(), this->end(), greater<T>());}
    auto sum() 			{T sum = 0; for(auto& i: *this) sum += i; return sum;}
    auto freqs() 		{map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
    auto indices()		{int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
    auto prefix_sums() 	{int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)            for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

struct Edge{
    int u, v;
    ll len;
    ll cost = 0;
};

struct Node{
    int id;
    V<Edge> edges;
};

V<Edge> get_cut_edges(V<Node>& graph){
    int n = graph.size();
    V<Edge> cut_edges;
    V<int> visited(n, 0);
    V<int> d(n, 0);
    V<int> up(n, 0);
    V<ll> sz(n, 1);
    int timer = 0;

    function<void(int, int)> dfs = [&](int u, int p){
        visited[u] = 1;
        d[u] = up[u] = timer++;
        for(auto& e: graph[u].edges){
            int v = e.u ^ e.v ^ u;
            if(v == p) continue;
            if(visited[v]){
                up[u] = min(up[u], d[v]);
            }
            else{
                dfs(v, u);
                sz[u] += sz[v];
                up[u] = min(up[u], up[v]);
                if(up[v] > d[u]){
                    cut_edges.pb(e);
                }
            }
        }
    };

    FOR(i, n) if(!visited[i]) dfs(i, -1);
    for(auto& e: cut_edges){
        e.cost = min(sz[e.u], sz[e.v]) * (n - min(sz[e.u], sz[e.v])) * e.len;
    }
    return cut_edges;
}

void solve(){
    ll n, m; cin >> n >> m;
    V<Node> graph(n);
    V<Edge> edges(m);
    FOR(i, m){
        int u, v; ll len; cin >> u >> v >> len;
        u--, v--;
        if(u > v) swap(u, v);
        edges[i] = {u, v, len};
        graph[u].edges.pb(edges[i]);
        graph[v].edges.pb(edges[i]);
    }

    auto cut_edges = get_cut_edges(graph);
    V<Node> new_graph(n);
    for(auto& e: cut_edges){
        new_graph[e.u].edges.pb(e);
        new_graph[e.v].edges.pb(e);
    }

    auto is_possible = [&](ll x){
        vll budget(n, 0);
        V<bool> visited(n, 0);
        map<pii, Edge> edge_map;
        for(auto& e: cut_edges)
            edge_map[{e.u, e.v}] = e;
        
        function<bool(int, int)> dfs = [&](int u, int p){
            bool ans = true;
            visited[u] = 1;
            for(auto& e: new_graph[u].edges){int
                int v = e.u ^ e.v ^ u;
                if(v == p) continue;
                ans &= dfs(v, u);
                budget[u] += edge_map[{u, v}].cost;
            }
            if(p != -1){
                if(budget[u] < x){
                    int delta = min(x - budget[u], edge_map[{min(u,p), max(u,p)}].cost);
                    budget[u] += delta;
                    edge_map[{min(u,p), max(u,p)}].cost -= delta;
                }
            }
            if(budget[u] > x) ans = false;
            return ans;
        };
        bool ans = true;
        FOR(i, n) if(!visited[i]) ans &= dfs(i, -1);
        return ans;
    };

    ll l = 0, r = 1LL << 40;
    while(l < r){
        ll mid = (l + r) / 2;
        if(is_possible(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
}

signed main(){
    FAST;
    solve();
    cout << nl;
    
    return 0;
}