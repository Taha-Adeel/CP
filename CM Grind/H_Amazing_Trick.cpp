#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort()			{std::sort(this->begin(), this->end());}
	void sort_dsc() 	{std::sort(this->begin(), this->end(), greater<T>());}
	auto sum() 			{T sum = 0; for(auto& i: *this) sum += i; return sum;}
	auto freqs() 		{map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	auto indices()		{int n=this->size(); map<T, int> ii; for(int i=0; i<n; i++) ii[(*this)[i]] = i; return ii;}
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
	int n;
	cin >> n;
	vi a(n);
	cin >> a;

	vi p(n), q(n);
	FOR(i, n)
		p[a[i]-1] = i+1;
	FOR(i, n)
		q[i] = i+1;
	if(n == 1){
		cout << "Impossible" << nl;
		return;
	}
	else if(n == 3){
		map<vi, pair<vi, vi>> ans;
		ans[{1,2,3}] = {{2,3,1},{3,1,2}};
		ans[{2,3,1}] = {{3,1,2},{3,1,2}};
		ans[{3,1,2}] = {{2,3,1},{2,3,1}};
		if(ans.count(p))
			cout << "Possible" << nl << ans[p].F << nl << ans[p].S << nl;
		else
			cout << "Impossible" << nl;
		return;
	}

	
	FOR(i, n/2)
		swap(p[2*i], p[2*i+1]),
		swap(q[2*i], q[2*i+1]);
	if(n%2)
		swap(p[n-2], p[n-1]),
		swap(q[n-3], q[n-1]);

	vi index_q(n);
	FOR(i, n)
		index_q[q[i]-1] = i;

	FOR(i, n){
		if(p[i] == i+1){
			for(int j = (i+1)%n; j != i; j = (j+1)%n){
				if(index_q[i] != j && index_q[j] != i){
					swap(p[i], p[j]);
					swap(q[index_q[i]], q[index_q[j]]);
					swap(index_q[i], index_q[j]);
					break;
				}
			}
		}
	}
	bool good = true;
	FOR(i, n) good &= (p[i] != i+1 && q[i] != i+1);
	if(good)
		cout << "Possible" << nl << p << nl << q << nl;
	else
		cout << "Impossible" << nl;
}

int main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve();
	}
	
	return 0;
}