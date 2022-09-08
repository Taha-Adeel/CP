#include <bits/stdc++.h>
using namespace std;

#define V vector
using vi = V<int>;
using pii = pair<int, int>;
#define FOR(i, n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define all(v) v.begin(), v.end()


// struct Node{
// 	int depth = 0;
// 	vi superior;
// 	vi adj_list;
// };

// // O(n+m log n)
// void dfs(int root, V<Node>& tree){
// 	for(auto& child: tree[root].adj_list){
// 		if(root != 0 && child == tree[root].superior[0]) continue;

// 		tree[child].depth = tree[root].depth + 1;
// 		tree[child].superior.pb(root);
// 		for(int k = 1; (1<<k) <= tree[child].depth; k++)
// 			tree[child].superior.pb(tree[tree[child].superior[k-1]].superior[k-1]);
		
// 		dfs(child, tree);
// 	}
// }

// // O(log k)
// int get_kth_ancestor(int x, int k, V<Node>& tree){
// 	if(k == -1) return x;
// 	if(k >= tree[x].depth) return -1;
// 	int ancestor = tree[x].superior[0];
// 	for(int mask = 0; (1<<mask) <= k; mask++)
// 		if((1<<mask) & k)
// 			ancestor = tree[ancestor].superior[mask];
	
// 	return ancestor;
// }

// // O(log2 n)
// int lca(int a, int b, V<Node>& tree){
// 	int ad = tree[a].depth, bd = tree[b].depth;
// 	if(ad > bd) swap(a, b), swap(ad, bd);
// 	b = get_kth_ancestor(b, bd - ad - 1, tree); bd = ad;
// 	if(a == b) return a;

// 	int l = 0, r = ad;
// 	while(l < r){
// 		int m = (l+r)/2;
// 		if(get_kth_ancestor(a, m, tree) == get_kth_ancestor(b, m, tree))
// 			r = m;
// 		else
// 			l = m + 1;		
// 	}

// 	return get_kth_ancestor(a, l, tree);
// }


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