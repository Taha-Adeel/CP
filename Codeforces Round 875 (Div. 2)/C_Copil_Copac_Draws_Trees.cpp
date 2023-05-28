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

struct Node{
	V<pii> adj; // {v, index of edge u-v}
	int reading = -1; // Step in which the node is drawn
	int drawn_edge_index = -1; // Index of the edge that connects the node to its parent
};

void solve(){
	int n; cin >> n;
	V<Node> tree(n);
	FOR(i, n-1){
		int u, v; cin >> u >> v; u--, v--;
		tree[u].adj.pb({v, i});
		tree[v].adj.pb({u, i});
	}

	queue<int> outer_most; // The current leaves of the drawn tree
	outer_most.push(0);
	int ans = 0;
	tree[0].reading = 0;
	
	while(!outer_most.empty()){
		int u = outer_most.front(); outer_most.pop();
		int reading = tree[u].reading, drawn_edge_index = tree[u].drawn_edge_index;
		ans = max(ans, reading);
		for(auto& [v, e]: tree[u].adj){
			if(tree[v].reading != -1) continue;
			if(e > drawn_edge_index) tree[v].reading = reading;
			else tree[v].reading = reading+1;
			tree[v].drawn_edge_index = e;
			outer_most.push(v);
		}
	}

	cout << ans+1;
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