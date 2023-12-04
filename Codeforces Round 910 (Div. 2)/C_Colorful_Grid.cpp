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

void solve() {
    int n, m, k; cin >> n >> m >> k;

    if(k < n-1 + m-1 || k%2 != (n+m)%2) {cout << "NO" << nl; return;}
    else cout << "YES" << nl;

    V<V<char>> horizontal(n, V<char>(m-1, 'R'));
    V<V<char>> vertical(n-1, V<char>(m, 'R'));

    // Make the path
    for(int i = 0; i < m-1; i+=2)
        horizontal[0][i] = 'B';
    for(int i = (horizontal[0][m-2] == 'B'); i < n-1; i+=2)
        vertical[i][m-1] = 'B';

    // Make a potential cycle
    if((k - (n+m-2)) % 4 == 2) {
        horizontal[0][0] = horizontal[1][0] = 'R';
        vertical[0][0] = vertical[0][1] = 'B';
    }
    else {
        horizontal[1][0] = 'B';
    }

    for(auto& v: horizontal) cout << v << nl;
    for(auto& v: vertical) cout << v << nl;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}