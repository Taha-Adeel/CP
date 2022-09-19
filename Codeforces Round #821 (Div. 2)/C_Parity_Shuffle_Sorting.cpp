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
	int n;
	cin >> n;
	vi a(n);
	cin >> a;

	V<pii> ans;
	if(a[0]%2 == a[n-1]%2){
		for(int i = n-1; i >= 0; i--){
			if(a[i]%2 == a[n-1]%2 && a[i] != a[n-1]){
				ans.pb({i+1, n});
				a[i] = a[n-1];
			}
		}
		for(int i = 1; i < n-1; i++){
			if(a[i]%2 != a[0]%2){
				ans.pb({1, i+1});
				a[i] = a[0];
			}
		}
	}
	else{
		for(int i = 0; i < n; i++){
			if(a[i]%2 != a[0]%2){
				ans.pb({1, i+1});
				a[i] = a[0];
			}
		}
		for(int i = n-1; i >= 0; i--){
			if(a[i]%2 == a[n-1]%2 && a[i] != a[n-1]){
				ans.pb({i+1, n});
				a[i] = a[n-1];
			}
		}
	}

	cout << ans.size() << nl;
	for(auto& p: ans)
		cout << p.F << ' ' << p.S << nl;
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		solve();
	}
	
	return 0;
}