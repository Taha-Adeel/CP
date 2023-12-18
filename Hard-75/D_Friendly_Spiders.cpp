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

constexpr int MxN = 555; // sqrt(3e5)
vi primes, primes_n;
vi primes_upto(int n) {
    vi primes;
    V<bool> is_prime(n+1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.pb(i);
            for (ll j = i*i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
    return primes;
}

void sieve() {
    primes = primes_upto(MxN);
    primes_n = primes_upto(3e5+5);
}

struct Node {
    int val;
    vi adj_list;
};

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    int s, t; cin >> s >> t; --s; --t;

    map<int, int> prime_idx;
    FOR(i, primes_n.size()) prime_idx[primes_n[i]] = i; 

    int num_primes = lower_bound(all(primes_n), *max_element(all(a))) - primes_n.begin() + 1;
    V<Node> graph(num_primes + n);
    FOR(i, n) {
        vi factors;
        int x = a[i];
        for (int p: primes) {
            if (p*p > x) break;
            if (x % p == 0) {
                factors.pb(p);
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) factors.pb(x);

        for (int p: factors) {
            graph[num_primes + i].adj_list.pb(prime_idx[p]);
            graph[prime_idx[p]].adj_list.pb(num_primes + i);
        } 
    }

    int ans = -1;
    s += num_primes;
    t += num_primes;
    vi dist(num_primes + n, -1);
    vi parent(num_primes + n, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) {
            ans = dist[u];
            break;
        }
        for (int v: graph[u].adj_list) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (ans == -1) { cout << -1; return; }

    vi path;
    int v = t;
    while (v != -1) {
        path.pb(v);
        v = parent[v];
    }
    reverse(all(path));

    cout << (path.size() + 1) / 2 << nl;
    cerr << path << nl;
    for(auto i: path) {
        if (i >= num_primes) cout << i - num_primes + 1 << ' ';
    }
}

int main() {
    sieve();
    FAST;
    solve();
    cout << nl;
    
    return 0;
}