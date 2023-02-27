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

void solve(){
	string s;
	cin >> s;

	int n = s.size();
	map<char, int> freq;
	for(auto& c: s) freq[c]++;
	string ans = "";
	char c;
	for(c = 'a'; c <= 'z'; c++){
		FOR(i, freq[c]/2) ans += c;
		if(freq[c]%2) break;
	}
	string suffix = ans;
	reverse(all(suffix));
	int rem_chars = 0;
	char other_char = 'A';
	for(char cc = c+1; cc <= 'z'; cc++) if(freq[cc]) rem_chars++, other_char = cc;
	if(rem_chars > 1){
		if(c <= 'z') suffix = c + suffix;
		while(c <= 'z'){
			c++;
			FOR(i, freq[c]) ans += c;
		}
		ans += suffix;
	}
	else{
		FOR(i, freq[other_char]/2) ans += other_char;
		suffix = ans;
		reverse(all(suffix));
		if(freq[other_char]%2) ans += other_char;
		if(c <= 'z') ans += c;
		ans += suffix;
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