#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort_asc() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	vector<int> indices() {vector<int> index(this->size()+2); for(int i=0; i<this->size(); i++) index[this->at(i)] = i+1; return index;}
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
	int n, m;
	cin >> n >> m;
	vi a(n);
	cin >> a;
	
	ll ans = 1;
	auto index = a.indices();
	index[0] = 0;
	index[n+1] = n+1;
	FOR1(i, n+1){
		if(index[i] > index[i+1])
			ans++;
	}
	set<pii> change;
	auto add = [&](int i){
		change.insert({a[i] - 1, a[i]});
		change.insert({a[i], a[i] + 1});
	};

	FOR(i, m){
		int x, y;
		cin >> x >> y; x--, y--;
		add(x); add(y);
		
		for(auto& c: change)
			ans -= index[c.S] < index[c.F];
		
		swap(index[a[x]], index[a[y]]);
		swap(a[x], a[y]);

		for(auto& c: change)
			ans += index[c.S] < index[c.F];
		
		cout << ans << nl;
		change.clear();
	}
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}