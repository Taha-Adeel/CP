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
#define FOR1(i, n)               for(int i = 1; i < (int)n; ++i)
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

// Seive of Eratosthenes
vi primes;
void seive(int n){
	vi is_prime(n+1, 1);
	is_prime[0] = is_prime[1] = 0;
	for(int i=2; i<=n; i++){
		if(is_prime[i]){
			primes.push_back(i);
			for(int j=i*i; j<=n; j+=i)
				is_prime[j] = 0;
		}
	}
}

V<pii> prime_factors(int n){
	V<pii> factors;
	for(auto& p: primes){
		if(p*p > n) break;
		int count = 0;
		while(n%p == 0)
			count++,
			n /= p;
		if(count) factors.pb({count, p});
	}
	if(n > 1) factors.push_back({1, n});
	factors.sort();
	return factors;
}

void solve(){
	int n;
	cin >> n;

	auto factors = prime_factors(n);
	int cur_a = 1;
	for(auto& [k, p]: factors)
		cur_a *= p;
	int ans = factors[0].F * cur_a;
	FOR1(i, factors.size()){
		cur_a /= factors[i-1].S;
		ans += cur_a * (factors[i].F - factors[i-1].F);
	}

	cout << ans;
}

int main(){
	FAST;
	seive(sqrt(1e9)+5);
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}