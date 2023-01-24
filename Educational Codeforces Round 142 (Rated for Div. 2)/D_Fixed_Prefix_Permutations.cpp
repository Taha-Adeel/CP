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
	int n, m;
	cin >> n >> m;
	V<vi> a(n, vi(m));
	cin >> a;

	V<V<vi>> sorted_as(m, V<vi>(n, vi(m)));
	FOR(i, m) sorted_as[i] = a;
	FOR(i, m){
		auto cmp = [i](const vi& a, const vi& b){ return a[i] < b[i]; };
		sort(all(sorted_as[i]), cmp);
	}

	for(auto& ai: a){
		int k = 0;
		vi target_lb(m), target_ub(m);
		while(k < m){
			target_lb[ai[k]-1] = k+1;
			target_ub[ai[k]-1] = k+2;
			auto cmp = [&](const vi& a1, const vi& a2){ return a1[ai[k]-1] < a2[ai[k]-1]; };

			int l = lower_bound(all(sorted_as[ai[k]-1]), target_lb, cmp) - sorted_as[ai[k]-1].begin();
			int r = lower_bound(all(sorted_as[ai[k]-1]), target_ub, cmp) - sorted_as[ai[k]-1].begin();
			
			if(l == r) break;
			bool good = false;
			for(int i = l; i < r; i++){
				bool check_next = false;
				for(int kk = 0; kk < k; kk++){
					if(sorted_as[ai[k]-1][i][ai[kk]-1] != kk+1){
						check_next = true;
						break;
					}
				}
				if(check_next) continue;
				good = true;
				break;
			}
			if(!good) break;
			k++;
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