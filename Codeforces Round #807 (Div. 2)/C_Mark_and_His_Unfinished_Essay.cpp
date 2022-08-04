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

#define FOR(i, n)                for(ll i = 0; i < (ll)n; ++i)
#define FOR1(i, n)               for(ll i = 1; i < (ll)n; ++i)
#define FOR_RANGE(i, start, end) for(ll i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(ll i = (ll)n-1; i >= 0; --i)

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
	ll n, c, q;
	cin >> n >> c >> q;
	string s;
	cin >> s;
	V<pll> ops(c);
	vll k(q);
	FOR(i, c)
		cin >> ops[i].F >> ops[i].S;
	cin >> k;

	vll prefix_sum(c+1, n);
	FOR(i, ops.size())
		prefix_sum[i+1] = prefix_sum[i] + ops[i].S - ops[i].F + 1;
	
	FOR(i, q){
		ll cur_k = k[i];
		ll ci = c;
		while(cur_k > n){
			ci = lower_bound(prefix_sum.begin(), prefix_sum.begin() + ci, cur_k) - prefix_sum.begin();
			cur_k = cur_k - prefix_sum[ci-1] + ops[ci-1].F - 1;
		}
		cout << s[cur_k - 1] << nl;
	}
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		solve();
	}
	
	return 0;
}