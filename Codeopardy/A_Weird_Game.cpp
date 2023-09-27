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
	string s, t; cin >> s >> t;

	int cnt_11 = 0, cnt_10 = 0, cnt_01 = 0;
	FOR(i, 2*n){
		if(s[i] == '1' && t[i] == '1') cnt_11++;
		else if(s[i] == '1' && t[i] == '0') cnt_10++;
		else if(s[i] == '0' && t[i] == '1') cnt_01++;
	}

	int a_cnt = 0, b_cnt = 0;
	if(cnt_11 % 2){
		a_cnt = cnt_11/2 + 1;
		b_cnt = cnt_11/2;

		if(cnt_01){b_cnt++, cnt_01--;}
		else if(cnt_10){cnt_10--;}
	}
	int min_cnt = min(cnt_01, cnt_10);
	a_cnt += min_cnt;
	b_cnt += min_cnt;
	cnt_01 -= min_cnt;
	cnt_10 -= min_cnt;

	if(cnt_10) a_cnt += (cnt_10+1)/2;
	else if(cnt_01) b_cnt += cnt_01/2;

	if(a_cnt > b_cnt) cout << "First";
	else if(a_cnt < b_cnt) cout << "Second";
	else cout << "Draw";
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}