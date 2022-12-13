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
vi primes;
void seive(int n){
	vi isPrime(n+1, 1);
	isPrime[0] = isPrime[1] = 0;
	for(int i=2; i*i<=n; i++){
		if(isPrime[i]){
			for(int j=i*i; j<=n; j+=i)
				isPrime[j] = 0;
		}
	}
	FOR1(i, n) if(isPrime[i]) primes.push_back(i);
}

vi factors(int n){
	vi f;
	for(int i=0; i<primes.size() && primes[i]*primes[i]<=n; i++){
		if(n%primes[i] == 0){
			f.push_back(primes[i]);
			while(n%primes[i] == 0) n /= primes[i];
		}
	}
	if(n > 1) f.push_back(n);
	return f;
}

void solve(){
	int x, y;
	cin >> x >> y;

	if(gcd(x, y) != 1) { cout << 0; return; }
	if(abs(x-y) == 1) { cout << -1; return; }
	int ans = INT_MAX;
	for(auto& p: factors(abs(x-y)))
		ans = min(ans, p - (x%p));

	cout << ans;
}

int main(){
	FAST;
	seive(sqrt(1e7) + 5);
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}