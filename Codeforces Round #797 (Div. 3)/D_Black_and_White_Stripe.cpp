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

int is_W(char c){
	if(c == 'W')
		return 1;
	return 0;
}

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	int num_of_whites = 0;
	FOR(i, k){
		if(s[i] == 'W')
			num_of_whites++;
	}

	int min_whites = num_of_whites;
	for(int i = 0; i + k < n; i++){
		num_of_whites = num_of_whites - is_W(s[i]) + is_W(s[i + k]);
		if(num_of_whites < min_whites)
			min_whites = num_of_whites;
	}
	cout << min_whites << nl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}