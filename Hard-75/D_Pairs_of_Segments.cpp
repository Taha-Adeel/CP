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
#define FOR1(i, n)    for(int i = 1; i < (int)n; ++i)
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
    V<pii> ranges(n);
    for (auto& [l, r]: ranges) {
        cin >> l >> r;
    }

    auto intersect = [&](int i, int j) {
        return (ranges[i].first <= ranges[j].second && ranges[i].second >= ranges[j].first)
            || (ranges[j].first <= ranges[i].second && ranges[j].second >= ranges[i].first);
    };

    auto merge = [&](int i, int j) {
        return pii(max(ranges[i].second, ranges[j].second), min(ranges[i].first, ranges[j].first));
    };

    V<pii> merged_ranges; // {r, l}
    FOR(i, n) {
        for(int j = 0; j < i; j++)
            if(intersect(i, j))
                merged_ranges.push_back(merge(i, j));
    }

    merged_ranges.sort(); // Sort by end points
    int ans = 0, cur_r = -1;
    for(auto& [r, l]: merged_ranges) {
        if(l > cur_r) {
            ans++;
            cur_r = r;
        }
    }

    cout << n - 2 * ans;
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