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

#define nl endl;
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vll a(n); for (auto& i: a) cin >> i;

    auto max_subarray_sum = [&](int l, int r) {
        if (l > r) return 0LL;
        ll current_sum = 0, max_sum = 0;
        for (int i = l; i <= r; ++i) {
            current_sum += a[i];
            max_sum = max(max_sum, current_sum);
            if (current_sum < 0) current_sum = 0;
        }
        // cerr << a << ' ' << "max_subarray_sum(" << l << ", " << r << ") = " << max_sum << nl;
        return max_sum;
    };

    vll ps = a.prefix_sums();

    int zero_cnt = count(all(s), '0');
    if (zero_cnt == 0) {
        if (max_subarray_sum(0, n - 1) == k) {
            cout << "Yes" << nl;
            cout << a;
        } else {
            cout << "No";
        }
    } 
    else if (zero_cnt == 1) {
        int i = find(all(s), '0') - s.begin();
        ll a_max = max_subarray_sum(0, i - 1);
        ll b_max = max_subarray_sum(i + 1, n - 1);

        if (max(a_max, b_max) > k) {
            cout << "No";
        } else if (a_max == k or b_max == k) {
            cout << "Yes" << nl;
            a[i] = -1e17;
            cout << a;
        } else {
            ll a_max_ps = ps[i] - *min_element(ps.begin(), ps.begin() + i + 1);
            ll b_max_ps = *max_element(ps.begin() + i + 1, ps.end()) - ps[i + 1];
            cout << "Yes" << nl;
            a[i] = k - (a_max_ps + b_max_ps);
            cout << a;
        }
    } 
    else if (zero_cnt == 2) {
        int i = find(all(s), '0') - s.begin();
        int j = find(s.begin() + i + 1, s.end(), '0') - s.begin();

        ll a_max = max_subarray_sum(0, i - 1);
        ll b_max = max_subarray_sum(i + 1, j - 1);
        ll c_max = max_subarray_sum(j + 1, n - 1);
        if (max({a_max, b_max, c_max}) > k) {
            cout << "No";
        } else if (a_max == k or b_max == k or c_max == k) {
            cout << "Yes" << nl;
            a[i] = a[j] = -1e17;
            cout << a;
        } else {
            ll a_max_ps = ps[i] - *min_element(ps.begin(), ps.begin() + i + 1);
            ll b_max_ps_l = *max_element(ps.begin() + i + 1, ps.begin() + j + 1) - ps[i + 1];
            cout << "Yes" << nl;
            a[i] = k - (a_max_ps + b_max_ps_l);
            a[j] = -1e17;
            cout << a;
        }
    } 
    else {
        int prev_i = -1, cur_i = 0;
        ll max_ans = 0;
        for (; cur_i <= n; cur_i++) {
            if (cur_i == n or s[cur_i] == '0') {
                max_ans = max(max_ans, max_subarray_sum(prev_i + 1, cur_i - 1));
                prev_i = cur_i;
            }
        }

        if (max_ans > k) {
            cout << "No";
        } else if (max_ans == k) {
            cout << "Yes" << nl;
            FOR(i, n) {
                if (s[i] == '0') {
                    a[i] = -1e17;
                }
            }
            cout << a;
        } else {
            int i = find(all(s), '0') - s.begin();
            int j = find(s.begin() + i + 1, s.end(), '0') - s.begin();
            ll a_max_ps = ps[i] - *min_element(ps.begin(), ps.begin() + i + 1);
            ll b_max_ps_l = *max_element(ps.begin() + i + 1, ps.begin() + j + 1) - ps[i + 1];
            cout << "Yes" << nl;
            FOR (x, n) {
                if (s[x] == '0') {
                    a[x] = -1e17;
                }
            }
            a[i] = k - (a_max_ps + b_max_ps_l);
            cout << a;
        }
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