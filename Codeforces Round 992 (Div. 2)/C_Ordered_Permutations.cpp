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
    ll n, k; cin >> n >> k; k--;

    if (n < 60 and k >= (1LL << (n - 1))) {
        cout << -1;
        return;
    }

    auto same_first_digits = [&](ll i) {
        if (i == 0) {
            return n;
        }
        ll num_bits = __lg(i) + 1;
        return n - (num_bits + 1);
    };

    vll ans(n);
    ll l = 0, r = n - 1, cur = 1;
    bool flipped = false;
    while (cur <= n) {
        ll next = same_first_digits(k);
        if (!flipped) {
            while (cur <= next) {
                ans[l++] = cur++;
            }
        } else {
            while (cur <= next) {
                ans[r--] = cur++;
            }
        }
        flipped = !flipped;

        if (cur == n + 1) break;
        ll smaller_pow_2 = 1;
        while (2 * smaller_pow_2 <= k) {
            smaller_pow_2 *= 2;
        }
        ll dist = k - smaller_pow_2 + 1;
        k = smaller_pow_2 - dist;
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