#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()            {std::sort(this->begin(), this->end());}
    void sort_dsc()     {std::sort(this->begin(), this->end(), greater<T>());}
    auto sum()             {T sum = 0; for(auto& i: *this) sum += i; return sum;}
    auto freqs()         {vector<int> freq(this->size()+1, 0); for(auto& i: *this) freq[i]++; return freq;}
    auto indices()        {int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
    auto prefix_sums()     {int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)                for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()

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

void solve(){
    ll n; cin >> n;
    vll a(n); cin >> a;

    auto cnt = a.freqs();

    vll dp(n+1, 0); // dp[g] = number of pairs (i, j) such that gcd(a[i], a[j]) = g
    for(int g = n; g > 0; g--){
        ll s = 0;
        for(int j = g; j <= n; j += g)
            s += cnt[j];

        dp[g] = ((s * (s-1)) / 2);
        for(int j = 2*g; j <= n; j += g)
            dp[g] -= dp[j];
    }

    FOR1(g, n){
        if(cnt[g] == 0 || dp[g] == 0) continue;
        for(int j = g; j <= n; j += g)
            dp[j] = 0;
    }

    cout << dp.sum();
}

int main(){
    FAST;
    int T;
    cin >> T;
    FOR(t, T){
        solve();
        cout << nl;
    }
    
    return 0;
}