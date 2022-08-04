#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
void display(bool answer){cout << ((answer)?"Yes":"No");}

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

void solve(){
	ll n;
	cin >> n;

	if(n % 4 == 1 || n % 4 == 2){
		cout << "NO";
		return;
	}

	vll A, B;
	ll sum = (n * (n+1))/4;
	ll cur_sum = 0;

	FOR_REV(i, n){
		if(cur_sum + (i+1) <= sum){
			cur_sum += i + 1;
			A.push_back(i + 1);
		}
		else
			B.push_back(i + 1);
	}
	cout << "YES" << nl;
	cout << A.size() << nl;
	cout << A << nl;
	cout << B.size() << nl;
	cout << B;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}