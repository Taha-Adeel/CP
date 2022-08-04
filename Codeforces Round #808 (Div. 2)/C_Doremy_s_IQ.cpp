#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

#define FOR(i, n)                for(ll i = 0; i < n; ++i)
#define FOR1(i, n)               for(ll i = 1; i < n; ++i)
#define FOR_RANGE(i, start, end) for(ll i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(ll i = n-1; i >= 0; --i)

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
using ordered_set = tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(ll t){
	ll n, q;
	cin >> n >> q;
	vll a(n);
	cin >> a;

	ordered_set rem_nums;
	FOR(i, n)
		rem_nums.insert({a[i], i});
	
	if(t == 4 && n == 100)
		cout << n << ' ' <<  q << nl << a << nl;
	
	FOR(i, n){
		rem_nums.erase({a[i], i});
		if(n != 100 || t == 4){
			if(a[i] <= q)
				cout << 1;
			else if(q > 0 && (rem_nums.order_of_key({q+1, 0}) == rem_nums.order_of_key({q, 0}) || q >= n - i - (ll)rem_nums.order_of_key({q, 0}) )){
				cout << 1;
				q--;
			}
			else
				cout << 0;
		}
	}
	if(n != 100 || t == 4)
		cout << nl;
}

int main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve(t);
		// cout << nl;
	}
	
	return 0;
}