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
    vll a(n); cin >> a;

    ll total = a.sum();
    if (total % 2 != 0) {
        cout << -1;
        return;
    }

    ll cur_sum = 0, target = total / 2;
    vll b = a;
    int i = 0;
    for (; i < n; i++) {
        cur_sum += a[i];
        if (cur_sum >= target) {
            break;
        }
    }

    ll s1 = cur_sum - a[i], s2 = total - cur_sum;
    
    if (cur_sum == s2) {
        cout << 1 << nl;
        cout << b;
        return;
    }

    if (s1 >= (cur_sum - s2) / 2) {
        ll extra = cur_sum - s2;
        b[i] -= extra / 2;
        extra -= extra / 2;
        for (int j = 0; j < i; j++) {
            ll to_remove = min(b[j], extra);
            extra -= to_remove;
            b[j] -= to_remove;
        }
    }
    else if (s2 >= (s2 + a[i] - s1) / 2) {
        ll extra = s2 + a[i] - s1;
        for (int j = i + 1; j < n; j++) {
            ll to_remove = min(b[j], extra);
            extra -= to_remove;
            b[j] -= to_remove;
        }
    }
    else {
        cout << -1;
        return;
    }

    for (int i = 0; i < n; i++) {
        a[i] -= b[i];
    }

    cout << 2 << nl;
    cout << b << nl;
    cout << a;
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