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

void answer(int i, int j) {
    cout << "! " << i << ' ' << j << endl;
}

char query(int a, int b, int c, int d) {
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    char cd; cin >> cd;
    return cd;
}

int query_greater(int a, int b) {
    char c = query(a, a, b, b);
    if (c == '>') return a;
    else return b;
}

int get_idx_n(int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        idx = query_greater(idx, i);
    }
    return idx;
}

set<int> get_set(int n, int idx) {
    set<int> s;
    int cur_idx = idx;
    for (int i = 0; i < n; i++) {
        if (i == idx) continue;
        char c = query(idx, cur_idx, idx, i);
        if (c == '<') {
            cur_idx = i;
            s = {i};
        } else if (c == '=') {
            s.insert(i);
        }
    }
    return s;
}

int get_min_idx(set<int>& s) {
    int min_idx = *s.begin();
    for (int i: s) {
        if (query_greater(i, min_idx) == min_idx) {
            min_idx = i;
        }
    }
    return min_idx;
}

void solve() {
    int n; cin >> n;

    int idx_n = get_idx_n(n);
    set<int> s = get_set(n, idx_n);
    int min_idx = get_min_idx(s);

    answer(idx_n, min_idx);
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