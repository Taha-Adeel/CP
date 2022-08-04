#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};

#define FOR(i, n)                for(int i = 0; i < n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = n-1; i >= 0; --i)

#define F  first
#define S  second
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll   = long long int;
using p_ii = pair<int,int>;
using p_ll = pair<ll,ll>;
using vi   = V<int>;
using vll  = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	int n, m;
	cin >> n >> m;

	V<vi> board(n, vi(m));
	cin >> board;

	int max_elem = INT_MIN;
	int i_max, j_max;
	FOR(i, n){
		FOR(j, m){
			if(board[i][j] > max_elem){
				max_elem = board[i][j];
				i_max = i;
				j_max = j;
			}
		}
	}
	i_max++; j_max++;

	cout << (max(i_max, n-i_max + 1) * max(j_max, m - j_max + 1)); 
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