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
    int n; cin >> n;
    vi a(n); cin >> a;

    vi b(n-1);
    FOR (i, n-1) {
        b[i] = gcd(a[i], a[i+1]);
    }
    b.pb(INT_MAX);

    V<bool> prefix(n, true), suffix(n-1, true);
    FOR (i, n-2) {
        prefix[i+2] = (prefix[i+1] and b[i+1] >= b[i]);
    }
    for (int i = n-3; i >= 0; i--) {
        suffix[i] = (suffix[i+1] and b[i] <= b[i+1]);
    }

    FOR (i, n) {
        if (i == 0) {
            if (suffix[1]) {
                cout << "YES";
                return;
            }
        } else if (i == n-1) {
            if (prefix[n-2]) {
                cout << "YES";
                return;
            }
        } else {
            if (prefix[i-1] and suffix[i+1] and (i < 2 or gcd(a[i-1], a[i+1]) >= b[i-2]) and gcd(a[i-1], a[i+1]) <= b[i+1]) {
                cout << "YES";
                return;
            }
        }
    }


    cout << "NO";
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