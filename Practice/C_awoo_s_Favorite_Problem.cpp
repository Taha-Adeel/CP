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
    string s, t; cin >> s >> t;

    vi s_freqs(3, 0), t_freqs(3, 0);
    FOR(i, n) {
        s_freqs[s[i] - 'a']++;
        t_freqs[t[i] - 'a']++;
    }

    if (s_freqs != t_freqs) {
        cout << "NO";
        return;
    }

    int a_cnt_s = 0, a_cnt_t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'c' || t[i] == 'c') {
            if (a_cnt_s != a_cnt_t) {
                cout << "NO";
                return;
            }
        }
        if (s[i] == 'a') a_cnt_s++;
        if (t[i] == 'a') a_cnt_t++;
        if (a_cnt_s < a_cnt_t) {
            cout << "NO";
            return;
        }
    }

    int c_cnt_s = 0, c_cnt_t = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'a' || t[i] == 'a') {
            if (c_cnt_s != c_cnt_t) {
                cout << "NO";
                return;
            }
        }
        if (s[i] == 'c') c_cnt_s++;
        if (t[i] == 'c') c_cnt_t++;
        if (c_cnt_s < c_cnt_t) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
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