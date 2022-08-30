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

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()

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
	V<string> grid(n);
	cin >> grid;

	V<V<pii>> set(n, V<pii>(m, {-1, -1}));
	pii def = {-1, -1};
	FOR(i, n-1){
		FOR(j, m-1){
			if(grid[i][j] == '*' && grid[i+1][j] == '*' && grid[i+1][j+1] == '*'){
				if(set[i][j] == def && set[i+1][j] == def && set[i+1][j+1] == def){
					set[i][j] = {i, j};
					set[i+1][j] = {i, j};
					set[i+1][j+1] = {i, j};
				}
				else pN
			}
		}
	}
	FOR(i, n-1){
		FOR(j, m-1){
			if(grid[i][j] == '*' && grid[i][j+1] == '*' && grid[i+1][j+1] == '*'){
				if(set[i][j] == def && set[i][j+1] == def && set[i+1][j+1] == def){
					set[i][j] = {i, j};
					set[i][j+1] = {i, j};
					set[i+1][j+1] = {i, j};
				}
				else pN
			}
		}
	}
	FOR(i, n-1){
		FOR(j, m-1){
			if(grid[i][j] == '*' && grid[i+1][j] == '*' && grid[i][j+1] == '*'){
				if(set[i][j] == def && set[i+1][j] == def && set[i][j+1] == def){
					set[i][j] = {i, j};
					set[i+1][j] = {i, j};
					set[i][j+1] = {i, j};
				}
				else pN
			}
		}
	}
	FOR(i, n-1){
		FOR(j, m-1){
			if(grid[i][j+1] == '*' && grid[i+1][j] == '*' && grid[i+1][j+1] == '*'){
				if(set[i][j+1] == def && set[i+1][j] == def && set[i+1][j+1] == def){
					set[i][j+1] = {i, j+1};
					set[i+1][j] = {i, j+1};
					set[i+1][j+1] = {i, j+1};
				}
				else pN
			}
		}
	}

	auto is_good = [&](int i, int j){
		bool ans = true;
		if(i > 0) if(set[i-1][j] != set[i][j] && set[i-1][j] != def) ans = false;
		if(i < n-1) if(set[i+1][j] != set[i][j] && set[i+1][j] != def) ans = false;
		if(j > 0) if(set[i][j-1] != set[i][j] && set[i][j-1] != def) ans = false;
		if(j < m-1) if(set[i][j+1] != set[i][j] && set[i][j+1] != def) ans = false;
		if(i > 0 && j > 0) if(set[i-1][j-1] != def && set[i-1][j-1] != set[i][j]) ans = false;
		if(i > 0 && j < m-1) if(set[i-1][j+1] != def && set[i-1][j+1] != set[i][j]) ans = false;
		if(i < n-1 && j > 0) if(set[i+1][j-1] != def && set[i+1][j-1] != set[i][j]) ans = false;
		if(i < n-1 && j < m-1) if(set[i+1][j+1] != def && set[i+1][j+1] != set[i][j]) ans = false;

		return ans;
	};

	FOR(i, n)
		FOR(j, m)
			if(grid[i][j] == '*' && set[i][j] == def) 
				pN
			else if(grid[i][j] == '*' && !is_good(i, j)) 
				pN
	
	pY
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