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
    vi a(n); cin >> a;

    reverse(all(a));

    vi pref_xor(n, 0);
    pref_xor[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref_xor[i] = pref_xor[i - 1] ^ a[i];
    }

    V<vi> b(n + 1, vi(31, n-1)); // b[i][k] = next j such that a[j] >= 2^k
    for (int k = 0; k < 31; k++) {
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] >= (1 << k)) {
                b[i][k] = i;
            } else {
                b[i][k] = b[i + 1][k];
            }
        }
    }

    auto greatest_bit = [](int x) {
        int ans = 0, mask = 1;
        while ((2 * mask) <= x) {
            mask <<= 1;
            ans++;
        }
        return ans;
    };

    while (q--) {
        int xi; cin >> xi;

        int ans = 0;
        int i = 0, x = xi;
        while (i < n and x >= a[i]) {
            int k = greatest_bit(x);
            int next = b[i][k];
            if (next and (xi ^ pref_xor[next - 1]) < a[next]) {
                i = next;
                break;
            }
            x = xi ^ pref_xor[next];
            i = next + 1;
        }

        cout << i << ' ';
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