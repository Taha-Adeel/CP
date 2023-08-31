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
#define FOR1(i, n)               for(int i = 1; i < (int)n; ++i)
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
	string ss = "";
	ss += s[0];

	FOR1(i, n){
		if(s[i] == '-'){
			if(ss.back() == '+') ss.pop_back();
			else ss += '-';
		}
		else ss += s[i];
	}
	for(int i = ss.size() - 1; i >= 0; i--) 
		if(ss[i] != '0' && ss[i] != '1') ss.pop_back();
		else break;
	s = ss;
	n = s.size();

	string next_q = s;
	char last_q = s.back();
	ROF(i, n){
		if(next_q[i] != '0' && next_q[i] != '1') next_q[i] = last_q;
		else last_q = next_q[i];
	}

	vi arr;
	int zero_count = 0, one_count = 0;
	FOR(i, n){
		char c = s[i];
		if(c == '+'){
			if(arr.empty()) arr.pb(2);
			else{
				if(next_q[i] == '1') arr.pb(2);
				else arr.pb(1);
			}
		}
		else if(c == '-'){
			if(arr.back() == 0) zero_count--;
			arr.pop_back();
		}
		else if(c == '1'){
			if(zero_count) pN
			ROF(j, arr.size()){
				if(arr[j] == 1) arr[j] = 2;
				else break;
			}
		}
		else if(c == '0'){
			if(arr.empty() || arr.back() == 2) pN
			if(zero_count) continue;
			arr.back() = 0;
			zero_count++;
		}
	}

	pY
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