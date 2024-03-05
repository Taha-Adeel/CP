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
    int n, l; cin >> n >> l;
    V<pll> a(n); // {b[i], a[i]}
    FOR (i, n) {
        cin >> a[i].second >> a[i].first;
    }

    a.sort();

    auto check_possible = [&](int x) {
        if (x == 0) return true;
        if (x == 1) {
            ll min_a = INT_MAX;
            FOR (i, n) {
                min_a = min(min_a, a[i].second);
            }
            return min_a <= l;
        }

        ll min_sum = 1e18;
        for (int l = 0; l < n - x + 1; l++) {
            ll sum = 0;
            priority_queue<ll> pq;
            for (int i = l + 1; i < l + x - 1; i++) {
                sum += a[i].second;
                pq.push(a[i].second);
            }

            for (int r = l + x - 1; r < n; r++) {
                min_sum = min(min_sum, a[l].second + a[r].second + (a[r].first - a[l].first) + sum);
                sum += a[r].second;
                pq.push(a[r].second);
                sum -= pq.top();
                pq.pop();
            }
        }

        return min_sum <= l;
    };

    // Binary search to find greatest x such that check_possible(x) is true
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (check_possible(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo;
}

int main() {
    FAST;
    int t; cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
    
    return 0;
}