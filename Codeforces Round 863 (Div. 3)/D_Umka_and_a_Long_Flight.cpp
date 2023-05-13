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

#define f  first
#define s  second
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

vll F(50); 
vector<set<ll>> xs(45), ys(45);

void solve(){
	int n, x, y;
	cin >> n >> x >> y;

	if(n%2 == 0){
		if(xs[n].count(x-1) && ys[n].count(y-1)) pY
		else pN
	}
	else{
		if(ys[n].count(x-1) && xs[n].count(y-1)) pY
		else pN
	}
}

int main(){
	F = vll(50);
	F[0] = 1; F[1] = 1;
	for(int i = 2; i < 50; i++) F[i] = F[i-1] + F[i - 2];

	xs[0].insert(0); ys[0].insert(0);
	for(int i = 1; i < 24; i++){
		xs[i] = xs[i-1];
		for(int j = 1; j <= i; j += 2)
			for(auto& x: xs[j-1])
				xs[i].insert(x + F[j]);

		ys[i] = ys[i-1];
		for(int j = 2; j <= i; j += 2)
			for(auto& y: ys[j-1])
				ys[i].insert(y + F[j]);
	}

	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}