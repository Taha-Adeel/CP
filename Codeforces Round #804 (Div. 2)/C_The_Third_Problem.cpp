#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> indices() {map<T, int> freq; for(int i=0; i<this->size(); i++) freq[this->at(i)] = i; return freq;}
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

#define N 200001

ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];

void InverseofNumber(ll p = MOD){
	naturalNumInverse[0] = naturalNumInverse[1] = 1;
	for (ll i = 2; i <= N; i++)
		naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}

void InverseofFactorial(ll p = MOD){
	factorialNumInverse[0] = factorialNumInverse[1] = 1;
	for (ll i = 2; i <= N; i++)
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

void factorial(ll p = MOD){
	fact[0] = 1;
	for (ll i = 1; i <= N; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}

void solve(){
	ll n;
	cin >> n;
	vll a(n);
	cin >> a;
	
	auto index = a.indices();
	ll answer = 1;
	ll free_nums = n - 1;

	ll cur_mex = 1;
	ll cur_l = index[0], cur_r = index[0];
	ll cur_empty = 0;
	V<bool> cur_found(n+1, 0);
	cur_found[0] = true;

	while(cur_mex < n){
		ll i = index[cur_mex];
		if(i > cur_r){
			FOR_RANGE(j, cur_r, i+1)
				cur_found[a[j]] = true;
			cur_empty += i - cur_r - 1;
			cur_r = i;
		}
		else{
			FOR_RANGE(j, cur_l, i-1)
				cur_found[a[j]] = true;
			cur_empty += cur_l - i - 1;
			cur_l = i;
		}
		
		ll old_mex = cur_mex;
		while(cur_found[cur_mex])
			cur_mex++;

		answer = (((answer * fact[cur_empty])%MOD) * factorialNumInverse[cur_empty - (cur_mex - old_mex - 1)])%MOD;
		cur_empty -= (cur_mex - old_mex - 1);
		// cout << cur_mex << ' ';
	}
	cout << answer;
}

int main(){
	InverseofNumber();
	InverseofFactorial();
	factorial();

	ll T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}