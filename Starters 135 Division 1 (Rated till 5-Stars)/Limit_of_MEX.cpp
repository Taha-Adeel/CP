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
    ll n; cin >> n;
    vll a(n); cin >> a;

    ll ans = 0; // ans = sigma(max(A) + 1 - distinct(A)) for all subarrays of A.
    ans += n * (n + 1) / 2; // sigma(1) for all subarrays of A.

    // sigma(max(A)) for all subarrays of A.
    vll idx_prev_larger(n, -1), idx_next_larger(n, n);
    stack<int> st;
    FOR (i, n) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            idx_prev_larger[i] = st.top();
        }
        st.push(i);
    }
    while (!st.empty()) st.pop();
    ROF (i, n) {
        while (!st.empty() && a[st.top()] < a[i]) {
            st.pop();
        }
        if (!st.empty()) {
            idx_next_larger[i] = st.top();
        }
        st.push(i);
    }
    FOR (i, n) {
        ans += (i - idx_prev_larger[i]) * (idx_next_larger[i] - i) * a[i];
    }

    // sigma(distinct(A)) for all subarrays of A.
    V<vi> indices(n, {-1});
    FOR (i, n) {
        indices[a[i]].pb(i);
    }
    FOR (i, n) {
        indices[i].pb(n);
    }
    ll dist_sum = 0;
    FOR (i, n) {
        dist_sum += (n * (n + 1)) / 2;
        FOR (j, indices[i].size() - 1) {
            ll len = indices[i][j + 1] - indices[i][j] - 1; 
            dist_sum -= (len * (len + 1)) / 2;
        }
    }
    ans -= dist_sum;

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