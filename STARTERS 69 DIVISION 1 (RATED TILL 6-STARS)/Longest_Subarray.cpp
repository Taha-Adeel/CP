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
constexpr int BITS = 3;

void solve(){
	int n;
	cin >> n;
	vi a(n);
	cin >> a;

	V<vi> bit_i_count(n+1, vi(BITS, 0));
	FOR(i, n)
		FOR(j, BITS)
			bit_i_count[i+1][j] = bit_i_count[i][j] + ((a[i]>>j)&1);
	
	int ans = -1, cur_or = 0;
	FOR(i, n){
		int l = i, r = n-1;
		int med_or = 0, rem_or = 0, best_m = -1;
		while(l <= r){
			int m = (l+r)/2;
			med_or = rem_or = 0;
			FOR(j, BITS){
				if(bit_i_count[m+1][j] - bit_i_count[i][j])
					med_or |= (1<<j);
				if(bit_i_count[n][j] - bit_i_count[m+1][j])
					rem_or |= (1<<j);
			}
			if(med_or < (cur_or | rem_or))
				l = m + 1;
			else if(med_or > (cur_or | rem_or))
				r = m - 1;
			else
				best_m = m,
				l = m + 1;
		}
		if(best_m != -1)
			ans = max(ans, best_m-i+1);
		cur_or |= a[i];
	}

	cout << ans;
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