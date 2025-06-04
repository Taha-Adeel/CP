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

void solve(int t) {
    ll n, k; cin >> n >> k;
    vll a(n); cin >> a;

    auto ops = [](ll x) {
        ll pow2 = 1;
        while (x % (2 * pow2) == 0) {
            pow2 *= 2;
        }
        return pow2;
    };
 
    auto is_pow2 = [](ll x) {
        return (x & (x - 1)) == 0;
    };
 
    vll prefix_ops(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_ops[i + 1] = ops(a[i]) + prefix_ops[i];
        if (i < n - 1 && a[i] % a[i + 1] == 0 && is_pow2(a[i] / a[i + 1])) {
            prefix_ops[i + 1] -= (ops(2 * a[i + 1]) - 1);
        }
    }
 
    vll suffix_ops(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suffix_ops[i] = ops(a[i]) + suffix_ops[i + 1];
        if (i > 0 && a[i] % a[i - 1] == 0 && is_pow2(a[i] / a[i - 1])) {
            suffix_ops[i] -= (ops(2 * a[i - 1]) - 1);
        }
    }
 
    ll max_ops = 0;
    for (int i = 0; i < n; i++) {
        max_ops = max(max_ops, ops(a[i]) + prefix_ops[i] + suffix_ops[i + 1]);
    }

    display(k <= max_ops);
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve(t + 1);
        cout << nl;
    }

    return 0;
}