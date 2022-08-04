#include <bits/stdc++.h>

using namespace std;

#define FAST 		ios::sync_with_stdio(0); cin.tie(0)
#define FOR(a,c) 	for (int a=0; a<c; ++a)
template<class T> struct v: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	friend ostream& operator << (ostream &outFunc, const v<T> &_v) {for(auto& i: _v) outFunc << i << ' '; return outFunc;}
	friend istream& operator >> (istream &inFunc, v<T> &_v) {for(auto& i: _v) inFunc >> i; return inFunc;}
};

#define f 	first
#define s 	second
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll   = long long int;
using p_ii = pair<int,int>;
using p_ll = pair<ll,ll>;
using v_i  = v<int>;
using v_ll  = v<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	int n;
	cin >> n;
	v_i a(n), b(n);
	cin >> a >> b;

	// v_i ops_req(n);
	// FOR(i, n)
	// 	ops_req[i] = a[i] - b[i];

	// int max_ops_req = *max_element(ops_req.begin(), ops_req.end());
	// if(max_ops_req < 0){
	// 	cout << "NO" << nl;
	// 	return;
	// }

	// FOR(i, n)
	// 	a[i] = max(a[i] - max_ops_req, 0);

	// FOR(i, n){
	// 	if(a[i] != b[i]){
	// 		cout << "NO" << nl;
	// 		return;
	// 	}
	// }
	// cout << "YES" << nl;

	int num_of_operations = INT_MIN;
	FOR(i, n){
		if(b[i] == 0)
			continue;
		else{
			num_of_operations = a[i] - b[i];
			break;
		}
	}
	if(num_of_operations == INT_MIN){
		cout << "YES" << nl;
		return;
	}
	if(num_of_operations < 0){
		cout << "NO" << nl;
		return;
	}
	FOR(i, n){
		if(max(a[i] - num_of_operations, 0) != b[i]){
			cout << "NO" << nl;
			return;
		}
	}
	cout << "YES" << nl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}