#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()            {std::sort(this->begin(), this->end());}
    void sort_dsc()     {std::sort(this->begin(), this->end(), greater<T>());}
    auto sum()             {T sum = 0; for(auto& i: *this) sum += i; return sum;}
    auto freqs()         {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
    auto indices()        {int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
    auto prefix_sums()     {int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)                for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/
const int MX = 200001; 
 
vector<vi> graph;
bool marked[MX];
int dist[MX];
int dist2[MX];
 
void dfs1(int v, int p) {
    vi ops;
    ops.pb(dist2[v]);
    if (marked[v]) ops.pb(0);
    dist2[v] = max(dist2[v], dist[v]);
    ops.pb(-MOD); ops.pb(-MOD);
    for(auto& a: graph[v]) {
        if (a == p) continue;
        ops.pb(dist[a] + 1);
    }
    sort(all(ops)); reverse(all(ops));
    for(auto& a: graph[v]) {
        if (a == p) continue;
        if (dist[a] + 1 == ops[0]) {
            dist2[a] = ops[1] + 1;
        } else dist2[a] = ops[0] + 1;
        dfs1(a, v);
    }
}
void dfs2(int v, int p) {
    dist[v] = -MOD;
    if (marked[v]) dist[v] = 0;
    for(auto& a: graph[v]) {
        if (a == p) continue;
        dfs2(a, v);
        dist[v] = max(dist[v], dist[a] + 1);
    }
}
 
void solve() {
    int N; cin >> N;
    int K; cin >> K;
    FOR(i, N) {
        marked[i] = false;
    }
    graph = vector<vi>(N);
    FOR(i, K) {
        int X; cin >> X; marked[X-1] = true;
    }
    FOR(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].pb(Y); graph[Y].pb(X);
    }
    dfs2(0, -1);
    dist2[0] = -MOD;
    dfs1(0, -1);
    int ans = MOD; FOR(i, N) ans = min(ans, dist2[i]);
    cout << ans;
 
}

int main(){
    FAST;
    int T;
    cin >> T;
    FOR(t, T){
        solve();
        cout << nl;
    }
    
    return 0;
}