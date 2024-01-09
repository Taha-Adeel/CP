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
    int n; cin >> n;
    vi a(n); cin >> a;

    int l = 0, r = n - 1;
    while(l < r and a[l] == 1) l++;
    while(r > l and a[r] == 1) r--;

    ll prod = 1;
    for(int i = l; i <= r; ++i) {
        prod *= a[i];
        if(prod > 1e9) {
            cout << l + 1 << ' ' << r + 1;
            return;
        }
    }

    vi idx_not_1s;
    for(int i = l; i <= r; ++i) {
        if(a[i] != 1) idx_not_1s.pb(i);
    }

    int sum = a.sum();
    int l_ans = 1, r_ans = 1, ans = sum;
    for(int i = 0; i < idx_not_1s.size(); ++i) {
        int l = idx_not_1s[i], cur_prod = 1, cur_sum = 0;
        for(int j = i; j < idx_not_1s.size(); ++j) {
            int r = idx_not_1s[j];
            cur_prod *= a[r];
            cur_sum += a[r] - 1;
            int cur_ans = sum - (r - l + 1) - cur_sum + cur_prod;
            if(cur_ans > ans) {
                ans = cur_ans;
                l_ans = l + 1;
                r_ans = r + 1;
            }
        }
    }

    cout << l_ans << ' ' << r_ans;
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