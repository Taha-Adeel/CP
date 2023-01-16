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
	int n;
	cin >> n;
	string s;
	cin >> s;

	map<char, int> freq;
	for(auto& c: s) freq[c]++;
	vi freqs;
	for(auto& [c, f]: freq) freqs.pb(f);
	freqs.sort();

	int ans = n-1, min_i = 1, nf = freqs.size();
	FOR1(i, 26){
		if(n%i) continue;
		int cur_ans = 0;
		for(int j = 0; j < nf-i; j++)
			cur_ans += freqs[j];
		for(int j = max(nf-i, 0); j < nf; j++)
			cur_ans += max(0, freqs[j] - n/i);
		if(cur_ans <= ans)
			ans = cur_ans,
			min_i = i;
	}

	string t = s;
	int extra_chars_required = max(0, min_i - (int)freqs.size());
	map<char, int> to_add, to_dec;
	V<pair<int, char>> sorted_freqs;
	for(auto& [c, f]: freq) sorted_freqs.pb({f, c});
	sorted_freqs.sort();
	for(int j = 0; j < nf-min_i; j++)
		to_dec[sorted_freqs[j].S] = freqs[j];
	for(int j = max(nf-min_i, 0); j < nf; j++)
		if(freq[sorted_freqs[j].S] > n/min_i)
			to_dec[sorted_freqs[j].S] = freqs[j] - n/min_i;
		else if(freq[sorted_freqs[j].S] < n/min_i)
			to_add[sorted_freqs[j].S] = n/min_i - freqs[j];

	int i = 0;
	while(extra_chars_required--){
		while(freq.count('a'+i)) i++;
		to_add['a'+ i++] = n/min_i;
	}

	for(auto& c: t){
		if(to_dec.count(c)){
			to_dec[c]--;
			if(to_dec[c] == 0) to_dec.erase(c);
			c = to_add.begin()->F;
			to_add[c]--;
			if(to_add[c] == 0) to_add.erase(c);
		}
	}
	
	cout << ans << nl;
	cout << t;
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