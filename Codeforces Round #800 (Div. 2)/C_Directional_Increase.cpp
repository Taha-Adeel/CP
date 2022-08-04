#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};

#define FOR(i, n)                for(int i = 0; i < n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; (i - end)*((start<end)?1:-1) <= 0; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = n-1; i >= 0; --i)

#define F  first
#define S  second
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll   = long long int;
using p_ii = pair<int,int>;
using p_ll = pair<ll,ll>;
using vi   = V<int>;
using vll  = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	ll n;
	cin >> n;
	vll a(n);
	cin >> a;

	ll sum = 0;
	FOR(i, n)
		sum += a[i];
	if(sum != 0){
		cout << "No";
		return;
	}

	if(n == 1){
		cout << "Yes";
		return;
	}

	FOR_REV(i, n){
		if(a[i] == 0)
			n--;
		else
			break;
	}
	if(n < 2){
		if(n == 0)
			cout << "Yes";
		if(n == 1)
			cout << "No";
		
		return;
	}

	vll v(n, 1);
	v[n - 1] = 0;
	v[n - 2] = 0;
	
	bool answer = true;
	FOR_RANGE(i, n-2, 0){
		ll operations = v[i+1] - a[i+1];
		if(operations < 0){
			answer = false;
			break;
		}
		v[i] += operations;
		v[i + 1] -= operations;

		if(i != 0)
			v[i] -= 1;
	}

	if(answer)
		cout << "Yes";
	else
		cout << "No";
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