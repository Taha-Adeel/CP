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
    V<string> a(n); cin >> a;

    int cnt_w_r0 = 0, cnt_b_r0 = 0, cnt_w_rn = 0, cnt_b_rn = 0;
    int cnt_w_c0 = 0, cnt_b_c0 = 0, cnt_w_cm = 0, cnt_b_cm = 0;
    FOR(i, n) {
        if (a[i][0] == 'W') cnt_w_r0++;
        else cnt_b_r0++;
        if (a[i][m-1] == 'W') cnt_w_rn++;
        else cnt_b_rn++;
    }
    FOR(j, m) {
        if (a[0][j] == 'W') cnt_w_c0++;
        else cnt_b_c0++;
        if (a[n-1][j] == 'W') cnt_w_cm++;
        else cnt_b_cm++;
    }

    if ((a[0][0] == 'W' && cnt_w_rn && cnt_w_cm) || (a[0][0] == 'B' && cnt_b_rn && cnt_b_cm) ||
            (a[0][m-1] == 'W' && cnt_w_r0 && cnt_w_cm) || (a[0][m-1] == 'B' && cnt_b_r0 && cnt_b_cm) ||
            (a[n-1][0] == 'W' && cnt_w_rn && cnt_w_c0) || (a[n-1][0] == 'B' && cnt_b_rn && cnt_b_c0) ||
            (a[n-1][m-1] == 'W' && cnt_w_r0 && cnt_w_c0) || (a[n-1][m-1] == 'B' && cnt_b_r0 && cnt_b_c0)) {
        cout << "YES";
    } else {
        cout << "NO";
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