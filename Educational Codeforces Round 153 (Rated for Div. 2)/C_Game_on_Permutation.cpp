#include <bits/stdc++.h>

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
	int n; cin >> n;
	vi a(n); cin >> a;

	auto indices = a.indices();
	set<int> s; FOR(i, n) s.insert(i+1);

	V<int> ans(n+1, -1);
	ans[0] = 0;
	ans[a[0]] = 0;
	s.erase(a[0]);
	FOR1(i, n-1){
		ans[a[i]] = 0;
		s.erase(a[i]);
		if(a[i] > a[i-1]){
			ans[a[i]] = 1;
			for(auto it = s.begin(); it != s.end();){
				if(*it < a[i]) {ans[*it] = 0; it = s.erase(it);}
				else it++;
			}
			break;
		}
	}

	FOR(i, n){
		if(ans[a[i]] != -1) continue;
		ans[a[i]] = 1;
		for(auto it = s.begin(); it != s.end();){
			if(*it < a[i]) {ans[*it] = 0; it = s.erase(it);}
			else it++;
		}
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