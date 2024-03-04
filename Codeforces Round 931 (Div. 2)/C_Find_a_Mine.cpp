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

int query(int x, int y) {
    cout << "? " << x + 1 << ' ' << y + 1 << endl;
    int d; cin >> d;
    return d;
}

void solve() {
    int n, m; cin >> n >> m;

    int d1 = query(0, 0); // L1 -> x + y = d1
    int d2 = (n + m - 2) - query(n - 1, m - 1); // L2 -> x + y = d2
    int d3 = (n - 1) - query(n - 1, 0); // L3 -> x - y = d3

    // L1 intersection L3
    int x = (d1 + d3) / 2, y = (d1 - d3) / 2; 
    if (x >= 0 && x < n && y >= 0 && y < m) {
        int d = query(x, y);
        if (d == 0) {
            cout << "! " << x + 1 << ' ' << y + 1 << endl;
            return;
        }
    }

    // L2 intersection L3
    x = (d2 + d3) / 2, y = (d2 - d3) / 2;
    cout << "! " << x + 1 << ' ' << y + 1 << endl;
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