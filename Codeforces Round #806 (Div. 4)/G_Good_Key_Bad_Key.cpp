#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
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
	ll n, k;
	cin >> n >> k;
	vll a(n);
	cin >> a;
	vll a_copy = a;
	V<vll> rem_sum(32, vll(n+1, 0));
	FOR(bad_keys, 32){
		FOR_REV(i, n)
			rem_sum[bad_keys][i] = rem_sum[bad_keys][i+1] + a[i];
		
		FOR(i, n)
			a[i] /= 2;
	}
	ll cur_money = 0;
	ll good_keys = 0, bad_keys = 0;

	FOR(i, n){
		if(k < rem_sum[bad_keys][i] - rem_sum[bad_keys+1][i]){
			cur_money -= k;
			good_keys++;
			cur_money += (a_copy[i] >> bad_keys);
		}
		else{
			bad_keys++;
			cur_money += (a_copy[i] >> bad_keys);
		}
	}
	cout << cur_money;
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