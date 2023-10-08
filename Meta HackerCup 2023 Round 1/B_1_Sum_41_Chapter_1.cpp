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

V<vi> perms;
map<ll, vi> mp;

void decompose(int n, vi prefix = {}) {
	if (n == 0) {
		perms.push_back(prefix);
	}
	else {
		int max = prefix.size() ? std::min(prefix.back(), n) : n;
		prefix.push_back(1);
		for (int i = 1; i <= max; i++) {
			prefix.back() = i;
			decompose(n - i, prefix);
		}
	}
}

void solve(){
	int n; cin >> n;

	if(mp.count(n) == 0) cout << -1;
	else cout << mp[n].size() << ' ' << mp[n];
}

int main(){
	FAST;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	decompose(41);

	for(auto& i: perms){
		ll prod = 1;
		for(auto& j: i)
			prod *= j;
		if(mp.count(prod) == 0)
			mp[prod] = i;
		else if(i.size() < mp[prod].size())
			mp[prod] = i;
	}

	int T;
	cin >> T;
	FOR(t, T){
		cout << "Case #" << t+1 << ": ";
		solve();
		cout << nl;
	}
	
	return 0;
}