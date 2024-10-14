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
    vi r(n); cin >> r;

    // dp[i][j] = max checks passed with i pts intelligence and j pts strength
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0)); 
    vi cur_i_checks, cur_s_checks;
    int total_pts = 0;
    FOR (i, n + 1) {
        if (i < n && r[i] != 0) {
            if (r[i] > 0) {
                cur_i_checks.pb(r[i]);
            } else {
                cur_s_checks.pb(-r[i]);
            }
        } else {
            cur_i_checks.sort();
            cur_s_checks.sort();
            for (int j = 0; j <= total_pts; j++) {
                int max_checks = 0;
                int i_passed = upper_bound(all(cur_i_checks), j) - cur_i_checks.begin();
                int s_passed = upper_bound(all(cur_s_checks), total_pts-j) - cur_s_checks.begin();
                if (j > 0) {
                    max_checks = max(max_checks, dp[j-1][total_pts-j] + i_passed + s_passed);
                }
                if (j < total_pts) {
                    max_checks = max(max_checks, dp[j][total_pts-j-1] + i_passed + s_passed);
                }
                dp[j][total_pts-j] = max_checks;
            }
            total_pts++;
            cur_i_checks.clear();
            cur_s_checks.clear();
        }
    }

    int ans = 0;
    FOR (i, total_pts) {
        ans = max(ans, dp[i][total_pts-i-1]);
    }
    cout << ans;
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}