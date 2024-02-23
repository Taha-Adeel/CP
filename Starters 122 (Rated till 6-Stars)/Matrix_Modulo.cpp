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
    ll n; cin >> n;
    V<vll> a(n, vll(n)); cin >> a;

    ll zero_cnt = 0;
    FOR(i, n) {
        FOR(j, n) {
            if (a[i][j] == 0) zero_cnt++;
        }
    }
    if (zero_cnt == 0) {
        cout << 0;
        return;
    }
    

    ll k = (n * (n + 1)) / 2;
    ll num_pairs = (n * (n - 1)) / 2;

    ll ans = 1;

    // Check diagonal
    zero_cnt = 0;
    FOR(i, n) {
        if (a[i][i] == 0) {
            zero_cnt++;
            (ans *= zero_cnt) %= MOD;
            continue;
        }
        if (a[i][i] == k) continue;
        if (a[i][i] % k <= num_pairs) {
            ans = 0;
        }
    }

    // Check remaining
    zero_cnt = 0;
    FOR(i, n) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] == 0 and a[j][i] == 0) {
                zero_cnt++;
                (ans *= zero_cnt) %= MOD;
                (ans *= 2) %= MOD;
            } else if (a[i][j] == 0) {
                if (a[j][i] % k > num_pairs or a[j][i] == k) {
                    ans = 0;
                }
            } else if (a[j][i] == 0) {
                if (a[i][j] % k > num_pairs or a[i][j] == k) {
                    ans = 0;
                }
            } else if (a[i][j] % k != a[j][i] % k or a[i][j] % k > num_pairs or a[j][i] % k > num_pairs or a[i][j] == k or a[j][i] == k) {
                ans = 0;
            }
        }
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