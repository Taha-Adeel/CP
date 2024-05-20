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
    int n, m, k; 
    cin >> n >> m >> k;
    V<V<string>> pic(k+1, V<string>(n));
    cin >> pic;

    V<V<pii>> a(k+1); // a[i] -> Possible postions where an operation was done on the ith picture.
    for (int p = 0; p < k+1; p++) {
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                set<char> c = {pic[p][i][j], pic[p][i-1][j], pic[p][i+1][j], pic[p][i][j-1], pic[p][i][j+1]};
                if (c.size() == 1) {
                    a[p].push_back({i, j});
                }
            }
        }
    }

    vi ord(k+1);
    iota(all(ord), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i].size() < a[j].size(); });
    cout << ord[0] + 1 << nl;

    V<vi> ops;
    for (int p = 1; p < k + 1; p++) {
        V<pii> diff; 
        set_difference(all(a[ord[p]]), all(a[ord[p-1]]), back_inserter(diff));
        for(auto& [i, j]: diff) {
            if (pic[ord[p]][i][j] != pic[ord[p-1]][i][j])
                ops.push_back({1, i + 1, j + 1});
        }
        ops.push_back({2, ord[p] + 1});
    }


    cout << ops.size() << nl;
    for (auto& op : ops) {
        cout << op << nl;
    }
}

int main() {
    FAST;
    solve();
    
    return 0;
}