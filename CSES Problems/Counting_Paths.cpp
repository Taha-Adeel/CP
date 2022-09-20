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
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v){out << i << ' ';} return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v){in >> i;} return in;}
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

template <typename T>
class SparseTable{
	vector<vector<T>> sparse_table;
	vector<int> lg; // Precomputed values of floor(log2(i))

public:
	SparseTable(vector<T>& arr){
		int n = arr.size();

		// Precompute log values
		lg.reserve(n + 1);
		lg[1] = 0;
		for (int i = 2; i <= n; i++)
			lg[i] = lg[i/2] + 1;

		// Initialize the sparse table
		int k = lg[n] + 1;
		sparse_table = vector<vector<T>>(n, vector<T>(k));
		for(int i = 0; i < n; i++)
			sparse_table[i][0] = arr[i];
		
		// Populate the sparse table
		for(int j = 1; j < k; j++)
			for(int i = 0; i + (1 << j) <= n; i++)
				sparse_table[i][j] = min(sparse_table[i][j-1], sparse_table[i + (1 << (j - 1))][j - 1]);
	}

	T query(int l, int r){
		if(l > r) swap(l, r);
		int j = lg[r - l + 1];
		T value = min(sparse_table[l][j], sparse_table[r - (1 << j) + 1][j]);

		return value;
	}
};

struct Node{
	vi adj_list;
	int parent = -1;
	int depth = 0;
	int paths = 0;
};

V<pii> euler_order_heights; map<int, int> first_occurrence;
void dfs(int root, int parent, vector<Node>& tree){
	euler_order_heights.pb({tree[root].depth, root});
	first_occurrence[root] = euler_order_heights.size() - 1;
	tree[root].parent = parent;
	for(auto& child: tree[root].adj_list){
		if(child == parent) continue;
		tree[child].depth = tree[root].depth + 1;
		dfs(child, root, tree);
		euler_order_heights.pb({tree[root].depth, root});
	}
}

// O(1)
int lca(int a, int b, V<Node>& tree, SparseTable<pii>& st){
	return st.query(first_occurrence[a], first_occurrence[b]).second;
}

void dfs_paths(int root, int parent, vector<Node>& tree){
	for(auto& c: tree[root].adj_list){
		if(c == parent) continue;
		dfs_paths(c, root, tree);
		tree[root].paths += tree[c].paths;
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	V<Node> tree(n);
	FOR(i, n-1){
		int a, b;
		cin >> a >> b; a--, b--;
		tree[a].adj_list.pb(b);
		tree[b].adj_list.pb(a);
	}

	dfs(0, -1, tree);
	SparseTable<pii> st(euler_order_heights);

	FOR(i, m){
		int a, b;
		cin >> a >> b; a--, b--;

		int lca_ab = lca(a, b, tree, st);
		tree[a].paths += 1;
		tree[b].paths += 1;
		tree[lca_ab].paths -= 1;
		if(lca_ab != 0) tree[tree[lca_ab].parent].paths -= 1;
	}

	dfs_paths(0, -1, tree);

	FOR(i, n)
		cout << tree[i].paths << ' ';	
}

int main(){
	FAST;
	solve();
	cout << nl;
	
	return 0;
}