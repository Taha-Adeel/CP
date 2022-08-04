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
	int n, m, k;
	cin >> n >> m >> k;
	string a, b, c = "";
	cin >> a >> b;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int a_i = 0, b_i = 0;
	bool a_curr = true;
	int cur_reps = 0;
	while(a_i < n && b_i < m){
		if(a_curr){
			if(a[a_i] < b[b_i] && cur_reps < k){
				c += a[a_i];
				a_i++;
				cur_reps++;
			}
			else if(b[b_i] < a[a_i] || cur_reps == k){
				c += b[b_i];
				a_curr = false;
				cur_reps = 1;
				b_i++;
			}
		}
		else{
			if(b[b_i] < a[a_i] && cur_reps < k){
				c += b[b_i];
				b_i++;
				cur_reps++;
			}
			else if(a[a_i] < b[b_i] || cur_reps == k){
				c += a[a_i];
				a_curr = true;
				cur_reps = 1;
				a_i++;
			}
		}
	}
	cout << c << nl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}