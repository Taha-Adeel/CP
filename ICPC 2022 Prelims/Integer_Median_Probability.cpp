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
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
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
constexpr int MOD = 998244353;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

ll pow(int a, int b){
	if(b == 0) return 1;
	return a * pow(a, b-1);
}

string to_base_m(int a, int b, int n){
	string ans = "";
	while(a){
		ans += to_string(a%b);
		a /= b;
	}
	while(ans.size() < (unsigned ll)n) ans += "0";
	reverse(all(ans));
	return ans;
}

pair<int, int> solve(int n, int m) {
	vll a(n);
	ll good = 0, total = pow(m, n);
	// n = 8, m = 6
	FOR(i, total){
		string perm = to_base_m(i, m, n);
		FOR(i, n)
			a[i] = perm[i] - '0' + 1;
		a.sort();
		if(n % 2) good++;
		else if((a[n/2 - 1] + a[n/2]) % 2 == 0) good++;
	}

	return {good, total};
	// cout << good << '/' << total;
}

void solve() {
	for (int m = 1, n = 6; m <= 10; m++) {
		auto x = solve(n, m);
		cout << x.F << ' ' << x.S << '\n';
	}
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}