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
// f(ab[1] != ab[0]){
// 		FOR(i, n){
// 			if(a[i] == ab[0] || b[i] == ab[0]){
// 				if(a[i] == ab[1] || b[i] == ab[1]) cout << ab[0] - ab[2];
// 				else cout << ab[0] - ab[1];
// 				return;
// 			}
// 		}
// 	}
// 	else{
// 		FOR(i, n){
// 			if(a[i] == ab[0] || b[i] == ab[0]){
// 				if(a[i] == ab[1] && b[i] == ab[1]) cout << ab[0] - ab[2];
// 				else cout << ab[0] - ab[1];
// 				return;
// 			}
// 		}
// 	}
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

bool dif_indices(map<int, vi>& indices, int x, int y){
	for(auto& i: indices[x]) 
		for(auto& j: indices[y]) 
			if(i != j) return true;
	return false;
}

void solve(){
	int n; cin >> n;
	vi a(n), b(n); FOR(i, n) cin >> a[i] >> b[i];

	map<int, vi> indices; FOR(i, n) indices[a[i]].pb(i), indices[b[i]].pb(i);

	vi ab = a; ab.insert(ab.end(), all(b));
	ab.sort();

	int min_bigger = 0;
	FOR(i, n) min_bigger = max(min_bigger, min(a[i], b[i]));

	int min_bigger_count = 0;
	FOR(i, n) if(min_bigger == a[i] || min_bigger == b[i]) min_bigger_count++;

	if(min_bigger_count > 1) cout << 0;
	else{
		int i = 0;
		while(i < 2*n && ab[i] < min_bigger) i++;
		int ans = INT_MAX;
		FOR(j, i) if(dif_indices(indices, ab[j], min_bigger)) ans = min(ans, min_bigger - ab[j]);
		while(i < 2*n) {
			if(dif_indices(indices, ab[i], ab[i-1])) ans = min(ans, ab[i] - ab[i-1]);
			else ans = min(ans, ab[i] - ab[i-2]);
			i++;
		}
		cout << ans;
	}
}

int main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}