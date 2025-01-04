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
constexpr int MOD = 998244353;
using ll  = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

template<int MOD = MOD, int MxN = 1'000'001>
class Z {
    int val;
public:
    Z(ll v = 0) : val(v%MOD) { if(val < 0) val += MOD; }

    Z pow(ll e) const { Z res = 1; for(Z b = val; e > 0; b = b*b, e /= 2) if(e & 1) res = res*b; return res; }
    Z inv() const { return pow(MOD-2); }

    Z operator+(const Z& o) const { return Z(val + o.val); }
    Z operator-(const Z& o) const { return Z(val - o.val); }
    Z operator*(const Z& o) const { return Z((ll)val * o.val); }
    Z operator/(const Z& o) const { return *this * o.inv(); }
    Z operator-() const { return Z(-val); }
    Z operator+=(const Z& o) { return *this = *this + o; }
    Z operator-=(const Z& o) { return *this = *this - o; }
    Z operator*=(const Z& o) { return *this = *this * o; }
    Z operator/=(const Z& o) { return *this = *this / o; }
    bool operator==(const Z& o) const { return val == o.val; }
    bool operator!=(const Z& o) const { return val != o.val; }

    friend istream& operator>>(istream& in, Z& z) { ll v; in >> v; z = Z(v); return in; }
    friend ostream& operator<<(ostream& out, const Z& z) { return out << z.val; }
};

void solve() {
    int n, q; cin >> n >> q;
    vi a(n), b(n); cin >> a >> b;

    vi ord_a(n), ord_b(n);
    iota(all(ord_a), 0);
    iota(all(ord_b), 0);
    sort(all(ord_a), [&](int i, int j) { return a[i] < a[j]; });
    sort(all(ord_b), [&](int i, int j) { return b[i] < b[j]; });
    sort(all(a));
    sort(all(b));

    Z<MOD> ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= min(a[i], b[i]);
    }
    cout << ans << ' '; 

    while (q--) {
        int o, x; cin >> o >> x; x--;
        if (o == 1) {
            int i = ord_a[x];
            while (i < n - 1 and a[i] + 1 > a[i + 1]) {
                ans /= min(a[i], b[i]);
                ans /= min(a[i + 1], b[i + 1]);
                swap(a[i], a[i + 1]);
                ord_a[x]++;
                ans *= min(a[i], b[i]);
                ans *= min(a[i + 1] + 1, b[i + 1]);
                i++;
            }
            a[i]++;

            cout << ans << ' ';
        } else {
            int i = ord_b[x];
            while (i < n - 1 and b[i] + 1 > b[i + 1]) {
                ans /= min(a[i], b[i]);
                ans /= min(a[i + 1], b[i + 1]);
                swap(b[i], b[i + 1]);
                ord_b[x]++;
                ans *= min(a[i], b[i]);
                ans *= min(a[i + 1], b[i + 1] + 1);
                i++;
            }
            b[i]++;
            
            cout << ans << ' ';
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