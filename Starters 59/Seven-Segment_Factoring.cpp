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

bool isDivisible(string a, int b){
	return true;
}

void solve(){
	string n;
	cin >> n;
	int A, B, C, D, E, F, G;
	cin >> A >> B >> C >> D >> E >> F >> G;

	int c1 = B + C, c2 = A + B + G + E + D, c5 = A + F + G + C + D, c6 = A + F + G + C + D + E;
	int ans = c1;
	if((n.back() - '0')%5 == 0) ans = min(ans, c5); 
	if((n.back() - '0')%2 == 0){
		ans = min(ans, c2);
		if((n.back() - '0')%3 == 0)
			ans = min(ans, c6);
		
		if(n.size() >= 18) {
			cout << ans;
			return;
		}
		ll nn = stoll(n);
		map<int, int> nums;
		nums[56] = c5 + c6; 
		nums[66] = c6 + c6; 
		nums[556] = 2*c5 + c6; 
		nums[566] = c5 + 2*c6; 
		nums[656] = c5 + 2*c6; 
		nums[666] = 0*c5 + 3*c6; 
		nums[5556] = 3*c5 + 1*c6;
		nums[5566] = 2*c5 + 2*c6;
		nums[5656] = 2*c5 + 2*c6;
		nums[5666] = 1*c5 + 3*c6;
		nums[6556] = 2*c5 + 2*c6;
		nums[6566] = 1*c5 + 3*c6;
		nums[6656] = 1*c5 + 3*c6;

		for(auto& p: nums)
			if(nn % p.F == 0) ans  = min(ans, p.S);
	}

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