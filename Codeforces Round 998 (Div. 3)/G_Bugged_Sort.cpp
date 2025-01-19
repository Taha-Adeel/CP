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
    vi a(n), b(n); cin >> a >> b;

    vi idx(2 * n + 1);
    FOR (i, n) {
        idx[a[i]] = i;
        idx[b[i]] = i;
    }

    V<bool> used(2 * n + 1, false);
    int cur_x = -1, cur_y = -1;
    int num_inversions = 0, num_free = 0;
    for (int k = 1; k <= 2 * n; k++) {
        if (used[k]) continue;
        int i = idx[k];
        int x = a[i], y = b[i];
        if (min(x, y) > max(cur_x, cur_y)) {
            cur_x = x; cur_y = y;
            num_free++;
        } else if (x > cur_x and y > cur_y) {
            cur_x = x; cur_y = y;
        } else if (x > cur_y and y > cur_x) {
            cur_x = y; cur_y = x;
            num_inversions++;
        } else {
            cout << "NO";
            return;
        }
        used[x] = used[y] = true;
    }

    cout << "YES";
    cerr << num_inversions << ' ' << num_free << nl;
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