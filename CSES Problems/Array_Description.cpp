#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}

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

ll total(const map<int, ll>& mp){
	ll sum = 0;
	for(auto& num: mp)
		sum += num.S;
	
	return sum;
}

void solve(){
	int n, m;
	cin >> n >> m;
	vi a(n);
	cin >> a;

	FOR(i, n-1){
		if(a[i]*a[i+1] != 0 && abs(a[i] - a[i+1]) > 1){
			cout << 0;
			return;
		}
	}
	
	vi lb(n, 1), ub(n, m);
	FOR(i, n){
		if(a[i] != 0){
			lb[i] = a[i];
			ub[i] = a[i];
		}
	}
	
	FOR1(i, n){
		if(a[i] == 0){
			lb[i] = max(lb[i-1] - 1, 1);
			ub[i] = min(ub[i-1] + 1, m);
		}
	}
	FOR_REV(i, n-1){
		if(a[i] == 0){
			lb[i] = max({lb[i], lb[i+1] - 1, 1});
			ub[i] = min({ub[i], ub[i+1] + 1, m});
		}
	}

	ll ans = 1;
	map<int, ll> cur_freqs;
	FOR_RANGE(i, lb[0], ub[0]+1)
		cur_freqs[i]++;

	FOR1(i, n-1){
		auto old_freqs = cur_freqs;
		FOR_RANGE(x, lb[i-1], ub[i-1]+1){
			if(x - 1 >= lb[i])
				cur_freqs[x - 1] = (cur_freqs[x - 1] + old_freqs[x]) % MOD;
			if(x + 1 <= ub[i])
				cur_freqs[x + 1] = (cur_freqs[x + 1] + old_freqs[x]) % MOD;
			if(x < lb[i] || x > ub[i])
				cur_freqs.erase(x);
		}
		if(a[i] != 0 && a[i-1] == 0){
			ans = (ans * cur_freqs[a[i]]) % MOD;
			cur_freqs[a[i]] = 1;
		}
	}
	if(a[n-1] == 0)
		ans = (ans * total(cur_freqs)) % MOD;

	cout << ans;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}