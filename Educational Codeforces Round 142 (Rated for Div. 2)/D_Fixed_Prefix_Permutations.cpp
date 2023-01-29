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

ll hash_vi(vi& a){
	ll h = 0;
	for(auto& ai: a) h = (h*16) + ai;
	return h;
}

void solve(){
	int n, m;
	cin >> n >> m;
	V<vi> a(n, vi(m));
	cin >> a;

	vll hashes(n);
	FOR(i, n) hashes[i] = hash_vi(a[i]);
	V<vi> sorted_as(m, vi(n));
	FOR(i, m) iota(all(sorted_as[i]), 0);
	FOR(i, m){
		auto cmp = [&](const int& x, const int& y){ return a[x][i] < a[y][i]; };
		sort(all(sorted_as[i]), cmp);
	}

	for(auto& ai: a){
		ll k = 0, cur_set_hash = 0, mask = 0;
		while(k < m){
			cur_set_hash |= ((k+1) << ((m - ai[k])*4));
			mask |= (15LL << ((m - ai[k])*4));

			auto cmp = [&](const int& x, const int& y){return a[x][ai[k]-1] < y; };

			int l = lower_bound(all(sorted_as[ai[k]-1]), k+1, cmp) - sorted_as[ai[k]-1].begin();
			int r = lower_bound(all(sorted_as[ai[k]-1]), k+2, cmp) - sorted_as[ai[k]-1].begin();
			
			if(l == r) break;
			bool good = false;
			for(int i = l; i < r; i++){
				if((hashes[sorted_as[ai[k]-1][i]] & mask) == cur_set_hash){
					good = true;
					k++;
					break;
				}
			}
			if(!good) break;
		}
		cout << k << ' ';
	}
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