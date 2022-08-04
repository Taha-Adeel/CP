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
	ll n, k;
	cin >> n >> k;
	v<ll> a(n);
	cin >> a;

	ll answer = 0;
	FOR(i, n)
		answer += a[i]/k;

	v_i mod_k(k, 0);
	FOR(i, n)
		mod_k[a[i] % k]++;

	// v_i pairable(k, 0);
	// FOR(i, k){
	// 	if(i == 0)
	// 		continue;
	// 	pairable[i] = pairable[i - 1] + mod_k[k - i];
	// }
	for(ll i = 1; i < k; i++){
		ll j = k - i;
		while(mod_k[i] > 0){
			for(; j < k; j++){
				if(mod_k[j] != 0)
					break;
			}
			if(j == k){
				break;
			}
			if(i == j && mod_k[j] == 1)
				break;
			mod_k[i]--;
			mod_k[j]--;
			answer++;
		}
	}

	cout << answer << nl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}