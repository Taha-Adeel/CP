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
bool isPalindrome(string s){
	for(int i = 0; i <= s.size()/2; i++){
		if(s[i] != s[s.size() - i - 1])
			return false;
	}
	return true;
}

void inc_time(string& t, int x){
	int min = atoi((t.substr(3, 2)).c_str());
	int hour = atoi((t.substr(0, 2)).c_str());
	min += x%60;
	hour += x/60 + min/60;
	min %= 60;
	hour %= 24;

	string hour_s, min_s;
	if(hour < 10)
		hour_s = "0" + to_string(hour);
	else
		hour_s = to_string(hour);
	if(min < 10)
		min_s = "0" + to_string(min);
	else
		min_s = to_string(min);
		
	t = hour_s + ":" + min_s;
}

void solve(){
	string t;
	int x;
	cin >> t >> x;
	string t_start = t;
	ll answer = 0;
	do{
		if(isPalindrome(t))
			answer++;
		inc_time(t, x);
	}while(t.compare(t_start) != 0);

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