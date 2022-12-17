#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort()			{std::sort(this->begin(), this->end());}
	void sort_dsc() 	{std::sort(this->begin(), this->end(), greater<T>());}
	auto sum() 			{T sum = 0; for(auto& i: *this) sum += i; return sum;}
	auto freqs() 		{map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	auto indices()		{int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
	auto prefix_sums() 	{int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)                for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

void solve(){
	ll n, m;
	cin >> n >> m;
	V<vi> a(n, vi(m));
	cin >> a;

	vll one_count(n);
	FOR(i, n)
		one_count[i] = count(all(a[i]), 1LL);
	ll total_ones = one_count.sum(), avg_ones = total_ones/n;
	if(total_ones%n){
		cout << -1 << nl;
		return;
	}
	
	V<tuple<int, int, int>> ops;
	FOR(z, m){
		queue<int> excess, deficit;
		FOR(i, n){
			if(a[i][z] == 1 && one_count[i] > avg_ones)
				excess.push(i);
			else if(a[i][z] == 0 && one_count[i] < avg_ones)
				deficit.push(i);
		}
		while(!excess.empty() && !deficit.empty()){
			int x = excess.front(); excess.pop();
			int y = deficit.front(); deficit.pop();
			one_count[x]--; one_count[y]++;
			ops.push_back({x+1, y+1, z+1});
		}
	}

	cout << ops.size() << nl;
	for(auto& [x, y, z]: ops)
		cout << x << ' ' << y << ' ' << z << nl;
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		solve();
	}
	
	return 0;
}