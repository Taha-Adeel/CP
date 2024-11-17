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

    vi min_suffix(n);
    min_suffix[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        min_suffix[i] = min(min_suffix[i + 1], a[i]);
    }

    vi furthest_smaller(n, -1);
    for (int i = n - 2; i >= 0; i--) {
        int l = i, r = n - 1;
        while (l < r) {
            int m = l + (r - l + 1) / 2;
            if (min_suffix[m] < a[i]) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        if (min_suffix[l] < a[i]) {
            furthest_smaller[i] = l;
        }
    }

    vi comp(n);
    map<int, int> max_ht;
    int cnt = 0, l = 0;
    while (l < n) {
        int r = l;
        while (l <= r) {
            comp[l] = cnt;
            max_ht[cnt] = max(max_ht[cnt], a[l]);
            r = max(r, furthest_smaller[l]);
            l++;
        }
        cnt++;
    }

    for (int i = 0; i < n; i++) {
        cout << max_ht[comp[i]] << ' ';
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