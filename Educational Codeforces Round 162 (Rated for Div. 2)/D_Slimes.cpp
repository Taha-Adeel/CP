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

    vll ps = a.prefix_sums();
    vi prev_diff(n, -1), next_diff(n, -1);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            prev_diff[i] = prev_diff[i - 1];
        } else {
            prev_diff[i] = i - 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == a[i + 1]) {
            next_diff[i] = next_diff[i + 1];
        } else {
            next_diff[i] = i + 1;
        }
    }

    FOR (i, n) {
        int left = INT_MAX, right = INT_MAX;
        if (i > 0) {
            if (a[i - 1] > a[i]) {
                left = 1;
            } else {
                int l = 0, r = prev_diff[i - 1];
                if (r == -1 || ps[i] <= a[i]) {
                    left = INT_MAX;
                } else {
                    // Binary search to find largest index j such that ps[i] - ps[j] > a[i]
                    while (l < r) {
                        int m = l + (r - l + 1) / 2;
                        if (ps[i] - ps[m] > a[i]) {
                            l = m;
                        } else {
                            r = m - 1;
                        }
                    }
                    left = i - l;
                }
            }
        }

        if (i < n - 1) {
            if (a[i + 1] > a[i]) {
                right = 1;
            } else {
                int l = next_diff[i + 1], r = n - 1;
                if (l == -1 || ps[n] - ps[i + 1] <= a[i]) {
                    right = INT_MAX;
                } else {
                    // Binary search to find smallest index j such that ps[j] - ps[i + 1] > a[i]
                    while (l < r) {
                        int m = l + (r - l) / 2;
                        if (ps[m + 1] - ps[i + 1] > a[i]) {
                            r = m;
                        } else {
                            l = m + 1;
                        }
                    }
                    right = l - i;
                }
            }
        }

        if (min(left, right) == INT_MAX) {
            cout << -1 << ' ';
        } else {
            cout << min(left, right) << ' ';
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