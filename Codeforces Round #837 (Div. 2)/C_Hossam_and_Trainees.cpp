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
vll primes;
void seive(ll n){
	vll is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for(ll i=2; i<=n; i++){
		if(is_prime[i] && i*i <= n){
			for(ll j=i*i; j<=n; j+=i)
				is_prime[j] = false;
		}
	}
	for(ll i=2; i<=n; i++)
		if(is_prime[i])
			primes.push_back(i);
}

void solve(){
	int n;
	cin >> n;
	vll a(n);
	cin >> a;

	for(auto& p: primes){
		int one_count = 0, p_count = 0;
		for(auto& i: a){
			if(i%p == 0){
				p_count++;
				if(p_count > 1) pY
				while(i%p == 0)
					i /= p;
			}
			if(i == 1) one_count++;
		}
		if(one_count == n) break;
	}
	auto freqs = a.freqs();
	for(auto& [v, f]: freqs)
		if(f > 1 && v != 1) pY

	pN
}

int main(){
	FAST;
	seive(4*(1e4));
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}