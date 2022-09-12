#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort()			{std::sort(this->begin(), this->end());}
	void sort_dsc() 	{std::sort(this->begin(), this->end(), greater<T>());}
	auto sum() 			{T sum = 0; for(auto& i: *this) sum += i; return sum;}
	auto freqs() 		{map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	auto indices()		{int n=this->size(); map<T, set<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].insert(i); return ii;}
	auto prefix_sums() 	{int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i < (int)n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using PI = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	string s;
	cin >> s;

	int n = s.size(), min_cost = abs(s[n-1]-s[0]);
	V<pair<char, int>> ss(n);
	FOR(i, n) ss[i] = {s[i], i};
	ss.sort();
	if(s[n-1] < s[0]) reverse(all(ss));
	vi ans; ans.pb(1);
	FOR(i, n)
		if(ss[i].F <= max(s[0], s[n-1]) && ss[i].F >= min(s[0], s[n-1]))
			if(ss[i].S != 0 && ss[i].S != n-1)
				ans.pb(ss[i].S + 1);
	ans.pb(n);

	cout << min_cost << ' ' << ans.size() << nl;
	cout << ans << nl;
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		// cout << nl;
	}
	
	return 0;
}