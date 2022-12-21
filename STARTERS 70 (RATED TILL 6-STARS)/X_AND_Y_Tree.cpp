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
	int val = 0;
	vi adj_list;

	int parent = -1;
	int child_count = 0;
	int val_1_child_count = 0;
};

void dfs(int cur_node, V<Node>& tree){
	auto& cur = tree[cur_node];
	for(auto& child: cur.adj_list){
		if(child == cur.parent) continue;
		tree[child].parent = cur_node;
		dfs(child, tree);
		cur.child_count++;
	}
}

void solve(){
	int n;
	cin >> n;
	V<Node> tree(n);
	FOR(i, n-1){
		int u, v;
		cin >> u >> v; u--, v--;
		tree[u].adj_list.pb(v);
		tree[v].adj_list.pb(u);
	}

	dfs(0, tree);

	int good_edges = n-1;
	int q;
	cin >> q;
	FOR(i, q){
		int t;
		cin >> t;
		if(t == 1){
			int u;
			cin >> u; u--;

			if(tree[u].val == 1) continue;
			if(tree[u].val_1_child_count == tree[u].child_count)
				tree[u].val = 1,
				good_edges--;
			if(tree[u].parent != -1 && tree[u].val == 1)
				tree[tree[u].parent].val_1_child_count++;
			if(good_edges == -1) good_edges = n-1;
		}
		else
			cout << good_edges << nl;
	}
}

int main(){
	int T;
	cin >> T;
	FOR(t, T){
		solve();
	}
	
	return 0;
}