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
using ll  = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

int MOD;
class Z {
    static vector<Z> fact;
public:
    int val;
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
    bool operator<(const Z& o) const { return val < o.val; }
    bool operator<=(const Z& o) const { return val <= o.val; }
    bool operator>(const Z& o) const { return val > o.val; }
    bool operator>=(const Z& o) const { return val >= o.val; }

    friend istream& operator>>(istream& in, Z& z) { ll v; in >> v; z = Z(v); return in; }
    friend ostream& operator<<(ostream& out, const Z& z) { return out << z.val; }
};

void solve() {
    int n, m, x; cin >> n >> m >> x;

    MOD = n;
    set<Z> s = {x - 1};
    FOR (i, m) {
        int d; cin >> d;
        char dir; cin >> dir;

        set<Z> ns;
        for (auto& z : s) {
            if (dir != '1') {
                ns.insert(z + d);
            }
            if (dir != '0') {
                ns.insert(z - d);
            }
        }
        s = ns;
    }

    cout << s.size() << nl;
    for (auto& z : s) {
        cout << z.val + 1 << ' ';
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