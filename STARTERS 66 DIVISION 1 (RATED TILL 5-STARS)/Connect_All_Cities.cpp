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

#define FOR(i, n)                for(long long i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(long long i = 1; i <= (int)n; ++i)
#define ROF(i, n)                for(long long i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	int n;
	cin >> n;
	vi a(n);
	cin >> a;

	if(n == 1){ cout << 0; return;}
	// Store the elements with the same least significant bit together 
	vi lsb[32];
	FOR(i, n){
		int x = a[i];
		if(x == 0){cout << -1; return;}
		int j = 0;
		while(x){
			if(x&1) {lsb[j].push_back(a[i]); break;}
			x >>= 1;
			j++;
		}
	}

	ll ans = 0;
	map<int, int> connected_component;
	FOR(i, 32){
		if(lsb[i].size() == 0) continue;
		for(auto& x: lsb[i]){
			connected_component[i] |= x;
			ans += 1<<i;
		}
		ans -= 1<<i;
	}
	map<int, set<int>> cc;
	map<int, int> cc_or;
	for(auto& [x, y]: connected_component)
		cc[x].insert(x), cc_or[x] = y;
	
	auto get_set = [&](int x){
		for(auto& [i, j]: cc)
			if(j.count(x)) return i;
		return -1;
	};
	FOR(i, 32){
		for(auto& [j, x]: connected_component){
			for(auto& [k, y]: connected_component){
				int xi = get_set(j), yi = get_set(k);
				if(xi == yi) continue;
				if(!(cc_or[xi] & cc_or[yi] & (1<<i))) continue;
				cc[xi].insert(all(cc[yi]));
				cc.erase(yi);
				cc_or[xi] |= cc_or[yi];
				cc_or.erase(yi);
				ans += 1<<i;
			}
		}
	}
	if(cc.size() == 1) cout << ans;
	else cout << -1;
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