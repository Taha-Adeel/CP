#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
void display(bool answer){cout << ((answer)?"Yes":"No");}
#define pY {cout << "Yes"; return;}
#define pN {cout << "No";  return;}

#define FOR(i, n)                for(int i = 0; i < n; ++i)
#define FOR1(i, n)               for(int i = 1; i < n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = n-1; i >= 0; --i)

#define F  first
#define S  second
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	int N;
	cin >> N;
	string s;
	cin >> s;

	set<char> vowels{'a', 'e', 'i', 'o', 'u'};

	V<string> substrings;
	string v = "";
	int l = 0;
	FOR(r, s.size()){
		if(vowels.find(s[r]) != vowels.end()){
			v += s[r];
			if(r == l)
				substrings.pb("");
			else
				substrings.pb(s.substr(l, r-l));
			l=r+1;
		}
	}
	string ans = "";
	int sz = substrings.size();
	if(sz%2 == 0){
		FOR(i, sz){
			if(i < sz/2){
				reverse(substrings[sz-1 - 2*i].begin(), substrings[sz-1 -2*i].end());
				ans += substrings[sz-1 -2*i] + v[sz-1 -2*i + sz%2 - 1];
			}
			else{
				ans += substrings[2*(i - sz/2)] + v[2*(i - sz/2) + 1];
			}
		}
		ans += s.substr(l);
	}
	else if(sz%2 == 1){
		FOR(i, sz){
			if(i <= sz/2){
				reverse(substrings[sz-1 - 2*i].begin(), substrings[sz-1 -2*i].end());
				ans += substrings[sz-1 -2*i];
				if(sz-1 -2*i != 0)
					ans += v[sz-1 -2*i - 1];
			}
			else{
				ans += v[2*(i - (sz + 1)/2)];
				ans += substrings[2*(i - (sz + 1)/2) + 1];
			}
		}
		ans += s.substr(l-1);
	}
	// cout << substrings;
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