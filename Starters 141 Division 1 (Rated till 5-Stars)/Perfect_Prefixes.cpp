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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll max_subarray_sum(vi& a) {
    ll ans = 0, sum = 0;
    for (int x: a) {
        sum += x;
        ans = max(ans, sum);
        sum = max(0LL, sum);
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    vi swap_gain_odd(n, 0), swap_gain_even(n, 0);

    int ans = 0;
    ordered_set<int> s;
    FOR (i, n) {
        s.insert(a[i]);
        if (s.find(i + 1) != s.end() and s.order_of_key(i + 1) == i) {
            if (i % 2 == 0) swap_gain_even[i] = -1;
            else swap_gain_odd[i] = -1;
            ans++;
        } else {
            s.erase(a[i]);
            if (i < n - 1) {
                s.insert(a[i + 1]);
                if (s.find(i + 1) != s.end() and s.order_of_key(i + 1) == i) {
                    if (i % 2 == 0) swap_gain_even[i + 1] = 1;
                    else swap_gain_odd[i + 1] = 1;
                }
                s.erase(a[i + 1]);
            }
            s.insert(a[i]);
        }
    }

    cout << ans + max(max_subarray_sum(swap_gain_odd), max_subarray_sum(swap_gain_even));
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