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
    string a, b; cin >> a >> b;
    
    V<vi> dp(n, vi(3, 0));
    dp[1][1]=((a[0]=='A')+(b[0]=='A')+(a[1]=='A'))>=2;
    dp[1][2]=((a[0]=='A')+(b[0]=='A')+(b[1]=='A'))>=2;
    dp[2][0]=max({dp[1][1]+(((a[2]=='A')+(b[1]=='A')+(b[2]=='A'))>=2),dp[1][2]+(((a[2]=='A')+(b[2]=='A')+(a[1]=='A'))>=2),(((a[2]=='A')+(a[1]=='A')+(a[0]=='A'))>=2)+(((b[2]=='A')+(b[1]=='A')+(b[0]=='A'))>=2)});

    for(int i = 3; i < n; i++) {
        dp[i][0]=max({dp[i-1][1]+(((b[i]=='A')+(a[i]=='A')+(b[i-1]=='A'))>=2),dp[i-1][2]+(((a[i]=='A')+(b[i]=='A')+(a[i-1]=='A'))>=2),dp[i-3][0]+ (((b[i-2]=='A')+(b[i-1]=='A')+(b[i]=='A'))>=2)+(((a[i-2]=='A')+(a[i-1]=='A')+(a[i]=='A'))>=2)});
        dp[i][1]=max({dp[i-2][0]+(((a[i]=='A')+(a[i-1]=='A')+(b[i-1]=='A'))>=2),dp[i-3][1]+(((b[i-2]=='A')+(b[i-1]=='A')+(b[i-3]=='A'))>=2)+(((a[i-2]=='A')+(a[i-1]=='A')+(a[i]=='A'))>=2)});
        dp[i][2]=max({dp[i-2][0]+(((b[i]=='A')+(b[i-1]=='A')+(a[i-1]=='A'))>=2),dp[i-3][2]+(((a[i-2]=='A')+(a[i-1]=='A')+(a[i-3]=='A'))>=2)+(((b[i-2]=='A')+(b[i-1]=='A')+(b[i]=='A'))>=2)});
    }

    cout << dp[n-1][0] << nl;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}