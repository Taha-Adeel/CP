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
    int n, q; cin >> n >> q;
    vll a(n), ks(q); cin >> a >> ks;

    vll ans(n);
    ll pos_sum = 0, neg_sum = 0;
    priority_queue<ll, vll, greater<ll>> greater_half; // min heap
    priority_queue<ll> smaller_half; // max heap

    auto insert = [&](ll x) {
        if (greater_half.empty() || x >= greater_half.top()) {
            greater_half.push(x);
            pos_sum += x;
        } else {
            smaller_half.push(x);
            neg_sum += x;
        }
        if (greater_half.size() > smaller_half.size() + 1) {
            ll top = greater_half.top();
            greater_half.pop();
            pos_sum -= top;
            neg_sum += top;
            smaller_half.push(top);
        } else if (smaller_half.size() > greater_half.size()) {
            ll top = smaller_half.top();
            smaller_half.pop();
            neg_sum -= top;
            pos_sum += top;
            greater_half.push(top);
        }
    };

    ans[0] = a[0];
    insert(a[0]);
    for (int i = 1; i < n; i++) {
        insert(a[i]);
        ans[i] = pos_sum - neg_sum;
    }

    for (auto k: ks) {
        cout << ans[k-1] << ' ';
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