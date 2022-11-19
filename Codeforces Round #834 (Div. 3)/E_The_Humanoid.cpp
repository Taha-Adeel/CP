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
	ll n, h;
	cin >> n >> h;
	vll a(n);
	cin >> a;

	a.sort();
	ll h1 = h;
	ll ans1 = 0;
	vi serums1 = {3, 2, 2};
	FOR(i, n){
		if(a[i] < h1){
			h1 += a[i]/2;
			ans1++;
		}
		else if(serums1.size()){
			h1 *= serums1.back();
			serums1.pop_back();
			i--;
		}
	}
	ll h2 = h;
	ll ans2 = 0;
	vi serums2 = {2, 3, 2};
	FOR(i, n){
		if(a[i] < h2){
			h2 += a[i]/2;
			ans2++;
		}
		else if(serums2.size()){
			h2 *= serums2.back();
			serums2.pop_back();
			i--;
		}
	}

	ll h3 = h;
	ll ans3 = 0;
	vi serums3 = {2, 2, 3};
	FOR(i, n){
		if(a[i] < h3){
			h3 += a[i]/2;
			ans3++;
		}
		else if(serums3.size()){
			h3 *= serums3.back();
			serums3.pop_back();
			i--;
		}
	}

	cout << max({ans1, ans2, ans3});
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