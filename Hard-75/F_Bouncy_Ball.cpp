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

map<string, pii> dir = {
    {"DR", {1, 1}},
    {"DL", {1, -1}},
    {"UR", {-1, 1}},
    {"UL", {-1, -1}}
};

void solve() {
    int n, m, i1, j1, i2, j2; cin >> n >> m >> i1 >> j1 >> i2 >> j2;
    string d; cin >> d;

    set<pair<pii, pii>> visited;
    auto [di, dj] = dir[d];
    int i = i1, j = j1, bounces = 0;
    while(true) {
        if(i == i2 && j == j2) {
            cout << bounces;
            return;
        }
        if(visited.count({{i, j}, {di, dj}})) {
            cout << -1;
            return;
        }
        visited.insert({{i, j}, {di, dj}});

        bool bounce = false;
        if(i + di > n || i + di < 1) di *= -1, bounce = true;
        if(j + dj > m || j + dj < 1) dj *= -1, bounce = true;
        bounces += bounce;

        i += di, j += dj;
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