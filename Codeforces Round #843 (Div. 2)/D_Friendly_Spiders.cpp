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

vi get_prime_factors(int n){
	vi ans;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
			ans.pb(i);
			while(n%i == 0)
				n /= i;
		}
	}
	if(n != 1) ans.pb(n);
	return ans;
}

struct Node{
	int val;
	bool visited = false;
	int parent = -1;
	set<int> adj_list;
};

void solve(){
	int n;
	cin >> n;
	vi a(n);
	cin >> a;
	int s, t;
	cin >> s >> t; s--, t--;

	if(s == t){
		cout << 1 << nl;
		cout << s+1 << nl;
		return;
	}
	else if(gcd(a[s], a[t]) != 1){
		cout << 2 << nl;
		cout << s+1 << ' ' << t+1 << nl;
		return;
	}

	vi primes_s = get_prime_factors(a[s]), primes_t = get_prime_factors(a[t]);
	vi primes_st = primes_s; for(auto& p: primes_t) primes_st.pb(p);

	map<int, Node> graph;
	vi path;

	

	cout << path.size() << nl;
	cout << path;
}

int main(){
	FAST;
	int T = 1;
	FOR(t, T){
		solve();
	}
	
	return 0;
}