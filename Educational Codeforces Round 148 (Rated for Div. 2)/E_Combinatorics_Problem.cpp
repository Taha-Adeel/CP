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
ll mod_pow(ll x, ll y, ll m = MOD) {
	if (y == 0) 
		return 1;
	ll p = mod_pow(x, y/2) % m;
	p = (p * p) % m;

	return (y % 2 == 0) ? p : (x * p) % m;
}

// Using Fermat's Little Theorem (only works for prime MOD)
ll mod_inverse(ll x, ll m = MOD) {
	return mod_pow(x % m, m-2);
}

// x/y (mod MOD)
ll mod_div(ll x, ll y, ll m = MOD){
	if(y == 0) return 1;
	return (x * mod_inverse(y, m)) % m;
}


void solve(){
	ll n, a1, x, y, m, k;
	cin >> n >> a1 >> x >> y >> m >> k;

	ll ans = 0;
	ll y_coeff = 0, nCi = 0, nCi_modm = 0, bi = 0;
	for(ll i = k; i <= n; i++){
		y_coeff = (y_coeff + nCi_modm) % m;
		nCi_modm = mod_div((nCi_modm * i)%m, i-k, m);
		nCi = mod_div((nCi * i)%MOD, i-k);
		bi = (nCi * a1 % MOD + bi * x % m + y_coeff * y % m) % MOD;
		ans = (ans ^ (bi*i));
	}
	cout << ans;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}