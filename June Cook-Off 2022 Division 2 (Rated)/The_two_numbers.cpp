#include <bits/stdc++.h>

using namespace std;

#define FAST 		ios::sync_with_stdio(0); cin.tie(0)
#define FOR(a,c) 	for (int a=0; a<c; ++a)
#define all(v) 		v.begin(), v.end()
template<class T> struct v: vector<T>{
	using vector<T>::vector;
	void sort() {sort(all(*this));}
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
using v_i  = v<int>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve(){
	ll N;
	cin >> N;

	ll f_max = 0;
	for(ll i = N/2; i > 0; i--){
		ll gcd_i = gcd(i, N - i);
		ll lcm_i = (i * (N - i))/gcd_i;

		if(lcm_i - gcd_i > f_max)
			f_max = lcm_i - gcd_i;
		if(gcd_i == 1)
			break;
	}
	cout << f_max << nl; 
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}