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

void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	vll x(n);
	cin >> x;

	vll prefix_sums(n+1, 0);
	FOR1(i, n+1)
		prefix_sums[i] = prefix_sums[i - 1] + x[i - 1];
	
	map<ll, int> cur_prefix_sums;
	
	ll max_so_far = - (1e18);
	FOR_RANGE(i, a-1, n){
		if(i >= b){
			cur_prefix_sums[prefix_sums[i - b]]--;
			if(cur_prefix_sums[prefix_sums[i - b]] == 0)
				cur_prefix_sums.erase(prefix_sums[i - b]);
		}
		cur_prefix_sums[prefix_sums[i - (a-1)]]++;
		max_so_far = max(max_so_far, prefix_sums[i+1] - cur_prefix_sums.begin()->F);
	}
	cout << max_so_far;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}