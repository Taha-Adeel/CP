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

int MSBPosition(long long int N)
{
    int msb_p = -1;
    while (N) {
        N = N >> 1;
        msb_p++;
    }
    return msb_p;
}
 
// Returns the Bitwise OR of all
// integers between L and R
long long int findBitwiseOR(long long int L,
                            long long int R)
{
    long long int res = 0;
 
    // Find the MSB position in L
    int msb_p1 = MSBPosition(L);
 
    // Find the MSB position in R
    int msb_p2 = MSBPosition(R);
 
    while (msb_p1 == msb_p2) {
        long long int res_val = (1 << msb_p1);
 
        // Add this value until msb_p1 and
        // msb_p2 are same;
        res += res_val;
 
        L -= res_val;
        R -= res_val;
 
        // Calculate msb_p1 and msb_p2
        msb_p1 = MSBPosition(L);
        msb_p2 = MSBPosition(R);
    }
    // Find the max of msb_p1 and msb_p2
    msb_p1 = max(msb_p1, msb_p2);
 
    // Set all the bits from msb_p1 upto
    // 0th bit in the result
    for (int i = msb_p1; i >= 0; i--) {
        long long int res_val = (1 << i);
        res += res_val;
    }
    return res;
}

void solve() {
    ll n, m; cin >> n >> m;

    if (m == 0) {
        cout << n;
        return;
    }

    cout << findBitwiseOR(max(0LL, n - m), n + m);
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