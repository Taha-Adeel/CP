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
	int n, m; cin >> n >> m;
	vi a(n); FOR(i, n) cin >> a[i], a[i]--;
	vi b(m); FOR(i, m) cin >> b[i], b[i]--;

	auto op = [](vi& v, int i, vi& moves){
		int n = v.size();
		vi ans(n);
		FOR(j, n - i - 1) ans[j] = v[j + i + 1];
		ans[n - i - 1] = v[i];
		FOR(j, i) ans[n - i + j] = v[j];
		v = ans;
		moves.pb(i);
	};

	auto get_moves = [&op](vi& v){
		int n = v.size();
		int r_val = n-1, r_index = -1;
		auto update_right = [&](vi& v){
			FOR(i, n) if(v[i] == r_val) {r_index = i; break;}
			while(r_index) if(v[r_index-1] == r_val-1) r_index--, r_val--; else break;
		};
		update_right(v);
		vi moves;
		while(r_val--){
			if(r_index)
				op(v, r_index-1, moves);
			
			int r_val_i = find(all(v), r_val) - v.begin();
			op(v, r_val_i, moves);
			update_right(v);
		}
		return moves;
	};

	vi moves_a = get_moves(a);
	vi moves_b = get_moves(b);

	if(moves_a.size() % 2 != moves_b.size() % 2) {
		if(m%2) FOR(i, m) moves_b.pb(0);
		else if(n%2) FOR(i, n) moves_a.pb(0);
		else {cout << -1; return;}
	}

	while(moves_a.size() > moves_b.size()) moves_b.pb(((moves_a.size() - moves_b.size())%2) * (m-1));
	while(moves_b.size() > moves_a.size()) moves_a.pb(((moves_b.size() - moves_a.size())%2) * (n-1));

	cout << moves_a.size() << nl;
	FOR(i, moves_a.size()) cout << moves_a[i]+1 << ' ' << moves_b[i]+1 << nl;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}