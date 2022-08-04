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
	int n, s;
	cin >> n >> s;
	v_i a(n);
	cin >> a;

	int sum = 0;
	FOR(i, n)
		sum += a[i];

	if(sum < s){
		cout << -1 << nl;
		return;
	}

	int answer = INT_MAX;
	int l = n - 1, r = n;
	while(l >= 0){
		if(s >= 0){
			s -= a[l];
			l--;
		}
		if(s < 0){
			r--;
			s += a[r];
		}
		if(s == 0)
			answer = min(answer, (l + 1) + (n - r));
	}

	if (answer < INT_MAX)
		cout << answer << nl;
	else
		cout << -1 << nl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}