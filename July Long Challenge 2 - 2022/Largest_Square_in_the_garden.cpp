#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
void display(bool answer){cout << ((answer)?"Yes":"No");}
#define pY {cout << "Yes"; return;}
#define pN {cout << "No";  return;}

#define FOR(i, n)                for(int i = 0; i < n; ++i)
#define FOR1(i, n)               for(int i = 1; i < n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = n-1; i >= 0; --i)

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
#define MAXN 1000001
#define k 25

int maxarr[MAXN][k];
int minarr[MAXN][k];
int lg[MAXN+1];

void populateMinTable(vi& arr){
	FOR(i, arr.size())
		minarr[i][0] = arr[i];
	
	for(int j = 1; j < k; j++)
		for(int i = 0; i + (1 << j) <= arr.size(); i++)
			minarr[i][j] = min(minarr[i][j-1], minarr[i + (1 << (j - 1))][j - 1]);
}
void populateMaxTable(vi& arr){
	FOR(i, arr.size())
		maxarr[i][0] = arr[i];
	
	for(int j = 1; j < k; j++)
		for(int i = 0; i + (1 << j) <= arr.size(); i++)
			maxarr[i][j] = max(maxarr[i][j-1], maxarr[i + (1 << (j - 1))][j - 1]);
}

int get_min(int l, int r){
	int j = lg[r - l + 1];
	int value = min(minarr[l][j], minarr[r - (1 << j) + 1][j]);

	return value;
}
int get_max(int l, int r){
	int j = lg[r - l + 1];
	int value = max(maxarr[l][j], maxarr[r - (1 << j) + 1][j]);

	return value;
}


void solve(){
	int N;
	cin >> N;
	vi A(N), B(N);
	FOR(i, N)
		cin >> A[i] >> B[i];
	
	populateMaxTable(A);
	populateMinTable(B);

	auto is_green_square = [&](int size) -> bool{
		FOR(i, N - size + 1){
			int A_max_i = get_max(i, i + size - 1);
			int B_min_i = get_min(i, i + size - 1);

			if(B_min_i - A_max_i + 1 >= size)
				return true;
		}
		return false;
	};

	int l = 1, r = N;
	while(l < r){
		int m = (l + r + 1)/2;
		if(is_green_square(m))
			l = m;
		else
			r = m - 1;
	}

	cout << l;
}

int main(){
	// Precompute log values
	lg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
		lg[i] = lg[i/2] + 1;

	solve();
	cout << nl;
	
	return 0;
}