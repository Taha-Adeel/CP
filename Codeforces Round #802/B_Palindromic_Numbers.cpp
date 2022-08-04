#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};

#define FOR(i, n)                for(int i = 0; i < n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = n-1; i >= 0; --i)

#define F  first
#define S  second
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll   = long long int;
using p_ii = pair<int,int>;
using p_ll = pair<ll,ll>;
using vi   = V<int>;
using vll  = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/
string subtract(string c, string a){
	stack<char> b_rev;
	string b;
	while(c.length() > a.length()){
		a = '0' + a;
	}
	FOR_REV(i, c.length()){
		int c_dig = c[i] - '0';
		int a_dig = a[i] - '0';
		if(a_dig > c_dig){
			c_dig += 10;
			int carry_over_i = i-1;
			while(c[carry_over_i] == 0)
				c[carry_over_i--] = '9';
			c[carry_over_i]--;
		}
		int b_dig = c_dig - a_dig;
		b_rev.push('0'+b_dig);
	}

	bool removed_zeros = false;
	while(!removed_zeros){
		if(b_rev.top() != '0')
			removed_zeros = true;
		else
			b_rev.pop();
	}
	while(!b_rev.empty()){
		b += b_rev.top();
		b_rev.pop();
	}

	return b;
}

void solve(){
	int n;
	cin >> n;
	string a;
	cin >> a;

	if(a[0] != '9')
		cout << subtract(string(n, '9'), a);
	else{
		string c(n+1, '0');
		c[0] = '1';
		if(n != 1){
			c[1] = '8';
			c[n - 1] = '8';
		}
		c[n] = '1';

		cout << subtract(c, a);
	}
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}