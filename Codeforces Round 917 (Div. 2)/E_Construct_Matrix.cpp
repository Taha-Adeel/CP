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
#define pY { cout << "Yes" << nl; for(auto& v: a) cout << v << nl; return; }
#define pN {cout << "No" << nl;  return;}
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
    int n, k; cin >> n >> k;

    if(k % 2) { cout << "No" << nl; return; }
    else if(k == 2 || k == n * n - 2) {
        if(n == 2) cout << "Yes" << nl << "1 0" << nl << "0 1" << nl;
        else cout << "No" << nl;
        return;
    }

    V<vi> ans(n, vi(n, 0));
    bool fish = false;
    if(k % 4 == 2) {
        fish = true;
        ans[n-1][n-1] = ans[n-1][n-2] = ans[n-2][n-1] = ans[n-3][n-2] = ans[n-2][n-3] = ans[n-3][n-3] = 1;
        k -= 6;
        if(k > n * n - 16) {
            ans[n-4][n-4] = ans[n-4][n-3] = ans[n-1][n-4] = ans[n-1][n-3] = 1;
            k -= 4;
        }
    }

    // Add 2x2 blocks of 1s
    for(int i = 0; i < n && k; i += 2) {
        for(int j = 0; j < n && k; j += 2) {
            if(fish && i >= n-4 && j >= n-4) continue;
            ans[i][j] = ans[i+1][j] = ans[i][j+1] = ans[i+1][j+1] = 1;
            k -= 4;
        }
    }
    
    cout << "Yes" << nl;
    for(auto& v: ans)
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