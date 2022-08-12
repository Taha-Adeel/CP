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

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()

#define F  first
#define S  second
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

// x ^ y (mod MOD) (using binary exponentiation)
ll mod_pow(ll x, ll y, ll mod = MOD) {
	if (y == 0) 
		return 1;
	ll p = mod_pow(x, y/2) % mod;
	p = (p * p) % mod;

	return (y % 2 == 0) ? p : (x * p) % mod;
}

// Returns the gcd and finds the value of x, y s.t. ax + by = gcd(a, b). And x = mod_inverse of a (mod b).
ll extended_gcd(ll a, ll b, ll& x, ll& y){
	if(b == 0) return x = 1, y = 0, a;
	ll gcd = extended_gcd(b, a%b, y, x);
	y -= (a/b) * x;
	return gcd;
}

ll mod_inverse(ll n, ll mod = MOD) {
	ll x, y;
	extended_gcd(n, mod, x, y);
	return (x%mod + mod)%mod;
}

// x/y (mod MOD)
ll mod_div(ll x, ll y, ll mod = MOD){
	x = (x%mod + mod)%mod;
	return (x * mod_inverse(y, mod)) % mod;
}

void solve(){
	ll n;
	cin >> n;
	vll x(n), k(n);
	FOR(i, n)
		cin >> x[i] >> k[i];

	ll div_num = 1, div_sum = 1, div_prod = 1;
	FOR(i, n){
		div_num *= k[i] + 1; div_num %= MOD;
		div_sum *= mod_div(mod_pow(x[i], k[i] + 1) - 1, x[i] - 1); div_sum %= MOD;
	}
	vll prod_l(n+1, 1), prod_r(n+1, 1);
	FOR1(i, n)
		prod_l[i] = (prod_l[i-1] * (k[i-1]+1))%(MOD-1);
	FOR_REV(i, n)
		prod_r[i] = (prod_r[i+1] * (k[i] + 1))%(MOD-1);
	
	FOR(i, n){
		div_prod *= mod_pow(x[i], ((((k[i] * (k[i] + 1))/2)%(MOD-1)) * ((prod_l[i]*prod_r[i+1])%(MOD-1)))%(MOD-1)); div_prod %= MOD;
	}

	cout << div_num << ' ' << div_sum << ' ' << div_prod;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}