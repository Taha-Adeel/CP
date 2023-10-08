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

// Number of ways to go from mask_i to mask_f in the next layer
ll cnt(ll mask_i, ll mask_f, ll n){
	int ans = 1;
	FOR(i, n){
		if((mask_i>>i & 1) && (mask_f>>i & 1)){
			ans = 0; break;
		}
		if(!(mask_i>>i & 1) && !(mask_f>>i & 1)){
			if(i+1 < n && !(mask_i>>(i+1) & 1) && !(mask_f>>(i+1) & 1)){
				i++; continue;
			}
			ans = 0; break;
		}
	}
	return ans;
}

void solve(){
	ll n, m; cin >> n >> m;

	V<vll> dp(m+1, vll(1<<n, 0)); // dp[l][mask] = # of ways to fill the lth layer as mask 
	dp[0][0] = 1;

	FOR1(layer, m){
		FOR(nmask, 1<<n){
			FOR(mask, 1<<n){
				int c = cnt(mask, nmask, n);
				if(c > 1) cerr << "ERROR: " << mask << ' ' << nmask << nl;
				dp[layer][nmask] += dp[layer-1][mask] * c;
				dp[layer][nmask] %= MOD;
			}
		}
	}

	cout << dp[m][0];
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}