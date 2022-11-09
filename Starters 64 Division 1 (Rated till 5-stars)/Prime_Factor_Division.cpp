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
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

// Sieve of Eratosthenes
vll primes;
#define MxN 100000
void sieve() {
	vector<bool> is_prime(MxN+1, true);
	is_prime[0] = is_prime[1] = false;
	for(ll i = 2; i <= MxN; i++){
		if(is_prime[i]){
			primes.pb(i);
			for (ll j = i * i; j <= MxN; j += i)
				is_prime[j] = false;
		}
	}
}

vll prime_factorization(ll n) {
	vll prime_factors;
	for(auto& p: primes){
		if(p*p > n) break;
		if(n%p == 0){
			prime_factors.pb(p);
			while(n%p == 0) n /= p;
		}
	}
	if(n > 1) prime_factors.pb(n);

	return prime_factors;
}

void solve(){
	ll a, b;
	cin >> a >> b;

	ll gcd_ab = gcd(a, b);
	if(gcd_ab < INT_MAX){
		vll prime_factors = prime_factorization(gcd_ab);
		for(auto& p: prime_factors)
			while(b%p == 0) b /= p;
		if(b == 1) pY
		else pN
	}
	else{
		ll b_rem = b/gcd_ab;
		vll prime_factors = prime_factorization(b_rem);
		for(auto& p: prime_factors)
			if(gcd_ab%p) pN
		pY
	}
}

int main(){
	int T;
	cin >> T;
	sieve();
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}