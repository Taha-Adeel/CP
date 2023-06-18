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

// the value of the letter A is 1, B is 10, C is 100, D is 1000, E is 10000. the values of all digits are summed up, but some digits are taken with negative signs: a digit is taken with negative sign if there is a digit with a strictly greater value to the right of it (not necessarily immediately after it); otherwise, that digit is taken with a positive sign.
ll val_char[5] = {1, 10, 100, 1000, 10000};
ll getStringVal(string s){
	ll val = 0; int n = s.size();
	char largest_char = 'A';
	for(int i = n-1; i >= 0; i--){
		if(s[i] >= largest_char){
			val += val_char[s[i]-'A'];
			largest_char = s[i];
		}
		else{
			val -= val_char[s[i]-'A'];
		}
	}
	return val;
}

char getGreatestCharAfter(int i, V<vll>& freq, string& s, char new_char){
	int n = s.size();
	freq[i][new_char-'A']++; freq[n][new_char-'A']++;
	freq[i][s[i]-'A']--; freq[n][s[i]-'A']--;
	char ans = 'A';
	for(char c = 'E'; c >= 'A'; c--){
		if(freq[n][c-'A'] - freq[i][c-'A'] > 0) {ans = c; break;}
	}
	freq[i][new_char-'A']--; freq[n][new_char-'A']--;
	freq[i][s[i]-'A']++; freq[n][s[i]-'A']++;

	return ans;
}

void solve(){
	string s; cin >> s;
	int n = s.size();

	V<vll> freq(n+1, vll(5, 0));
	FOR(i, n){
		freq[i+1] = freq[i];
		freq[i+1][s[i]-'A']++;
	}

	V<char> greatest_char_after(n, 'A');
	for(int i = n-2; i >= 0; i--){
		greatest_char_after[i] = max(greatest_char_after[i+1], s[i+1]);
	}

	ll ans = 0, s_val = getStringVal(s);
	FOR(i, n){
		for(char c = 'A'; c <= 'E'; c++){
			ll delta = 0;
			for(char d = 'A'; d < c; d++){
				if(greatest_char_after[i] > d) continue;
				delta -= 2 * freq[i][d-'A'] * val_char[d-'A'];
			}
			delta += val_char[c-'A'] * ((c >= greatest_char_after[i]) ? 1 : -1) - val_char[s[i]-'A'] * ((s[i] >= greatest_char_after[i]) ? 1 : -1);
			for(char d = c+1; d <= 'E'; d++){
				if(getGreatestCharAfter(i, freq, s, c) <= d) continue;
				delta += 2 * freq[i][d-'A'] * val_char[d-'A'];
			}
			ans = max(ans, s_val + delta);
			cerr << s_val + delta << ' ';
		}
		cerr << nl;
	}
	cerr << nl;
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