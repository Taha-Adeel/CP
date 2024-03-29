#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()			{std::sort(this->begin(), this->end());}
    void sort_dsc() 	{std::sort(this->begin(), this->end(), greater<T>());}
    auto sum() 			{T sum = 0; for(auto& i: *this) sum += i; return sum;}
    auto freqs() 		{map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
    auto indices()		{int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
    auto prefix_sums() 	{int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)            for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 998244353;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

// x ^ y (mod MOD) (using binary exponentiation)
ll mod_pow(ll x, ll y) {
    if (y == 0) 
        return 1;
    ll p = mod_pow(x, y/2) % MOD;
    p = (p * p) % MOD;

    return (y % 2 == 0) ? p : (x * p) % MOD;
}

// Using Fermat's Little Theorem (only works for prime MOD)
ll mod_inverse(ll x) {
    return mod_pow(x % MOD, MOD-2);
}

// x/y (mod MOD)
ll mod_div(ll x, ll y){
    return (x * mod_inverse(y)) % MOD;
}

void solve(){
    ll n, m; cin >> n >> m;
    string s; cin >> s;

    ll ans = 1;
    FOR1(i, n-2) if(s[i] == '?')
        (ans *= i) %= MOD;
    cout << ans * (s[0] != '?') << nl;
    FOR(_, m){
        int i; char c; cin >> i >> c; i--;

        if(i != 0 && c == '?' && (s[i] == '>' || s[i] == '<')) 
            (ans *= i) %= MOD;
        else if(i != 0 && s[i] == '?' &&  (c == '>' || c == '<'))
            ans = mod_div(ans, i);
        s[i] = c;
        cout << ans * (s[0] != '?') << nl;
    }
}

int main(){
    solve();
    
    return 0;
}