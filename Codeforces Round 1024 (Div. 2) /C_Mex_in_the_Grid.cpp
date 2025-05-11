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

V<V<vi>> grids;

void precompute() {
    int n = 500;
    grids.resize(n + 1);
    grids[1] = {{0}};
    for (int k = 2; k <= n; k++) {
        grids[k].resize(k, vi(k));
        int cur = (k - 1) * (k - 1);
        if (k % 2 == 0) {
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    if (j == k - 1) {
                        grids[k][i][j] = cur++; 
                    } else if (i == k - 1) {
                        grids[k][i][j] = cur++;
                    } else {
                        grids[k][i][j] = grids[k - 1][i][j];
                    }
                }
            }
        } else {
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    if (i == 0 and j == 0) {
                        grids[k][i][j] = k * k - 1;
                    } else if (i == 0) {
                        grids[k][i][j] = cur++; 
                    } else if (j == 0) {
                        grids[k][i][j] = cur++;
                    } else {
                        grids[k][i][j] = grids[k - 1][i - 1][j - 1];
                    }
                }   
            }
        }
    }
}


void solve() {
    int n; cin >> n;

    for(auto& v: grids[n]) {
        cout << v << nl;
    }
}

int main() {
    FAST;
    precompute();
    int T; cin >> T;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}