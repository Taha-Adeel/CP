#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
void display(bool answer){cout << ((answer)?"Yes":"No");}
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

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	ll N;
	cin >> N;
	vll a(N);
	cin >> a;
	
	vll ps, ns;
	auto freq = a.freqs();

	FOR(i, N){
		if(a[i] > 0)
			ps.pb(a[i]);
		else if(a[i] < 0)
			ns.pb(a[i]);
	}

	if(ps.size() > 2 || ns.size() > 2)
		pN
	
	if(ps.size() == 2){
		ll sum = ps[0] + ps[1];
		if(freq[0] > 0)
			pN
		for(auto n: ns){
			if(freq[sum + n] == 0)
				pN
		}
		for(auto p: ps){
			if(freq[0] >= 1){
				for(auto n: ns){
					if(freq[n + p] == 0)
						pN
				}
			}
		}
	}
	if(ns.size() == 2){
		ll sum = ns[0] + ns[1];
		if(freq[0] > 0)
			pN
		for(auto p: ps){
			if(freq[sum + p] == 0)
				pN
		}
		for(auto n: ns){
			if(freq[0] >= 1){
				for(auto p: ps){
					if(freq[n + p] == 0)
						pN
				}
			}
		}
	}
	if(ps.size() == 1){
		if(ns.size() == 1 && freq[ps[0] + ns[0]] == 0)
			pN
	}
	if(ns.size() == 1){
		if(ps.size() == 1 && freq[ns[0] + ps[0]] == 0)
			pN
	}

	pY
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