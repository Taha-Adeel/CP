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
	string s; cin >> s;

	int n = s.size();
	string ans = s;
	FOR(i, n){
		if(i == 0){
			if(s[i] >= '5'){
				ans = '1' + string(n, '0'); break;
			}
			if(s[i] == '4'){
				int og_i = i;
				while(i < n && s[i] == '4') i++;
				if(i < n){
					if(s[i] >= '5'){
						if(og_i == 0) ans = '1' + string(n, '0');
						else ans = s.substr(0, og_i-1) + (char)(s[og_i-1]+1) + string(n-og_i, '0'); break;
					}
				}
			}
		}
		else if(s[i] == '4'){
			int og_i = i;
			while(i < n && s[i] == '4') i++;
			if(i < n){
				if(s[i] >= '5'){
					ans = s.substr(0, og_i-1) + (char)(s[og_i-1]+1) + string(n-og_i, '0'); break;
				}
			}
		}
		else if(s[i] >= '5'){
			ans = s.substr(0, i-1) + (char)(s[i-1]+1) + string(n-i, '0'); break;
		}
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