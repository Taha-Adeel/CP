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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    auto check = [n, k] (string s) {
        char cur = s[0];
        FOR (i, n) {
            if (s[i] != cur) {
                return false;
            }
            if (i % k == k - 1) {
                cur ^= '0' ^ '1';
            }
        }
        return true;
    };

    bool good = check(s);
    if (good) {
        cout << n;
        return;
    }

    int last_block_len = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != s[n - 1]) {
            break;
        }
        last_block_len++;
    }

    if (last_block_len > k) {
        cout << -1;
        return;
    }

    int req = k - last_block_len;
    char req_c = s[n - 1];
    if (req == 0) {
        req = k;
        req_c ^= '0' ^ '1';
    }

    int cur_block_len = 0, l = 0, r = 0;
    while (l < n) {
        while (r < n && s[l] == s[r]) {
            r++;
        }
        cur_block_len = r - l;

        if (cur_block_len != k) {
            if (s[l] != req_c) {
                cout << -1;
                return;
            }
            int p = l + req;
            if (p > n) {
                cout << -1;
                return;
            }

            string a = s.substr(0, p);
            string b = s.substr(p, n - p);
            reverse(all(a));
            b += a;
            if (check(b)) {
                cout << p;
                return;
            } else {
                cout << -1;
                return;
            }
        }
        l = r;
    }

    cout << -1;
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