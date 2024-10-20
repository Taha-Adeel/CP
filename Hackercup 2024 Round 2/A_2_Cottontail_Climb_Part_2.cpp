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

vll get_nums() {
    V<V<string>> nums_s;
    nums_s.pb({"1", "2", "3", "4", "5", "6", "7", "8", "9"});
    for (int l = 1; l <= 9; l++) {
        V<string> new_nums;
        for (auto& s: nums_s.back()) {
            for (int diff = 0; diff < 9; diff++) {
                if (s.back() + diff > '9') break;
                string new_s = s + char(s.back() + diff);
                new_nums.pb(new_s);
            }
        }
        nums_s.pb(new_nums);
    }

    V<V<string>> nums;
    for (auto& v: nums_s) {
        V<string> new_nums;
        for (auto& s: v) {
            int n = s.size();
            if (n > 1 and s[n - 1] == s[n - 2]) continue;
            new_nums.pb(s);
        }
        nums.pb(new_nums);
    }

    vll nums_i;
    for (auto& v: nums) {
        for (auto& s1: v) {
            for (auto s2: v) {
                if (s1.back() != s2.back()) continue;
                reverse(all(s2));
                string s = s1 + s2.substr(1);
                nums_i.pb(stoll(s));
            }
        }
    }
    nums_i.sort();

    // cerr << nums_i.size() << nl;
    // cerr << nums_i << nl;

    return nums_i;
}
auto nums = get_nums();

void solve() {
    ll a, b, m; cin >> a >> b >> m;

    int ans = 0;
    for (ll x: nums) {
        if (x > b) break;
        if (a <= x && x <= b && x % m == 0) {
            ans++;
        }
    }

    cout << ans;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        cout << "Case #" << t+1 << ": ";
        solve();
        cout << nl;
    }
    
    return 0;
}