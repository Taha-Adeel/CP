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
	vi a(n); cin >> a;

	map<int, ll> alt; alt[0] = a[0]; // Alternating array
	FOR1(i, n-1)
		if((a[i] >= 0) == (alt[alt.size()-1] >= 0))
			alt[alt.size()-1] += a[i];
		else
			alt[alt.size()] = a[i];
	
	if(alt[0] == 0) { cout << 0; return; }

	priority_queue<pll, vector<pll>, greater<pll>> pq;
	FOR(i, alt.size())
		pq.push({abs(alt[i]), i});

	ll ans = 0;
	while(pq.size()){
		auto [x, i] = pq.top(); pq.pop();
		cerr << x << ' ' << i << nl;
		if(alt.count(i)){
			ans += x-ans;
			cerr << ans << nl;
			auto it = alt.find(i);
			ll new_val = 0;
			if(it != alt.begin()) new_val += abs(prev(it)->F)-ans, it = alt.erase(prev(it));
			if(next(it) != alt.end()) new_val += abs(next(it)->F)-ans, alt.erase(next(it));
			if(new_val != 0) alt[i] = new_val+ans, pq.push({new_val+ans, i});
			cerr << new_val << nl;
		}
	}
	cerr << nl;
	cout << ans;
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}