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

V<vi> odd_base = {{1}};
V<vi> even_base = {{1, 2, 3, 4}, {5, 7, 9, 6}, {8, 11, 10, 13}, {12, 14, 15, 16}};

void solve() {
    int n; cin >> n;

    if(n == 2) { cout << -1 << nl; return; }

    V<vi> a(n, vi(n));
    int cur_e = 2, cur_o = 3;
    if(n % 2) {
        FOR(i, n) FOR(j, n) {
            if(i < odd_base.size() && j < odd_base.size()) a[i][j] = odd_base[i][j];
            else if(i == j) a[i][j] = cur_e, cur_e += 2;
            else if(max(i, j) % 2 == 1) a[i][j] = cur_e, cur_e += 2;
            else a[i][j] = cur_o, cur_o += 2;
        }
    }
    else {
        cur_o = 17, cur_e = 18;
        FOR(i, n) FOR(j, n) {
            if(i < even_base.size() && j < even_base.size()) a[i][j] = even_base[i][j];
            else if(i == j) a[i][j] = cur_e, cur_e += 2;
            else if(max(i, j) % 2 == 0) a[i][j] = cur_e, cur_e += 2;
            else a[i][j] = cur_o, cur_o += 2;
        }
    }

    for(auto& v: a) 
        cout << v << nl;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}