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
constexpr int MOD = 998244353;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

// Precompute factorials to be used for nCr calculations
#define MxN 1000001
ll factorial[MxN];
void calc_factorials(){
	factorial[0] = 1;
	for(ll i = 1; i < MxN; i++)
		factorial[i] = (factorial[i - 1] * i) % MOD;
}

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

// nCr (mod MOD)
ll mod_nCr(ll n, ll r){
	return mod_div(factorial[n], factorial[r] * factorial[n-r]);
}

void solve(){
	string N;
	cin >> N;
	int K;
	cin >> K;

	if(K == 0){ cout << N.size(); return; }

	ll pos = 0;
	vll a;
	ROF(i, N.size()){
		FOR(j, N[i] - '0'){
			pos += (N.size() - i);
			a.pb(pos);
		}
	}
	K--;

	ll ans = 0;
	ll binomial_coeff = 1;
	FOR(i, a.size()){
		ans += a[a.size() - (i+1)] * binomial_coeff;
		ans %= MOD;
		binomial_coeff = binomial_coeff * mod_div(K+i, i+1) % MOD;
	}

	cout << ans;
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