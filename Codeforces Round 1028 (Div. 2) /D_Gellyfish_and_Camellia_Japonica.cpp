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
    int n, q; cin >> n >> q;
    vi b(n); cin >> b;
    vi x(q), y(q), z(q);
    FOR (i, q) {
        cin >> x[i] >> y[i] >> z[i];
        x[i]--; y[i]--; z[i]--;
    }

    vi l = b, r = b;
    for (int i = q - 1; i >= 0; i--) {
        if (z[i] == x[i]) {
            if (z[i] == y[i]) continue;
            if (b[z[i]] < b[y[i]]) {
                if (b[z[i]] < l[z[i]]) {cout << -1; return;}
                l[z[i]] = b[z[i]];
                if (b[z[i]] > r[z[i]]) {cout << -1; return;}
                r[z[i]] = b[z[i]];
            } else if (b[z[i]] == b[y[i]]) {
                l[z[i]] = max(l[z[i]], b[y[i]]);
                r[z[i]] = INT_MAX;
            } else {
                cout << -1; return;
            }
        } else if (z[i] == y[i]) {
            if (b[z[i]] < b[x[i]]) {
                if (b[z[i]] < l[z[i]]) {cout << -1; return;}
                l[z[i]] = b[z[i]];
                if (b[z[i]] > r[z[i]]) {cout << -1; return;}
                r[z[i]] = b[z[i]];
            } else if (b[z[i]] == b[x[i]]) {
                l[z[i]] = max(l[z[i]], b[x[i]]);
                r[z[i]] = INT_MAX;
            } else {
                cout << -1; return;
            }
        } else {
            
        }
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