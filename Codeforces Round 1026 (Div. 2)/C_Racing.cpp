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
    vi d(n); cin >> d;
    vi l(n), r(n);
    FOR (i, n) {
        cin >> l[i] >> r[i];
    }

    int max_l = 0;
    for (int i = 0; i < n; i++) {
        max_l = max(max_l, l[i]);
        l[i] = max_l;
    }

    int min_r = n;
    for (int i = n - 1; i >= 0; i--) {
        min_r = min(min_r, r[i]);
        r[i] = min_r;
    }

    stack<int> st;
    int cur_ht = 0;
    FOR (i, n) {
        if (l[i] > r[i]) {
            cout << -1;
            return;
        }

        if (d[i] != -1) {
            cur_ht += d[i];
        } else {
            st.push(i);
        }
        if (cur_ht < l[i]) {
            while (!st.empty() and cur_ht < l[i]) {
                int idx = st.top(); st.pop();
                d[idx] = 1;
                cur_ht++;
            }
            if (cur_ht < l[i]) {
                cout << -1;
                return;
            }
        }
    }

    cur_ht = 0;
    FOR (i, n) {
        if (d[i] == -1) {
            d[i] = 0;
        }
        cur_ht += d[i];
        if (cur_ht < l[i] || cur_ht > r[i]) {
            cout << -1;
            return;
        }
    }

    cout << d;
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