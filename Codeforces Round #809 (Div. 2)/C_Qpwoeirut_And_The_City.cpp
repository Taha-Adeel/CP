#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort()     {std::sort(this->begin(), this->end());}
	void sort_dsc() {std::sort(this->begin(), this->end(), greater<T>());}
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
	vll a(n);
	cin >> a;
	
	if(n%2){
		ll ans = 0;
		FOR(i, n){
			if(i%2){
				if(a[i] > a[i+1] && a[i] > a[i - 1])
					continue;
				ans += max(a[i-1], a[i+1]) + 1 - a[i];
			}
		}

		cout << ans;
	}
	else{
		ll ans = 0;
		FOR1(i, n-1){
			if(i%2 == 0){
				if(a[i] > a[i+1] && a[i] > a[i - 1])
					continue;
				ans += max(a[i-1], a[i+1]) + 1 - a[i];
			}
		}
		ll min_ans = ans;
		FOR(i, n/2 - 1){
			int cur_i = 2*i + 1;
			if(!(a[cur_i] > a[cur_i+1] && a[cur_i] > a[cur_i - 1]))
				ans += max(a[cur_i-1], a[cur_i+1]) + 1 - a[cur_i];
			cur_i++;
			if(!(a[cur_i] > a[cur_i+1] && a[cur_i] > a[cur_i - 1]))
				ans -= max(a[cur_i-1], a[cur_i+1]) + 1 - a[cur_i];
			
			min_ans = min(min_ans, ans);
		}

		cout << min_ans;
	}
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