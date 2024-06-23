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
    ll n, k; cin >> n >> k;
    vll a(n); cin >> a;

    map<ll, vll> mp;
    FOR (i, n) {
        mp[a[i] % k].pb(a[i] / k);
    }

    ll odd_cnt = 0, odd_mod = -1;
    for (auto& [mod, v]: mp) {
        if (v.size() % 2) {
            odd_mod = mod;
            odd_cnt++;
        }
    }

    if (odd_cnt > 1 || odd_cnt != n % 2) {
        cout << -1;
        return;
    }

    ll ans = 0;
    for (auto& [mod, v]: mp) {
        v.sort();
        if (odd_cnt == 0 || mod != odd_mod) {
            for (int i = 1; i < v.size(); i += 2) {
                ans += v[i] - v[i - 1];
            }
        }
        if (mod == odd_mod) {
            vll pref(v.size()), suff(v.size());
            for (int i = 1; i < v.size() - 1; i += 2) {
                pref[i + 1] = pref[i - 1] + v[i] - v[i - 1];
            }
            for (int j = v.size() - 2; j > 0; j -= 2) {
                suff[j - 1] = suff[j + 1] + v[j + 1] - v[j];
            }
            ll mn = 1e16;
            for (int i = 0; i < v.size(); i += 2) {
                mn = min(mn, pref[i] + suff[i]);
            }
            ans += mn;
        }
    }

    cout << ans;
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