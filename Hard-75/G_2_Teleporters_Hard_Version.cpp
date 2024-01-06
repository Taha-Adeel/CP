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
    int n, c; cin >> n >> c;
    vi a(n); cin >> a;

    V<pii> costs(n);
    FOR(i, n) 
        costs[i] = {a[i] + min(i + 1, n - i), i};
    costs.sort();

    vll idx(n), costs_ps(n + 1, 0);
    FOR(i, n) 
        idx[costs[i].second] = i + 1,
        costs_ps[i + 1] = costs_ps[i] + costs[i].first;

    int ans = 0;
    FOR(i, n) {
        // We use the ith teleporter first, then greedily use the rest.
        int spent = a[i] + i + 1, rem = c - spent;
        if(rem < 0) continue;
        
        // Binary search to find largest j s.t. costs_ps[j] <= rem
        int lo = 0, hi = n;
        while(lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if(costs_ps[mid] <= rem) lo = mid;
            else hi = mid - 1;
        }

        if(idx[i] > lo) ans = max(ans, lo + 1);
        else {
            rem -= costs_ps[min(lo + 1, n)];
            rem += costs[idx[i] - 1].first;
            if(rem >= 0) ans = max(ans, min(lo + 1, n));
            else ans = max(ans, lo);
        }
    }

    cout << ans;
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