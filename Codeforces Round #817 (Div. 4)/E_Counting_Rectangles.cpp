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

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
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
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	int n, q;
	cin >> n >> q;
	V<pll> rects(n);
	FOR(i, n) 
		cin >> rects[i].F >> rects[i].S;

	rects.sort();
	map<ll, multiset<ll>> rcts;
	for(auto& rr: rects)
		rcts[rr.F].insert(rr.S);

	FOR(i, q){
		ll hs, ws, hb, wb;
		cin >> hs >> ws >> hb >> wb;

		ll ans = 0;
		auto lb = rcts.lb(hs+1), ub = rcts.lb(hb);
		auto cb = lb;
		while(cb != ub){
			auto lbw = (cb->S).lb(ws+1), ubw = (cb->S).lb(wb);
			auto cbw = lbw;
			while(cbw != ubw)
				ans += (cb->F) * (*cbw), cbw++;
			cb++;
		}

		cout << ans << nl;
	}
}

int main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve();
	}
	
	return 0;
}