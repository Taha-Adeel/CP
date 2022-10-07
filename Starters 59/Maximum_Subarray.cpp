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
	int n; cin >> n;
	vi a(n); cin >> a;
	int m; cin >> m;
	vi b(m); cin >> b;

	ll pos_sum = 0;
	FOR(i, m)
		if(b[i] > 0) pos_sum += b[i];
	
	vll sum1(n+1);
	sum1[0] = pos_sum;
	FOR1(i, n)
		sum1[i] = max(sum1[i-1]+a[i-1], 0LL+a[i-1]);
	ll ans1 = *max_element(sum1.begin(), sum1.end());

	a.pb(pos_sum);
	vll sum2(n+1);
	sum2[0] = a[0];
	FOR1(i, n)
		sum2[i] = max(sum2[i-1]+a[i], 0LL+a[i]);
	ll ans2 = *max_element(sum2.begin(), sum2.end());

	cout << max(ans1, ans2);
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