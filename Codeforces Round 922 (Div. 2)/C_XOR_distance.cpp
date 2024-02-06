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
    ll a, b, r; cin >> a >> b >> r;

    if (a == b) {
        cout << 0;
        return;
    }

    ll dif = a ^ b, ans = LLONG_MAX;
    ll mask = 1LL << (__lg(dif));

    if ((a & mask) or ((b & mask) and mask <= r)) {
        ll x = (a & mask) ? 0 : mask;
        ll ans1 = mask;
        mask >>= 1;
        while (mask) {
            if (mask & dif) {
                if (a & mask) {
                    if ((x | mask) <= r) {
                        x |= mask;
                        ans1 -= mask;
                    } else {
                        ans1 += mask;
                    }
                } else {
                    ans1 -= mask;
                }
            }
            mask >>= 1;
        }
        ans = ans1;
    }

    mask = 1LL << (__lg(dif));
    swap(a, b);

    if ((a & mask) or ((b & mask) and mask <= r)) {
        ll x = (a & mask) ? 0 : mask;
        ll ans2 = mask;
        mask >>= 1;
        while (mask) {
            if (mask & dif) {
                if (a & mask) {
                    if ((x | mask) <= r) {
                        x |= mask;
                        ans2 -= mask;
                    } else {
                        ans2 += mask;
                    }
                } else {
                    ans2 -= mask;
                }
            }
            mask >>= 1;
        }
        ans = min(ans, ans2);
    }

    cout << ans;
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