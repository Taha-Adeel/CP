#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort()			{std::sort(this->begin(), this->end());}
	void sort_dsc() 	{std::sort(this->begin(), this->end(), greater<T>());}
	auto sum() 			{T sum = 0; for(auto& i: *this) sum += i; return sum;}
	auto freqs() 		{map<T, T> freq; for(auto& i: *this) freq[i]++; return freq;}
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
#define ROF(i, n)            	 for(int i = (int)n-1; i >= 0; --i)
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

ll mod_pow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b&1) res = (res*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return res;
}

void solve(){
	ll m;
	cin >> m;
	vll a(m);
	cin >> a;

	auto powers = a.freqs();
	int n = powers.size();
	vll powers_vec; 
	for(auto& [p, k]: powers) 
		powers_vec.push_back(k);

	vll prefix_prod(n+1, 1), suffix_prod(n+1, 1);
	FOR1(i, n) 
		prefix_prod[i] = (prefix_prod[i-1] * (powers_vec[i-1]+1)) % (MOD-1);
	ROF(i, n)
		suffix_prod[i] = (suffix_prod[i+1] * (powers_vec[i]+1)) % (MOD-1);
	
	ll ans = 1, i = 0;
	for(auto& [p, k]: powers){
		ll p_power = ((k * (k+1)) / 2) % (MOD-1);
		p_power *= (prefix_prod[i] * suffix_prod[i+1]) % (MOD-1);
		p_power %= (MOD-1);
		ans = (ans * mod_pow(p, p_power)) % MOD;
		i++;
	}

	cout << ans;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}