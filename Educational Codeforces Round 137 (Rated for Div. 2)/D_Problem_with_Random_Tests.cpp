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
	string s;
	cin >> s;

	int first_1 = -1, first_0 = n;
	FOR(i, n)
		if(s[i] == '1' && first_1 == -1)
			first_1 = i;
		else if(first_1 != -1 && s[i] == '0'){
			first_0 = i;
			break;
		}

	if(first_1 == -1){ cout << 0; return; }

	int k = first_0 - first_1;
	string ans = s, s2 = s, s_or = s;
	FOR(i, k){
		s2 = '0' + s2.substr(0, n-1);
		FOR(i, n){
			if(s[i] == '1' || s2[i] == '1') s_or[i] = '1';
			else s_or[i] = '0';
		}
		ans = max(ans, s_or);
	}

	bool trailing_zeros = true;
	FOR(i, n){
		if(trailing_zeros && ans[i] == '0') continue;
		cout << ans[i];
		if(ans[i] == '1') trailing_zeros = false;
	}
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}