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
	int n, m, d; cin >> n >> m >> d;
	vi a(m); cin >> a;

	int cookies_eaten = 1, sellers_on_d_dist = 0, sellers_can_delete = 0, can_dec_cookie_cnt = 0;
	int prev = 1;

	FOR(i, m){
		if((a[i] - prev) % d == 0) sellers_on_d_dist++;
		else{
			int next_seller = n+1;
			if(i != m-1) next_seller = a[i+1];

			int cookie_cnt_no_del = 3 + (a[i] - prev) / d + (next_seller - a[i] - 1) / d;
			int cookie_cnt_del = 2 + (next_seller - prev - 1) / d;

			if(cookie_cnt_del < cookie_cnt_no_del){
				sellers_can_delete++;
				can_dec_cookie_cnt = 1;
			}
			else sellers_on_d_dist++;
			cookies_eaten += 1 + (a[i] - prev) / d;
			prev = a[i];
		}
	}
	cookies_eaten += (n - prev) / d;

	if(can_dec_cookie_cnt)
		cout << cookies_eaten - 1 << ' ' << sellers_can_delete;
	else
		cout << cookies_eaten << ' ' << sellers_on_d_dist;
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