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
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)            for(int i = (int)n-1; i >= 0; --i)
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
	int n; cin >> n;
	vi a(n); cin >> a;

	vi inc_ln(n, 1);
	FOR1(i, n-1) if(a[i] > a[i-1])
		inc_ln[i] = inc_ln[i-1]+1;

	vi dec_ln(n, 1);
	ROF(i, n-1) if(a[i] > a[i+1])
		dec_ln[i] = dec_ln[i+1]+1;

	cerr << inc_ln << nl;
	cerr << dec_ln << nl;


	int max_inc_len = *max_element(all(inc_ln)), max_dec_len = *max_element(all(dec_ln));
	int max_inc_len_cnt = count(all(inc_ln), max_inc_len), max_dec_len_cnt = count(all(dec_ln), max_dec_len);

	if(max_inc_len > max_dec_len){
		if(max_inc_len_cnt > 1 || max_inc_len%2 == 0 || max_dec_len == 1) cout << 0;
		else cout << 1;
	}
	else if(max_dec_len > max_inc_len){
		if(max_dec_len_cnt > 1 || max_dec_len%2 == 0 || max_inc_len == 1) cout << 0;
		else cout << 1;
	}
	else{
		if(max_inc_len_cnt + max_dec_len_cnt > 2) cout << 0;
		else{
			int i = find(all(inc_ln), max_inc_len) - inc_ln.begin();
			int j = find(all(dec_ln), max_dec_len) - dec_ln.begin();
			if(i != j) cout << 0;
			else if(max_inc_len%2 == 0) cout << 0;
			else cout << 1;
		}
	}
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}