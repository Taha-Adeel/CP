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

class DSU {
public:
    vi parent, size;
    int components;
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(all(parent), 0);
        components = n;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) {
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
            components--;
        }
    }
};

void solve() {
    int n, m; cin >> n >> m;
    V<string> a(n); cin >> a;

    auto conv = [&] (int x, int y) {
        return x * m + y;
    };

    DSU dsu1(n * m);
    vi top(n, 0);
    FOR (i, n) {
        FOR (j, m) {
            if (a[i][j] == '.') continue;
            if (i and a[i-1][j] == '#') {
                dsu1.unite(conv(i, j), conv(i-1, j));
            }
            if (j and a[i][j-1] == '#') {
                dsu1.unite(conv(i, j), conv(i, j-1));
            }
        }
        set<int> comps;
        FOR (j, m) {
            if (a[i][j] == '#') {
                int comp = dsu1.find(conv(i, j));
                if (comps.count(comp) == 0) {
                    comps.insert(comp);
                    top[i] += dsu1.size[comp];
                }
            }
        }
    }

    DSU dsu2(n * m);
    vi bottom(n, 0);
    ROF (i, n) {
        FOR (j, m) {
            if (a[i][j] == '.') continue;
            if (i < n-1 and a[i+1][j] == '#') {
                dsu2.unite(conv(i, j), conv(i+1, j));
            }
            if (j and a[i][j-1] == '#') {
                dsu2.unite(conv(i, j), conv(i, j-1));
            }
        }
        set<int> comps;
        FOR (j, m) {
            if (a[i][j] == '#') {
                int comp = dsu2.find(conv(i, j));
                if (comps.count(comp) == 0) {
                    comps.insert(comp);
                    bottom[i] += dsu2.size[comp];
                }
            }
        }
    }

    ll ans1 = 0;
    FOR (i, n) {
        ll cur = m;
        if (i) {
            cur += top[i-1];
        }
        if (i < n-1) {
            cur += bottom[i+1];
        }
        ans1 = max(ans1, cur);
    }

    // Rotate the grid
    V<string> b(m, string(n, '.'));
    FOR (i, n) {
        FOR (j, m) {
            b[j][i] = a[i][j];
        }
    }
    swap(n, m);

    DSU dsu3(n * m);
    vi left(n, 0);
    FOR (i, n) {
        FOR (j, m) {
            if (b[i][j] == '.') continue;
            if (i and b[i-1][j] == '#') {
                dsu3.unite(conv(i, j), conv(i-1, j));
            }
            if (j and b[i][j-1] == '#') {
                dsu3.unite(conv(i, j), conv(i, j-1));
            }
        }
        set<int> comps;
        FOR (j, m) {
            if (b[i][j] == '#') {
                int comp = dsu3.find(conv(i, j));
                if (comps.count(comp) == 0) {
                    comps.insert(comp);
                    left[i] += dsu3.size[comp];
                }
            }
        }
    }

    DSU dsu4(n * m);
    vi right(n, 0);
    ROF (i, n) {
        FOR (j, m) {
            if (b[i][j] == '.') continue;
            if (i < n-1 and b[i+1][j] == '#') {
                dsu4.unite(conv(i, j), conv(i+1, j));
            }
            if (j and b[i][j-1] == '#') {
                dsu4.unite(conv(i, j), conv(i, j-1));
            }
        }
        set<int> comps;
        FOR (j, m) {
            if (b[i][j] == '#') {
                int comp = dsu4.find(conv(i, j));
                if (comps.count(comp) == 0) {
                    comps.insert(comp);
                    right[i] += dsu4.size[comp];
                }
            }
        }
    }

    ll ans2 = 0;
    FOR (i, n) {
        ll cur = m;
        if (i) {
            cur += left[i-1];
        }
        if (i < n-1) {
            cur += right[i+1];
        }
        ans2 = max(ans2, cur);
    }

    cout << max(ans1, ans2);
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