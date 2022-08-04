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
	int N, X;
	cin >> N >> X;
	string s_by_2 = "";
	if(X > N/2 + N%2){
		cout << -1 << nl;
		return;
	}
	FOR(i, N/2){
		s_by_2 += 'a' + min(i, X-1);
	}
	if(N%2)
		s_by_2 += 'a' + min(N/2 + 1, X-1);
	
	string s = s_by_2;
	FOR(i, N/2)
		s += s_by_2[N/2 - i - 1];

	cout << s << nl; 
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}