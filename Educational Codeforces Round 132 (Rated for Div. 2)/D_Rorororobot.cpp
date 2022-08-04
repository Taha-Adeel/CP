#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<(int)this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
#define pY {cout << "YES" << nl; continue;}
#define pN {cout << "NO" << nl;  continue;}

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

#define MAXN 200005
#define k 20

int maxarr[MAXN][k];
int lg[MAXN+1];

void populateMaxTable(vi& arr){
	// Precompute log values
	lg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
		lg[i] = lg[i/2] + 1;
		
	FOR(i, arr.size())
		maxarr[i][0] = arr[i];
	
	for(int j = 1; j < k; j++)
		for(int i = 0; i + (1 << j) <= (int)arr.size(); i++)
			maxarr[i][j] = max(maxarr[i][j-1], maxarr[i + (1 << (j - 1))][j - 1]);
}

int get_max(int l, int r){
	if(l > r)
		swap(l, r);
	int j = lg[r - l + 1];
	int value = max(maxarr[l][j], maxarr[r - (1 << j) + 1][j]);

	return value;
}


void solve(){
	int n, m;
	cin >> n >> m;
	vi a(m);
	cin >> a;

	populateMaxTable(a);

	int q;
	cin >> q;
	FOR(i, q){
		int x1, y1, x2, y2, kk;
		cin >> x1 >> y1 >> x2 >> y2 >> kk;

		if((x1 - x2)%kk != 0 || (y1 - y2)%kk != 0)
			pN
		
		int xmax = ((n - x1)/kk)*kk + x1;
		if(get_max(y1-1, y2 - 1) >= xmax)
			pN
		else
			pY
	}
}

int main(){
	FAST;
	solve();
	cout << nl;
	
	return 0;
}