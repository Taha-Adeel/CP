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
#define rall(v)       v.rbegin(), v.rend()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    V<pii> ops;

    V<pii> a_idx, a_idx_sorted;
    FOR(i, n) 
        a_idx.pb({a[i], i});
    a_idx_sorted = a_idx;
    a_idx_sorted.sort();

    map<pii, int> pos;
    FOR(i, n)
        pos[{a[i], i}] = i;

    auto swap_op = [&](int i, int j) {
        if(i == j) return;
        ops.pb({i+1, j+1});
        ops.pb({j+1, i+1});
        ops.pb({i+1, j+1});
        swap(pos[a_idx[i]], pos[a_idx[j]]);
        swap(a_idx[i], a_idx[j]);
    };

    FOR(i, n)
        swap_op(i, pos[a_idx_sorted[i]]);

    cout << ops.size() << nl;
    for(auto& [x, y]: ops)
        cout << x << ' ' << y << nl;
}

int main(){
    FAST;
    int T; cin >> T;
    FOR(t, T){
        solve();
    }
    
    return 0;
}