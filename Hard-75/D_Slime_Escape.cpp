#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()        { std::sort(this->begin(), this->end()); }
    void sort_dsc()    { std::sort(this->begin(), this->end(), greater<T>()); }
    auto sum()         { T sum = 0; for(auto& i: *this) sum += i; return sum; }
    auto freqs()       { map<T, int> freq; for(auto& i: *this) freq[i]++; return freq; }
    auto indices()     { int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii; }
    auto prefix_sums() { int n=this->size(); V<long long> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps; }
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
    int n, k; cin >> n >> k; k--;
    vi a(n); cin >> a;

    auto ps = a.prefix_sums();

    int l = k, r = k + 1;
    V<pll> left_grps, right_grps;
    ll P = a[k]; a[k] = 0;
    for(int i = k - 1; i >= 0; i--) {
        if(ps[i] <= ps[l] || i == 0) {
            ll req = 0, cur = 0;
            for(int j = l - 1; j >= i; j--) {
                cur += a[j];
                req = min(req, cur);
            }
            left_grps.push_back({cur, -req});
            l = i;
        }
    }
    for(int i = k + 2; i <= n; i++) {
        if(ps[i] >= ps[r] || i == n) {
            ll req = 0, cur = 0;
            for(int j = r; j <= i - 1; j++) {
                cur += a[j];
                req = min(req, cur);
            }
            right_grps.push_back({cur, -req});
            r = i;
        }
    }
    reverse(left_grps.begin(), left_grps.end());
    reverse(right_grps.begin(), right_grps.end());

    long long curp = P;
    while(true) {
        bool acted = false;
        if(!left_grps.empty() && curp >= left_grps.back().second) {
            curp += left_grps.back().first;
            left_grps.pop_back();
            acted = true;
        }
        if(!right_grps.empty() && curp >= right_grps.back().second) {
            curp += right_grps.back().first;
            right_grps.pop_back();
            acted = true;
        }

        if(left_grps.empty() || right_grps.empty()) pY
        if(!acted) pN
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