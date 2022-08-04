#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
void display(bool answer){cout << ((answer)?"Yes":"No");}
#define pY {cout << "Yes"; return;}
#define pN {cout << "No";  return;}

#define FOR(i, n)                for(int i = 0; i < n; ++i)
#define FOR1(i, n)               for(int i = 1; i < n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = n-1; i >= 0; --i)

#define F  first
#define S  second
#define pb push_back
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	ll N;
	cin >> N;
	vll A(2*N);
	cin >> A;
	
	vi e_ops, o_ops;
	FOR(i, 2*N){
		if(A[i]%2 == 1)
			o_ops.pb(A[i]);
		int ops = 0;
		while(A[i]%2 == 0){
			ops++;
			A[i] /= 2;
		}
		if(ops != 0)
			e_ops.pb(ops);
	}
	if(o_ops.size() >= N)
		cout << o_ops.size() - N;
	else{
		e_ops.sort_asc();
		ll ans = 0;
		FOR(i, e_ops.size() - N){
			ans += e_ops[i];
		}
		cout << ans;
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