#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()        { std::sort(this->begin(), this->end()); }
    void sort_dsc()    { std::sort(this->begin(), this->end(), greater<T>()); }
    auto sum()         { T sum = 0; for(auto& i: *this) sum += i; return sum; }
    auto freqs()       { map<T, int> freq; for(auto& i: *this) freq[i]++; return freq; }
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
    vi p(n), q(n); cin >> p >> q;

    vll idx_p(n), idx_q(n);
    FOR(i, n) {
        idx_p[p[i] - 1] = i;
        idx_q[q[i] - 1] = i;
    }

    ll ans = 1; // [1..n] is always possible.

    // Number of pairs where mex is 0.
    ll l = min(idx_p[0], idx_q[0]), r = max(idx_p[0], idx_q[0]);
    ans += (l * (l + 1)) / 2 + ((n - r - 1) * (n - r)) / 2 + ((r - l - 1) * (r - l)) / 2;

    FOR1(mex, n) {
        auto [li, ri] = minmax(idx_p[mex], idx_q[mex]);

        if((li >= l && li <= r) || (ri >= l && ri <= r)) // If they are in between [l, r], then MEX = mex is not possible.
            ans += 0;
        else if(li <= l && ri >= r) // If they contain [l, r]
            ans += (l - li) * (ri - r);
        else if(ri < l) // If they are behind [l, r]
            ans += (l - ri) * (n - r);
        else if(li > r) // If they are ahead of [l, r]
            ans += (li - r) * (l + 1);

        l = min(l, li);
        r = max(r, ri);
    }

    cout << ans;
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}