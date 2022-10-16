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

#define MxN 100000
vll primes;

void seive_of_eratosthenes(){
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

void get_divisors(ll cur_i, ll cur_div, V<pii>& powers, vll& divisors){
	if(cur_i == powers.size()){
		divisors.pb(cur_div);
		return;
	}
	FOR(i, powers[cur_i].S+1){
		get_divisors(cur_i+1, cur_div, powers, divisors);
		cur_div *= powers[cur_i].F;
	}
}

map<int, int> get_powers(ll a){
	map<int, int> powers;
	for(auto& p: primes){
		int pow_p = 0;
		while(a%p == 0){
			a /= p;
			pow_p++;
		}
		if(pow_p) powers[p] = pow_p;
		if(a == 1) break;
	}
	if(a != 1) powers[a] = 1;
	return powers;
}

void solve(){
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll ab = a*b;

	auto powers_a = get_powers(a), powers_b = get_powers(b);
	V<pii> powers_ab;
	for(auto& p: powers_a){
		powers_ab.pb({p.F, p.S + powers_b[p.F]});
		powers_b.erase(p.F);
	}
	for(auto& p: powers_b){
		powers_ab.pb({p.F, p.S});
	}

	vll divisors;
	get_divisors(0, 1, powers_ab, divisors);
	for(auto& x: divisors){
		ll y = ab/x;
		ll xa = a/x + 1, ya = b/y + 1;
		x *= xa; y *= ya;
		if(x > a && x <= c && y > b && y <= d){
			cout << x << ' ' << y;
			return;
		}
	}
	cout << -1 << ' ' << -1;
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