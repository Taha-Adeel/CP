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

bool sums_to(int a, int x, v_i freqs){
	v_i freqs_copy = freqs;
	if(x < 0)
		return false;
	freqs_copy[a]--;
	int b = 0;
	int c = x - b;

	for(b = 0; b < 10; b++){
		c = x - b;
		if(c > 9 || c < 0)
			continue;
		if(c == b && freqs_copy[b] >= 2)
			return true;
		else if(c != b && freqs_copy[b] > 0 && freqs_copy[c] > 0)
			return true;
	}

	return false;
}

void solve(){
	int n;
	cin >> n;
	v_i a(n);
	cin >> a;

	v_i freqs(10, 0);
	FOR(i, n)
		freqs[a[i]%10]++;

	bool answer = false;
	for(int a = 0; a < 10; a++)
		if(freqs[a] > 0 && sums_to(a, 3 - a, freqs))
			answer = true;
	
	for(int a = 0; a < 10; a++)
		if(freqs[a] > 0 && sums_to(a, 13 - a, freqs))
			answer = true;
	
	for(int a = 0; a < 10; a++)
		if(freqs[a] > 0 && sums_to(a, 23 - a, freqs))
			answer = true;
	

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