#include <bits/stdc++.h>

using namespace std;

#define FAST 		ios::sync_with_stdio(0); cin.tie(0)
#define FOR(a,c) 	for (int a=0; a<c; ++a)
template<class T> struct v: vector<T>{
	using vector<T>::vector;
	void my_sort() {sort(this->begin(), this->end());}
	void my_rev_sort() {sort(this->begin(), this->end(), greater<T>());}
	friend ostream& operator << (ostream &outFunc, const v<T> &_v) {for(auto& i: _v) outFunc << i << ' '; return outFunc;}
	friend istream& operator >> (istream &inFunc, v<T> &_v) {for(auto& i: _v) inFunc >> i; return inFunc;}
};

#define pb 	push_back
#define f 	first
#define s 	second
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll   = long long int;
using p_ii = pair<int,int>;
using p_ll = pair<ll,ll>;
using v_i  = v<int>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

// Incorrect approach. Use dp to recursively solve.
void solve(){
	ll N;
	cin >> N;
	v<ll> C(N), V(N);
	cin >> C;
	cin >> V;

	v<pair<p_ll, ll>> piles(N);
	FOR(i, N)
		piles[i] = {{V[i], i}, C[i]};
	
	piles.my_rev_sort();

	ll A = 0, B = 0;
	int curr_index = 0;
	int move = 1;
	for(auto& p: piles){
		if(p.f.s < curr_index || p.s%2 == 0)
			continue;
		if(move%2)
			A += p.f.f;
		else
			B += p.f.f;
		curr_index = p.f.s + 1;
		move++;
	}
	cout << A - B << nl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}