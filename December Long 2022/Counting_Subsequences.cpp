#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort()			{std::sort(this->begin(), this->end());}
	void sort_dsc() 	{std::sort(this->begin(), this->end(), greater<T>());}
	auto sum() 			{T sum = 0; for(auto& i: *this) sum += i; return sum;}
	auto freqs() 		{map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	auto indices()		{int n=this->size(); map<T, int> ii; for(int i=0; i<n; i++) ii[(*this)[i]] = i; return ii;}
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

void solve(){
	int n;
	cin >> n;
	vll A(n);
	cin >> A;

	vll dp(n+1, 0);
	for(int i = n-1; i >= 0; i--){
		dp[A[i]] = 1;
		// int set_bits = __builtin_popcount(A[i]);
		// for(int perm = 1; perm < (1<<set_bits)-1; perm++){
		// 	int mask_i = 1, mask_n = 1, x = 0;
		// 	for(int j = 0; j < set_bits; j++){
		// 		while((mask_n & A[i]) == 0) mask_n <<= 1;
		// 		if(mask_i & perm) 
		// 			x |= mask_n;
		// 		mask_n <<= 1;
		// 		mask_i <<= 1;
		// 	}
		// 	dp[A[i]] += dp[x],
		// 	dp[A[i]] %= MOD;
		// }
		int mask = (A[i] - 1) & A[i];
		while(mask){
			dp[A[i]] += dp[mask];
			dp[A[i]] %= MOD;
			mask = (mask - 1) & A[i];
		}
	}

	cout << dp.sum()%MOD;
}

int main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}