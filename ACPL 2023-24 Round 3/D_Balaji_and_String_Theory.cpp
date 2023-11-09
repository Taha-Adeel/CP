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
    string s, t; cin >> s >> t;
    int k; cin >> k;

    string double_s = s+s.substr(0, t.size()-1);
    auto shift = double_s.find(t);
    int cnt = 0, n = s.size();
    while(shift != string::npos) {
        cnt++;
        shift = double_s.find(t, shift+1);
    }

    // dp[i][1] = number of ways to end in a string == t after i steps
    // dp[i][0] = number of ways to end in a string != t after i steps
    V<vll> dp(k+1, vll(2, 0)); 

    dp[0][0] = (s != t);
    dp[0][1] = (s == t);

    FOR1(i, k) {
        dp[i][1] = (dp[i-1][0] * cnt + dp[i-1][1] * (cnt - 1)) % MOD;
        dp[i][0] = (dp[i-1][0] * (n-cnt-1) + dp[i-1][1] * (n-cnt)) % MOD;
    }

    cout << dp[k][1];
}

int main() {
    FAST;
    solve();
    cout << nl;
    
    return 0;
}