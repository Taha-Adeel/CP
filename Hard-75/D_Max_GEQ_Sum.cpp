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
    vector<vector<ll>> sparse_table;
    vector<ll> lg; // Precomputed values of floor(log2(i))

public:
    SparseTable(vector<ll>& arr) {
        int n = arr.size();

        // Precompute log values
        lg.reserve(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i/2] + 1;

        // Initialize the sparse table
        ll k = lg[n] + 1;
        sparse_table = vector<vector<ll>>(n, vector<ll>(k));
        for(int i = 0; i < n; i++)
            sparse_table[i][0] = arr[i];
        
        // Populate the sparse table
        for(int j = 1; j < k; j++)
            for(int i = 0; i + (1 << j) <= n; i++)
                sparse_table[i][j] = max(sparse_table[i][j-1], sparse_table[i + (1 << (j - 1))][j - 1]);
    }

    ll query(int l, int r) {
        int j = lg[r - l + 1];
        ll value = max(sparse_table[l][j], sparse_table[r - (1 << j) + 1][j]);

        return value;
    }
};

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    vi next_larger_idx(n, n);
    stack<int> s;
    FOR(i, n) {
        while(!s.empty() && a[s.top()] < a[i]) {
            next_larger_idx[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    vi prev_larger_idx(n, -1);
    s = stack<int>();
    ROF(i, n) {
        while(!s.empty() && a[s.top()] < a[i]) {
            prev_larger_idx[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    vll pref_sums(n + 1, 0), suff_sums(n + 1, 0);
    FOR(i, n) pref_sums[i+1] = pref_sums[i] + a[i];
    ROF(i, n) suff_sums[i] = suff_sums[i+1] + a[i];

    SparseTable st_prefs(pref_sums), st_suffs(suff_sums);

    FOR(i, n) {
        ll right_max = st_prefs.query(i + 1, next_larger_idx[i]) - pref_sums[i + 1];
        ll left_max = st_suffs.query(prev_larger_idx[i] + 1, i) - suff_sums[i];
        if(right_max > 0 || left_max > 0) {
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