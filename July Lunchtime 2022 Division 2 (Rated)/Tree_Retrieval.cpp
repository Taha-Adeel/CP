#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort()     {std::sort(this->begin(), this->end());}
	void sort_dsc() {std::sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<this->size(); i++) index[this->at(i)].push_back(i); return index;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()

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

bool solve(){
	int N;
	cin >> N;

	set<int> S;
	FOR1(i, N)
		S.insert(i);
	
	vi path;

	int cur_leaf, other_leaf;
	while(S.size() > 1){
		cout << '?' << ' ' << S.size() << ' ';
		for(auto& s: S)
			cout << s << ' ';
		cout << endl;
		int a, b;
		cin >> a >> b;
		if(path.size() == 0){
			cur_leaf = a;
			other_leaf = b - a;
		}
		else{
			if(a == other_leaf)
				cur_leaf = b - a;
			else
				cur_leaf = a;
		}
		path.pb(cur_leaf);
		S.erase(cur_leaf);
	}
	path.pb(*S.begin());

	cout << '!' << nl;
	FOR(i, N-1)
		cout << path[i] << ' ' << path[i+1] << endl; 
	
	int ok;
	cin >> ok;

	return ok == 1;
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		if(!solve())
			break;
		cout << endl;
	}
	
	return 0;
}