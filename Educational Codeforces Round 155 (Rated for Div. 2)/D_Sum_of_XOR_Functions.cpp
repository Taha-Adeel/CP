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
constexpr int MOD = 998244353;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	int n; cin >> n;
	vll a(n); cin >> a;

	ll ans = 0;
	FOR(i, 33){
		ll mask = 1LL << i;
		ll zero_cnt = 0, one_cnt = 0;
		ll zero_sum = 0, one_sum = 0;
		ll prev_one_cnt = 0;
		ll ans_i = 0;

		FOR(j, n){
			prev_one_cnt += ((a[j] & mask) != 0);
			if(prev_one_cnt % 2 == 0) zero_sum += j + 1, zero_cnt++;
			else one_sum += j + 1, one_cnt++;
		}

		prev_one_cnt = 0;
		FOR(j, n){
			if(prev_one_cnt % 2 == 0) ans_i = (ans_i + one_sum) % MOD;
			else ans_i = (ans_i + zero_sum) % MOD;
			prev_one_cnt += ((a[j] & mask) != 0);

			zero_sum -= zero_cnt;
			one_sum -= one_cnt;

			if(prev_one_cnt % 2 == 0) zero_cnt--;
			else one_cnt--;
		}

		ans = (ans + ans_i * mask) % MOD;
	}

	cout << ans;
}

int main(){
	int T = 1;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}