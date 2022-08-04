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
	ll A, B, C;
	cin >> A >> B >> C;

	ll bit_mask = 1;
	bool answer = false;
	for(int i=0; i <= 32; i++, bit_mask <<= 1){
		if(A==B && B==C){
			answer = true;
			break;
		}
		int count = 0;
		count += (A&bit_mask)?1:0;
		count += (B&bit_mask)?1:0;
		count += (C&bit_mask)?1:0;
		if(count == 2){
			if((A&bit_mask) == 0)
				A |= bit_mask;
			else if((B&bit_mask) == 0)
				B |= bit_mask;
			else if((C&bit_mask) == 0)
				C |= bit_mask;
		}
		else if(count == 1){
			if(A&bit_mask)
				A += bit_mask;
			else if(B&bit_mask)
				B += bit_mask;
			else if(C&bit_mask)
				C += bit_mask;
		}
		else{
			answer = false;
			break;
		}
	}

	if(answer)
		cout << "YES" << nl;
	else
		cout << "NO" << nl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}