#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort()     {std::sort(this->begin(), this->end());}
	void sort_dsc() {std::sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<(int)this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "Yes"; return;}
#define pN {cout << "No";  return;}

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()

#define F  first
#define S  second
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	ll n, m , k;
	cin >> n >> m >> k;
	vll a(k);
	cin >> a;

	vll rows_colored(k, 0);
	FOR(i, k)
		rows_colored[i] = (a[i]/m > 1) ? a[i]/m : 0;
	
	rows_colored.sort_dsc();
	ll row_sum = 0;
	bool edge_case = false;
	FOR(i, k){
		if(row_sum == n - 1)
			edge_case = true;
		row_sum += rows_colored[i];

		if(!edge_case && row_sum >= n)
			pY
		if(edge_case && row_sum >= n+1 && rows_colored[0] > 2)
			pY
	}

	vll colmn_colored(k, 0);
	FOR(i, k)
		colmn_colored[i] = (a[i]/n > 1) ? a[i]/n : 0;
	
	colmn_colored.sort_dsc();
	ll colmn_sum = 0;
	edge_case = false;
	FOR(i, k){
		if(colmn_sum == m - 1)
			edge_case = true;
	colmn_sum += colmn_colored[i];

		if(!edge_case && colmn_sum >= m)
			pY
		if(edge_case && colmn_sum >= m+1 && colmn_colored[0] > 2)
			pY
	}
	
	pN
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