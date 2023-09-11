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
#define pY {cout << "Yes"; return;}
#define pN {cout << "No";  return;}
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

bool is_pow_2(ll n){
	return (n&(n-1)) == 0;
}

void solve(){
	ll n; cin >> n;
	vll a(n); cin >> a;

	ll total = a.sum(), final = total/n;
	if(total%n) pN

	vi exs_cnt(32, 0), def_cnt(32, 0);
	FOR(i, n){
		string dif = bitset<33>(abs(a[i] - final)).to_string();

		int cnt_01 = 0;
		FOR(j, dif.size()-1) if(dif[j] == '0' && dif[j+1] == '1') cnt_01++;
		if(cnt_01 > 1) pN
		else if(cnt_01 == 0){
			continue;
		}

		int first_1 = 0, last_1 = 0;
		FOR(j, dif.size()) if(dif[j] == '1') {first_1 = j; break;}
		ROF(j, dif.size()) if(dif[j] == '1') {last_1 = j; break;}

		if(a[i] > final){
			exs_cnt[dif.size() - first_1 + 1]++;
			def_cnt[dif.size() - last_1]++;
		}
		else{
			exs_cnt[dif.size() - last_1]++;
			def_cnt[dif.size() - first_1 + 1]++;
		}
	}

	
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