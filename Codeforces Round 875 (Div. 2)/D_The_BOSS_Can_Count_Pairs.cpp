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
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

// Seive of Eratosthenes
#define MAXN 400010
vi primes;
void seive(){
	int N = sqrt(MAXN) + 1;
	vi is_prime(N+1, 1);
	is_prime[0] = is_prime[1] = 0;
	for(int i=2; i*i<=N; i++) if(is_prime[i])
		for(int j=i*i; j<=N; j+=i)
			is_prime[j] = 0;
	FOR(i, N+1) if(is_prime[i]) primes.pb(i);
}

V<pii> getPrimeFactors(int n){
	V<pii> factors;
	for(auto& p: primes){
		if(p*p > n) break;
		if(n%p == 0){
			int cnt = 0;
			while(n%p == 0){
				n /= p;
				cnt++;
			}
			factors.pb({p, cnt});
		}
	}
	if(n > 1) factors.pb({n, 1});
	return factors;
}

void setDivisors(vi& divisors, int i, int n, const V<pii>& factors){
	if(i == factors.size()){
		divisors.pb(n);
		return;
	}
	int p = factors[i].F, cnt = factors[i].S;
	FOR1(j, cnt){
		setDivisors(divisors, i+1, n, factors);
		n *= p;
	}
	setDivisors(divisors, i+1, n, factors);
}

vi divisors_dp[MAXN];
vi getDivisors(int n){
	if(divisors_dp[n].size()) return divisors_dp[n];
	auto factors = getPrimeFactors(n);
	vi divisors;
	setDivisors(divisors, 0, 1, factors);
	divisors.sort();
	divisors_dp[n] = divisors;
	return divisors;
}

void solve(){
	int n; cin >> n;
	V<pll> c(n); 
	FOR(i, n) cin >> c[i].F;
	FOR(i, n) cin >> c[i].S;

	c.sort();
	// FOR(i, n) cerr << c[i].F << ' '; cerr << nl;
	// FOR(i, n) cerr << c[i].S << ' '; cerr << nl;


	double ans = 0;
	FOR1(x, 2*n){
		vi divisors = getDivisors(x);
		FOR(di, (divisors.size()+1)/2){
			int a1 = divisors[di], a2 = divisors[divisors.size()-1-di];
			int a1_l = lb(all(c), pll(a1, 0)) - c.begin(), a1_r = ub(all(c), pll(a1, MOD)) - c.begin();
			int a2_l = lb(all(c), pll(a2, 0)) - c.begin(), a2_r = ub(all(c), pll(a2, MOD)) - c.begin();
			
			for(int i=a1_l; i<a1_r; i++){
				int b1 = c[i].S;
				int b2 = x - b1;
				int b_l = lb(a2_l+ c.begin(), a2_r+c.begin(), pll(a2, b2)) - c.begin(), b_r = ub(a2_l+ c.begin(), a2_r+c.begin(), pll(a2, b2)) - c.begin();
				int cnt = b_r - b_l;
				if(i >= b_l && i < b_r) cnt--;
				// cerr << x << ' ' << a1 << ' ' << a2 << ' ' << b1 << ' ' << b2 << ' ' << i << ' ' << b_l << ' ' << b_r << ' ' << cnt << nl;
				ans += cnt/((a1==a2)?2.0:1.0);
			}
		}
	}
	// cerr << nl;
	cout << int(ans);
}

int main(){
	FAST;
	seive();
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}