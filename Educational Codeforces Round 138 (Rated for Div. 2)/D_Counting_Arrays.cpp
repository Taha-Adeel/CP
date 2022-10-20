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

#define MxN 300300

// x ^ y (mod MOD) (using binary exponentiation)
ll mod_pow(ll x, ll y) {
	x %= MOD;
	if (y == 0) 
		return 1;
	ll p = mod_pow(x, y/2) % MOD;
	p = (p * p) % MOD;

	return (y % 2 == 0) ? p : (x * p) % MOD;
}

vll prime;
void seive_of_eratosthenes(){
	vector<bool> is_prime(MxN+1, true);
	is_prime[0] = is_prime[1] = false;
	for(ll i = 2; i <= MxN; i++){
		if(is_prime[i]){
			prime.pb(i);
			for (ll j = i * i; j <= MxN; j += i)
				is_prime[j] = false;
		}
	}
}

void solve(){
	ll n, m;
	cin >> n >> m;

	ll ans = 0;
	ll cur_prime_i = 0;
	vll a(n); a[0] = 1;
	FOR(i, n){
		if(i && a[i-1] > m) a[i] = 2*m;
		else if(i+1 >= prime[cur_prime_i] && i){
			a[i] = a[i-1] * prime[cur_prime_i];
			cur_prime_i++;
		}
		else if(i)
			a[i] = a[i-1];
	}
	ll non_ambg = 1;
	FOR1(i, n){
		ll ansi = mod_pow(m, i);
		non_ambg = (non_ambg * ((m/a[i-1])%MOD)) % MOD;
		
		ansi = ((ansi - non_ambg)%MOD + MOD)%MOD;
		ans += ansi; ans %= MOD;
	}

	cout << ans;
}

int main(){
	seive_of_eratosthenes();
	solve();
	cout << nl;
	
	return 0;
}