#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
};
void display(bool answer){cout << ((answer)?"Yes":"No");}
#define pY {cout << "YES" << nl;}
#define pN {cout << "NO";  return;}

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
	ll n, k;
	cin >> n >> k;

	map<ll, ll> freq_addn;
	ll mask = 1;
	while(mask <= n){
		if((n&mask) != 0)
			freq_addn[mask]++;
		mask <<= 1;
	}
	if(freq_addn.size() > k || k > n)
		pN

	ll cur_addns = freq_addn.size();
	ll cur_pow_2 = freq_addn.rbegin()->first;
	while(cur_pow_2 != 1 && cur_addns + freq_addn[cur_pow_2] < k){
		cur_addns += freq_addn[cur_pow_2];
		freq_addn[cur_pow_2/2] += 2*freq_addn[cur_pow_2];
		freq_addn[cur_pow_2] = 0;
		cur_pow_2 >>= 1;
	}
	if(cur_pow_2 != 1){
		freq_addn[cur_pow_2/2] += 2*(k - cur_addns);
		freq_addn[cur_pow_2] -= k - cur_addns;
		cur_addns = k;
	}

	if(cur_addns != k)
		pN
	else{
		pY
		for(auto& i: freq_addn){
			while(i.S-- > 0)
				cout << i.F << ' ';
		}
	}
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}