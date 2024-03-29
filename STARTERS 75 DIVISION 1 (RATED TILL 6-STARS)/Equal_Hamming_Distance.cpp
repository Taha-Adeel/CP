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

ll mod_pow(ll a, ll b){
	if(b == 0) return 1;
	ll ans = mod_pow(a%MOD, b/2);
	return (ans*ans)%MOD * (b%2 ? a : 1)%MOD;
}

ll mod_div(ll a, ll b){
	return (a*mod_pow(b, MOD-2))%MOD;
}

#define MAXN 200005
vll fact(MAXN, 1);
ll mod_nCr(ll n, ll r){
	return (fact[n] * mod_pow(fact[r], MOD-2) % MOD * mod_pow(fact[n-r], MOD-2))%MOD;
}


void solve(){
	ll n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	int dif_count = 0;
	FOR(i, n) if(a[i] != b[i]) 
		dif_count++;
	
	if(dif_count%2) cout << 0;
	else cout << mod_nCr(dif_count, dif_count/2) * mod_pow(2, n - dif_count) % MOD;
}

int main(){
	for(int i = 2; i < MAXN; i++)
		fact[i] = (fact[i-1]*i)%MOD;

	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}