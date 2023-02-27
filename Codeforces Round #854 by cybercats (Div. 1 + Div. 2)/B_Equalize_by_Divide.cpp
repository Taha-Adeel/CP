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

int ceil(ll a, ll b){
	return (a+b-1)/b;
}

void solve(){
	int n;
	cin >> n;
	V<pii> a(n);
	FOR(i, n) cin >> a[i].F, a[i].S = i+1;

	a.sort();
	if(a[0].F == a[n-1].F){
		cout << 0 << nl;
		return;
	}
	if(a[0].F == 1){
		cout << -1 << nl;
		return;
	}

	V<pii> ans;
	map<int, int> freqs;
	while(freqs.size() != 1){
		a.sort();
		for(int i = 1; i < n; i++){
			while(a[0].F != a[i].F){
				while(a[i].F > a[0].F)
					ans.pb({a[i].S, a[0].S}), a[i].F = ceil(a[i].F, a[0].F);
				while(a[0].F > a[i].F)
					ans.pb({a[0].S, a[i].S}), a[0].F = ceil(a[0].F, a[i].F);
			}
		}
		freqs.clear();
		FOR(i, n) freqs[a[i].F]++;	
	}

	cout << ans.size() << nl;
	for(auto& i: ans)
		cout << i.F << ' ' << i.S << nl;
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		solve();
	}
	
	return 0;
}