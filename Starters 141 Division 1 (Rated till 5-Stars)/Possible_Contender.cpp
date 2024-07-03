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

    vi prefix_max(n + 1, 0), prefix_min_idx(n + 1, -1);
    prefix_max[1] = a[0]; prefix_min_idx[1] = 0;
    prefix_max[2] = min(a[0], a[1]); prefix_min_idx[2] = a[0] < a[1] ? 0 : 1;
    for (int i = 2; i < n; i++) {
        if (a[i] <= a[prefix_min_idx[i - 1]]) {
            prefix_max[i + 1] = prefix_max[prefix_min_idx[i - 1] + 1];
            prefix_min_idx[i + 1] = i;
        }
        vi b = {prefix_max[i - 1], a[i - 1], a[i]};
        b.sort();
        prefix_max[i + 1] = max(prefix_max[i + 1], b[1]);
        prefix_max[i + 1] = max(prefix_max[i + 1], min(prefix_max[i], a[i]));
    }
    

    vi suffix_max(n + 1, 0);
    suffix_max[n - 1] = a[n - 1];
    suffix_max[n - 2] = min(a[n - 1], a[n - 2]);
    for (int i = n - 3; i >= 0; i--) {
        vi b = {suffix_max[i + 2], a[i + 1], a[i]};
        b.sort();
        suffix_max[i] = b[1];
    }

    cerr << prefix_max << nl;
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