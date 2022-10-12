#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1000000007;
#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort()			{std::sort(this->begin(), this->end());}
	void sort_dsc() 	{std::sort(this->begin(), this->end(), greater<T>());}
	auto sum() 			{T sum = 0; for(auto& i: *this) sum = (sum+i)%MOD; return sum;}
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
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

#define MxN 1000000
vi primes;

// x ^ y (mod MOD) (using binary exponentiation)
ll mod_pow(ll x, ll y) {
	if (y == 0) 
		return 1;
	ll p = mod_pow(x, y/2) % MOD;
	p = (p * p) % MOD;

	return (y % 2 == 0) ? p : (x * p) % MOD;
}

void seive_of_eratosthenes(){
	vector<bool> is_prime(MxN+1, true);
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i <= MxN; i++){
		if(is_prime[i] && (long long)i * i <= MxN){
			primes.pb(i);
			for (int j = i * i; j <= MxN; j += i)
				is_prime[j] = false;
		}
	}
}

void solve(){
	int n;
	cin >> n;
	vll a(n);
	cin >> a;

	map<int, vi> powers;
	for(auto& p: primes){
		FOR(i, n){
			int pow_p = 0;
			while(a[i]%p == 0){
				a[i] /= p;
				pow_p++;
			}
			if(pow_p) powers[p].pb(pow_p);
		}
	}
	FOR(i, n)
		if(a[i] != 1) powers[a[i]].pb(1);
	for(auto& v: powers)
		v.S.sort();

	ll ans = 0; 
	FOR(i, n){
		ll term = 1;
		for(auto it = powers.begin(); it != powers.end();){
			term = (term * mod_pow(it->F, it->S.back()))%MOD;
			it->S.pop_back();
			if(it->S.empty())
				it = powers.erase(it);
			else it++;
		}
		ans = (ans + term)%MOD;
	}

	cout << ans;
}

int main(){
	FAST;
	seive_of_eratosthenes();
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}