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
    int n, m; cin >> n >> m;
    vll a(n + m + 1), b(n + m + 1); cin >> a >> b;

    V<bool> is_p(n + m, false);
    auto compute = [&](int x) {
        ll ans = 0, p_cnt = 0, t_cnt = 0, j = 0;
        for (int i = 0; i < n + m + 1; i++) {
            if (i == x) continue;
            if ((a[i] > b[i] and p_cnt < n) or t_cnt >= m) {
                is_p[j] = true;
                p_cnt++;
                ans += a[i];
            } else {
                ans += b[i];
                t_cnt++;
            }
            j++;
        }
        return ans;
    };

    ll ans = compute(0);
    cout << ans << ' ';
    
    ll p_cnt = 0, t_cnt = 0;
    for (int i = 0; i < n + m; i++) {
        if (is_p[i]) {
            if (t_cnt >= m or (p_cnt < n and a[i] > b[i])) {
                ans -= a[i + 1];
                ans += a[i];
                p_cnt++;
            } else {

            }
        } else {
            if (p_cnt >= n or (t_cnt < m and b[i] > a[i])) {
                ans -= b[i + 1];
                ans += b[i];
                t_cnt++;
            } else {

            }
        }

        cout << ans << ' ';
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