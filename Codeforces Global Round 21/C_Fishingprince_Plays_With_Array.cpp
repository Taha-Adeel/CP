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
#define pY {cout << "Yes"; return;}
#define pN {cout << "No";  return;}

#define FOR(i, n)                for(int i = 0; i < n; ++i)
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
	ll n, m;
	cin >> n >> m;
	V<pll> a(n);
	FOR(i, n){
		cin >> a[i].F;
		a[i].S = 1;
	}
	int k;
	cin >> k;
	V<pll> b(k);
	FOR(i, k){
		cin >> b[i].F;
		b[i].S = 1;
	}

	FOR(i, n){
		while((a[i].F)%m == 0){
			a[i].F /= m;
			a[i].S *= m;
		}
	}
	FOR(i, k){
		while((b[i].F)%m == 0){
			b[i].F /= m;
			b[i].S *= m;
		}
	}
	V<pll> aa(1, a[0]), bb(1, b[0]);
	FOR_RANGE(i, 1, n){
		if(a[i].F == aa.back().F)
			aa.back().S += a[i].S;
		else
			aa.pb(a[i]);
	}
	FOR_RANGE(i, 1, k){
		if(b[i].F == bb.back().F)
			bb.back().S += b[i].S;
		else
			bb.pb(b[i]);
	}
	if(aa.size() != bb.size())
		pN
	
	FOR(i, aa.size()){
		if(aa[i] != bb[i])
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