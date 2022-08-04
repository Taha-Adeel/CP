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

// Incorrect soln, see gauthams sol
void solve(int x, int T){
	int n;
	cin >> n;
 
	string s, t;
	cin >> s >> t;
	
	// if(T== 10000 && x != 172)
	// 	return;
	bool yes = true;
	v_i count_s(3, 0), count_t(3, 0);
	FOR(i, n){
		count_s[s[i] - 'a']++;
		count_t[t[i] - 'a']++;
	}
	FOR(i, 3)
		if(count_s[i] != count_t[i])
			yes = false;
 
	v_i c_after(n+1, 0), a_before(n+1, 0);
	FOR(i, n){
		if(s[i] == 'b')
			a_before[i+1] = a_before[i];
		else if(s[i] == 'a')
			a_before[i+1] = a_before[i] + 1;
		else if(s[i] == 'c')
			a_before[i+1] = 0;
	}
	for(int i = n-1; i >= 0; i--){
		if(s[i] == 'b')
			c_after[i] = c_after[i+1];
		else if(s[i] == 'c')
			c_after[i] = c_after[i+1] + 1;
		else if(s[i] == 'a')
			c_after[i] = 0;
	}
 
	FOR(i, n){
		if(t[i] == 'a'){
			if(--a_before[i+1] < 0)
				yes = false;
		}
		else if(t[i] == 'c'){
			if(--c_after[i] < 0)
				yes = false;
		}
	}	
	// if(T == 10000)
	// 	cout << s << nl << t << nl;
	if(yes)
		cout << "YES" << nl;
	else
		cout << "NO" << nl;
}

int main(){
	int T;
	cin >> T;
	FOR(i, T){
		solve(i, T);
	}
	
	return 0;
}