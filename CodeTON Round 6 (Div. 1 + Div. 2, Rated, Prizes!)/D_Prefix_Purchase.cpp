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

void solve(){
	int n; cin >> n;
	vi a(n, 0), c(n); cin >> c;
	int k;  cin >> k;

	vi min_after_idx(n, -1);
	min_after_idx[n-1] = n-1;
	ROF(i, n-1){
		if(c[i] < c[min_after_idx[i+1]]) min_after_idx[i] = i;
		else min_after_idx[i] = min_after_idx[i+1];
	}

	int prev_min = 0, prev_i = -1, prev_val = INT_MAX;
	int cur_min = c[min_after_idx[0]], cur_i = min_after_idx[0], rem = k;
	while(true){
		for(int i = prev_i+1; i <= cur_i; i++){
			a[i] = min(rem / (cur_min - prev_min), prev_val);
		} 
		rem -= a[cur_i] * (cur_min - prev_min);

		if(cur_i == n-1 || rem <= 0) break;
		prev_min = cur_min;
		prev_i = cur_i;
		prev_val = a[cur_i];
		cur_min = c[min_after_idx[cur_i+1]];
		cur_i = min_after_idx[cur_i+1];
	}

	std::cout << a;
}

int main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		std::cout << nl;
	}
	
	return 0;
}