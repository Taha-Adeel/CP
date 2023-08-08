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
constexpr int MOD = 998244353;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

struct Node{
	int parent = -1;
	int subtree_sz = 1;
	set<pii> adj;
};

void dfs(int root, V<Node>& tree){
	for(auto& [child, w]: tree[root].adj){
		if(child == tree[root].parent) continue;
		tree[child].parent = root;
		dfs(child, tree);
		tree[root].subtree_sz += tree[child].subtree_sz;
	}
}


void solve(){
	ll n, s; cin >> n >> s;
	V<Node> tree(n);
	V<tuple<int, int, int>> edges(n-1);
	FOR(i, n-1){
		int u, v, w; cin >> u >> v >> w;
		u--; v--;
		tree[u].adj.insert({v, w});
		tree[v].adj.insert({u, w});
		edges[i] = {w, u, v};
	}

	dfs(0, tree);

	edges.sort_dsc();
	ll ans = 1;

	for(auto& [w, u, v]: edges){
		if(v == tree[u].parent) 
			swap(u, v); // u is the parent of v
		
		ll v_sz = 0;
		for(auto& [child, w]: tree[v].adj){
			if(child == tree[v].parent) continue;
			v_sz += tree[child].subtree_sz;
		}

		ll u_sz = 0;
		for(auto& [child, w]: tree[u].adj){
			if(child == v) continue;
			if(child == tree[u].parent){
				// Compute number of nodes from parent edge
			}
			else
				u_sz += tree[child].subtree_sz;
		}

		// Delete the edge from u to v
		tree[u].adj.erase({v, w});
		tree[v].adj.erase({u, w});
		tree[u].subtree_sz -= v_sz;

		ans += (u_sz * v_sz * (s - w)) % MOD;
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