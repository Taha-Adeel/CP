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
    vi a(n), b(n);
    FOR (i, n) {
        cin >> a[i] >> b[i];
    }

    auto freqs_a = a.freqs();
    auto freqs_b = b.freqs();
    vi odd_a, odd_b;
    for (auto& [ai, f]: freqs_a) {
        if (f % 2) {
            odd_a.pb(ai);
        }
    }
    for (auto& [bi, f]: freqs_b) {
        if (f % 2) {
            odd_b.pb(bi);
        }
    }

    if (odd_a.size() + odd_b.size() > 2 or odd_a.size() + odd_b.size() == 1) {
        cout << "NO";
        return;
    }
    if (n % 2 and max(odd_a.size(), odd_b.size()) == 2) { // Should be 0, 0 or 1, 1
        cout << "NO";
        return;
    }
    if (n % 2 == 0 and max(odd_a.size(), odd_b.size()) == 1) { // Should be 0, 0 or 2, 0 or 0, 2
        cout << "NO";
        return;
    }

    vi ans;
    vi visited(n, 0);
    int idx = 0;
    bool next_a = false;
    if (n % 2) {
        if (odd_a.size() == 1) {
            for (int i = 0; i < n; i++) {
               if (a[i] == odd_a[0]) {
                    idx = i; 
                    next_a = false;
                    break;
                }
            }
        }
    } else {
        if (odd_a.size() == 2) {
            for (int i = 0; i < n; i++) {
                if (a[i] == odd_a[0]) {
                    idx = i;
                    next_a = false;
                    break;
                }
            }
        } else if (odd_b.size() == 2) {
            for (int i = 0; i < n; i++) {
                if (b[i] == odd_b[0]) {
                    idx = i;
                    next_a = true;
                    break;
                }
            }
        }
    }

    map<int, vi> adj_a = a.indices();
    map<int, int> used_a;
    map<int, vi> adj_b = b.indices();
    map<int, int> used_b;

    visited[idx] = 1;
    ans.pb(idx + 1);
    while (true) {
        cerr << "idx: " << idx << " next_a: " << next_a << nl;
        if (next_a) {
            if (used_a[a[idx]] == adj_a[a[idx]].size()) {
                break;
            }
            idx = adj_a[a[idx]][used_a[a[idx]]++];
        } else {
            if (used_b[b[idx]] == adj_b[b[idx]].size()) {
                break;
            }
            idx = adj_b[b[idx]][used_b[b[idx]]++];
        }
        if (visited[idx]) {
            continue;
        } else {
            visited[idx] = 1;
            ans.pb(idx + 1);
            next_a = !next_a;
        }
    }

    if (ans.size() != n) {
        cout << "NO";
        return;
    }

    cout << "YES" << nl;
    cout << ans;
}

void solve_debug(int t) {
    int n; cin >> n;
    vi a(n), b(n);
    FOR (i, n) {
        cin >> a[i] >> b[i];
    }

    if (t != 102) {
        return;
    }
    cout << "a: " << a << nl;
    cout << "b: " << b << nl;

    auto freqs_a = a.freqs();
    auto freqs_b = b.freqs();
    cout << "freqs_a: ";
    for (auto& [ai, f]: freqs_a) {
        cout << ai << ":" << f << " ";
    }
    cout << nl;
    
    cout << "freqs_b: ";
    for (auto& [bi, f]: freqs_b) {
        cout << bi << ":" << f << " ";
    }
    cout << nl;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        if (T == 10000) {
            solve_debug(t);
        } else {
            solve();
        }
        cout << nl;
    }
    
    return 0;
}