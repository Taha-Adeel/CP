#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort()     {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i < (int)n; ++i)
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
	int n;
	cin >> n;
	vi a(n);
	cin >> a;

	int intimidation_val = 0;
	vi hill_or_valley(n, 0);

	FOR1(i, n-1){
		if(a[i] < a[i + 1] && a[i] < a[i - 1]){
			intimidation_val++;
			hill_or_valley[i] = -1;
		}
		else if(a[i] > a[i + 1] && a[i] > a[i - 1]){
			intimidation_val++;
			hill_or_valley[i] = 1;
		}
	}

	int max_change = 0;
	FOR1(i, n-1){
		int cur_change;
		if(hill_or_valley[i] == 0){
			if(hill_or_valley[i-1] && hill_or_valley[i+1])
				cur_change = 1;
			else if (hill_or_valley[i-1]){
				if(a[i] != a[i+1] || i == n - 2)
					cur_change = 1;
				else{
					if(i < n - 1)
				}
			}
			
			
		}
		max_change = max(max_change, abs(hill_or_valley[i-1]) + abs(hill_or_valley[i]) + abs(hill_or_valley[i+1]));
	}

	cout << intimidation_val - max_change;
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