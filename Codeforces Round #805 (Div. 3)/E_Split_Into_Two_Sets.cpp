#include <bits/stdc++.h>
 
using namespace std;
 
#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
void display(bool answer){cout << ((answer)?"Yes":"No");}
#define pY {cout << "YES"; return;}
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
	int n;
	cin >> n;
	V<pii> v(n);
	FOR(i, n)
		cin >> v[i].F >> v[i].S;
	V<vi> indices(n+1);
	map<int, int> freqs;
	FOR(i, n){
		freqs[v[i].F]++;
		freqs[v[i].S]++;
		indices[v[i].F].pb(i);
		indices[v[i].S].pb(i);
		if(v[i].F == v[i].S)
			pN
	}
	for(auto& f: freqs){
		if(f.S > 2)
			pN
	}
	vi found(n, 0);
	vi cycle_lengths;
	FOR(i, n){
		if(found[i] == 1)
			continue;
		int cur_i = i;
		int start = v[i].F;
		int cur = start;
		int cycle_cur_len = 0;
		while(found[cur_i] == 0){
			found[cur_i] = 1;
			int other = v[cur_i].F ^ v[cur_i].S ^ cur;
			cur = other;
			cur_i = indices[other][0] ^ indices[other][1] ^ cur_i;
			cycle_cur_len++;
		}
		if(cycle_cur_len % 2)
			pN
	}
	pY
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