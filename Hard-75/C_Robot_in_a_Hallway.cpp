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

class SparseTable{
    vector<vector<int>> sparse_table;
    vector<int> lg; // Precomputed values of floor(log2(i))

public:
    SparseTable(vector<int>& arr) {
        int n = arr.size();

        // Precompute log values
        lg.reserve(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i/2] + 1;

        // Initialize the sparse table
        int k = lg[n] + 1;
        sparse_table = vector<vector<int>>(n, vector<int>(k));
        for(int i = 0; i < n; i++)
            sparse_table[i][0] = arr[i];
        
        // Populate the sparse table
        for(int j = 1; j < k; j++)
            for(int i = 0; i + (1 << j) <= n; i++)
                sparse_table[i][j] = max(sparse_table[i][j-1], sparse_table[i + (1 << (j - 1))][j - 1]);
    }

    int query(int l, int r) {
        int j = lg[r - l + 1];
        int value = max(sparse_table[l][j], sparse_table[r - (1 << j) + 1][j]);

        return value;
    }
};

void solve() {
    int n; cin >> n;
    V<vi> a(2, vi(n)); cin >> a;

    vi mid;
    FOR (i, n) {
        if (i % 2 == 0) {
            mid.pb(a[0][i]);
            mid.pb(a[1][i]);
        } else {
            mid.pb(a[1][i]);
            mid.pb(a[0][i]);
        }
    }

    vi left;
    FOR (i, n) left.pb(a[0][i] - i);
    FOR (i, n) left.pb(a[1][n - 1 - i] - n - i);
    SparseTable st1(left);

    vi right;
    FOR (i, n) right.pb(a[1][i] - i);
    FOR (i, n) right.pb(a[0][n - 1 - i] - n - i);
    SparseTable st2(right);

    auto possible = [&](int x) {
        int t = x - (2 * n - 1);
        int ll = 1, lr = 2 * n - 1, rl = 2, rr = 2 * n - 2;
        FOR (i, 2 * n) {
            if (i && t <= mid[i]) return false;
            if (i % 4 == 0) {
                if (t >= st1.query(ll, lr) + ll) {
                    return true;
                }
                ll += 2;
                lr -= 2;
            } else if (i % 4 == 2) {
                if (t >= st2.query(rl, rr) + rl) {
                    return true;
                }
                rl += 2;
                rr -= 2;
            }
            t++;
        }

        return true;
    };

    // Find smallest x such that possible(x) is true
    int l = 0, r = 2e9;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (possible(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << l;
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