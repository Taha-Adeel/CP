#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
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
	ll n, x;
	cin >> n >> x;
	vi a(n);
	cin >> a;
	// a.sort_asc();
	
	map<ll, set<pii>> sum2;
	FOR(i, n){
		FOR_RANGE(j, i+1, n){
			sum2[a[i] + a[j]].insert({i, j});
		}
	}

	for(auto& s: sum2){
		ll req_sum = x - s.F;
		if(sum2.count(req_sum) == 0)
			continue;
		auto P2 = sum2[req_sum];
		for(auto& p1: s.S){
			for(auto& p2: P2){
				if(p2.F != p1.F && p2.F != p1.S && p2.S != p1.F && p2.S != p1.S){
					cout << p1.F+1 << ' ' << p1.S+1 << ' ' << p2.F+1 << ' ' << p2.S+1 << ' ';
					return;
				}
			}
		}
	}

	cout << "IMPOSSIBLE";
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}