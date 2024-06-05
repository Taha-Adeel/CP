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
    int n, m; cin >> n >> m;
    V<vi> a(n, vi(m)), b(n, vi(m)); cin >> a >> b;

    auto swap_col = [](int col1, int col2, V<vi>& mat) {
        FOR (i, mat.size()) {
            swap(mat[i][col1], mat[i][col2]);
        }
    };
    auto swap_row = [](int row1, int row2, V<vi>& mat) {
        swap(mat[row1], mat[row2]);
    };

    pii a_one_idx = {-1, -1}, b_one_idx = {-1, -1};
    FOR (i, n) {
        FOR (j, m) {
            if (a[i][j] == 1) {
                a_one_idx = {i, j};
            }
            if (b[i][j] == 1) {
                b_one_idx = {i, j};
            }
        }
    }

    swap_row(a_one_idx.first, 0, a);
    swap_col(a_one_idx.second, 0, a);
    swap_row(b_one_idx.first, 0, b);
    swap_col(b_one_idx.second, 0, b);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto transpose = [](V<vi>& mat) {
        V<vi> res(mat[0].size(), vi(mat.size()));
        FOR (i, mat.size()) {
            FOR (j, mat[0].size()) {
                res[j][i] = mat[i][j];
            }
        }
        return res;
    };

    V<vi> a_t = transpose(a), b_t = transpose(b);
    sort(a_t.begin(), a_t.end());
    sort(b_t.begin(), b_t.end());

    if (a_t == b_t) {
        cout << "YES";
    } else {
        cout << "NO";
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