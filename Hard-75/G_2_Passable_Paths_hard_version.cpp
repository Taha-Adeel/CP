#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()        { std::sort(this->begin(), this->end()); }
    void sort_dsc()    { std::sort(this->begin(), this->end(), greater<T>()); }
    auto sum()         { T sum = 0; for(auto& i: *this) sum += i; return sum; }
    auto freqs()       { map<T, int> freq; for(auto& i: *this) freq[i]++; return freq; }
    auto indices()     { int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii; }
    auto prefix_sums() { int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps; }
    friend ostream& operator<<(ostream& out, const V<T>& v) { for(auto& i: v) out << i << ' '; return out; }
    friend istream& operator>>(istream& in, V<T>& v)        { for(auto& i: v) in >> i; return in; }
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)     for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)    for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)     for(int i = (int)n-1; i >= 0; --i)
#define all(v)        v.begin(), v.end()
#define pb push_back

constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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
	int depth = 0;
	int parent = -1;
	vi adj_list;
};

// O(n)
V<pii> euler_order_heights; map<int, int> first_occurrence;
void dfs(int root, vector<Node>& tree){
	euler_order_heights.pb({tree[root].depth, root});
	first_occurrence[root] = euler_order_heights.size() - 1;
	for(auto& child: tree[root].adj_list){
		if(child == tree[root].parent) continue;
		tree[child].depth = tree[root].depth + 1;
		tree[child].parent = root;
		dfs(child, tree);
		euler_order_heights.pb({tree[root].depth, root});
	}
}

// O(1)
int lca(int a, int b, V<Node>& tree, SparseTable<pii>& st){
	return st.query(first_occurrence[a], first_occurrence[b]).second;
}

void solve() {
    int n; cin >> n;
    V<Node> tree(n);
    FOR(i, n-1){
    	int u, v; cin >> u >> v; --u, --v;
    	tree[u].adj_list.pb(v);
    	tree[v].adj_list.pb(u);
    }

    dfs(0, tree);
    SparseTable<pii> st(euler_order_heights);

    int q; cin >> q;
    while(q--){
    	int k; cin >> k;
        vi nodes(k); cin >> nodes;
        for(auto& node: nodes) --node;

        auto dist = [&](int a, int b){
        	return tree[a].depth + tree[b].depth - 2 * tree[lca(a, b, tree, st)].depth;
        };

        int u = 0; // One end point
        for(auto& node: nodes) {
        	if(tree[node].depth > tree[u].depth)
        		u = node;
        }
        
        int v = u; // Other end point
        for(auto& node: nodes) {
        	if(dist(node, u) > dist(v, u))
        		v = node;
        }

        bool ok = true;
        for(auto& x: nodes){
        	if(dist(u, x) + dist(v, x) != dist(u, v)){
        		ok = false;
        		break;
        	}
        }

        if(ok) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
}

int main() {
    FAST;
    solve();
    
    return 0;
}