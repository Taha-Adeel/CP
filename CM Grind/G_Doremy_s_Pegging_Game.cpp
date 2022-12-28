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
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

ll mod_pow(ll a, ll b, ll p){
	ll ans = 1;
	while(b){
		if(b&1)
			(ans *= a) %= p;
		(a *= a) %= p;
		b >>= 1;
	}
	return ans;
}

ll mod_div(ll a, ll b, ll p){
	return (a%p * mod_pow(b%p, p-2, p)) % p;
}

ll mod_nCr(ll n, ll r, ll p, vll& factorials){
	return mod_div(factorials[n], factorials[r] * factorials[n-r], p);
}

void solve(){
	ll n, p;
	cin >> n >> p;

	vll factorial(n+1, 1);
	for(int i = 1; i <= n; i++)
		factorial[i] = (factorial[i-1] * i) % p;

	ll t = n/2;
	ll ans = 0;
	for(ll k = t; k <= n-2; k++){
		ll term = 0;
		for(int i = 0; i <= n-2-k; i++)
			(term += mod_nCr(n-2-k, i, p, factorial) * factorial[i + k-1]) %= p;
		(ans += n * (2*t-k) % p * term) %= p;
	}
	if(n%2 == 0)
		(ans += n * factorial[n-2]) %= p;

	cout << ans;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}