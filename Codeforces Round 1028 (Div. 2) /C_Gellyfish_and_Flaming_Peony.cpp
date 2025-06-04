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
using int16 = short;
using ll  = long long int;
using pii = pair<int16, int16>;
using pll = pair<ll, ll>;
using vi  = V<int16>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

int16 gcd_memo[5001][5001];
void init_gcd_memo() {
    for (int16 i = 0; i <= 5000; i++) {
        for (int16 j = 0; j <= 5000; j++) {
            gcd_memo[i][j] = gcd(i, j);
        }
    }
}

void solve() {
    int16 n; cin >> n;
    vi a(n); cin >> a;

    int16 gcd_total = 0;
    for (int16 i = 0; i < n; i++) {
        gcd_total = gcd(gcd_total, a[i]);
    }
    for (int16 i = 0; i < n; i++) {
        a[i] /= gcd_total;
    }

    int16 one_cnt = count(all(a), 1);
    if (one_cnt) {
        cout << n - one_cnt;
        return;
    } 

    set<int16> set_unique_a(all(a));
    vi unique_a(all(set_unique_a));
    int16 m = unique_a.size();
    
    for (int16 k = 2; k <= 5; k++) {
        vi indices(k, 0);
        iota(all(indices), 0);
        auto next_indices = [&]() {
            int16 j = k - 1;
            while (j >= 0 && indices[j] >= m - 1 - (k - 1 - j)) {
                j--;
            }
            if (j < 0) return false;
            indices[j]++;
            for (int16 i = j + 1; i < k; i++) {
                indices[i] = indices[i - 1] + 1;
            }
            return true;
        };

        do {
            int16 gcd_ = 0;
            for (int16 i = 0; i < k; i++) {
                gcd_ = gcd_memo[gcd_][unique_a[indices[i]]];
            }
            if (gcd_ == 1) {
                cout << n + k - 2 << ' ';
                return;
            }
        } while (next_indices());
    }
}

int main() {
    init_gcd_memo();
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
        cout << nl;
    }
    
    return 0;
}