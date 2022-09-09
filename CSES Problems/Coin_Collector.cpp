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

struct Node{
	int val;
	int component = -1;
	bool visited = false;
	vi adj_list;
};

// Get the "structure"(Nodes in increasing order of finished processing order)
void dfs1(int root, V<Node>& graph, stack<int>& structure){
	graph[root].visited = true;
	for(auto& child: graph[root].adj_list)
		if(!graph[child].visited)
			dfs1(child, graph, structure);

	structure.push(root);
}

// Generates the SCCs
void dfs2(int root, V<Node>& graph, int component){
	graph[root].component = component;
	for(auto& c: graph[root].adj_list)
		if(graph[c].component == -1)
			dfs2(c, graph, component);
}

// Reverses all edges in the graph
void reverse(V<Node>& graph){
	int n = graph.size();
	V<Node> reversed_graph = graph;
	FOR(i, n) reversed_graph[i].adj_list.clear();
	FOR(u, n)
		for(auto& v: graph[u].adj_list)
			reversed_graph[v].adj_list.pb(u);
	graph = reversed_graph;
}

// Kosaraju's algorithm to find strongly connected components in O(n+m);
void kosaraju_algo(V<Node>& graph){
	int n = graph.size();
	stack<int> structure;
	FOR(i, n)
		if(!graph[i].visited)
			dfs1(i, graph, structure);

	reverse(graph);
	int num_of_scc = 0;
	while(!structure.empty()){
		int top = structure.top(); structure.pop();
		if(graph[top].component == -1)
			dfs2(top, graph, ++num_of_scc);
	}
	reverse(graph);
}

#define INF 1e18
struct CondensedNode{
	ll neg_val = 0;
	vi nodes;
	set<int> adj_list;
	ll dist = INF;
};

// Replaces the SCCs with a single condensed node.
V<CondensedNode> condense(V<Node>& graph){
	int num_of_scc = 0;
	for(auto& node: graph) 
		num_of_scc = max(num_of_scc, node.component);

	V<CondensedNode> condensed_graph(num_of_scc);
	FOR(i, graph.size()){
		condensed_graph[graph[i].component - 1].nodes.pb(i);
		condensed_graph[graph[i].component - 1].neg_val -= graph[i].val;
		for(auto& v: graph[i].adj_list)
			if(graph[v].component != graph[i].component)
				condensed_graph[graph[i].component-1].adj_list.insert(graph[v].component-1);
	}

	return condensed_graph;
}

// Shortest Path First Algorithm (SPFA), which is a further optimization of Bellman-Ford. Average case time is better. Worst case = O(nm)
void calc_dists_spfa(int root, V<CondensedNode>& graph){
	graph[root].dist = 0;
	deque<int> q; // Use priority queue for better time complexity(Almost similar to Dijkstra's)
	V<bool> in_q(graph.size(), false);
	q.push_back(root); in_q[root] = true;
	while(!q.empty()){
		int u = q.front(); q.pop_front(); in_q[u] = false;
		for(auto& v: graph[u].adj_list){
			ll w = graph[v].neg_val;
			if(graph[u].dist + w < graph[v].dist){
				graph[v].dist = graph[u].dist + w;
				if(!in_q[v]){
					// Smallest Lable First Optimiztion
					if(graph[v].dist < graph[q.front()].dist)
						q.push_front(v), in_q[v] = true;
					else
						q.push_back(v), in_q[v] = true;
				}
			}
		}
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	V<Node> graph(n);
	FOR(i, n) cin >> graph[i].val;

	FOR(i, m){
		int a, b;
		cin >> a >> b; a--, b--;
		graph[a].adj_list.pb(b);
	}

	// We connect all SCCs to make a DAG
	kosaraju_algo(graph);
	auto condensed_graph = condense(graph);

	// We insert a dummy start node from which we can traverse to any room
	CondensedNode dummy_start_node;
	FOR(i, condensed_graph.size())
		dummy_start_node.adj_list.insert(i);
	condensed_graph.pb(dummy_start_node);

	// We find the longest path by finding the shortest path with all weights made negative
	calc_dists_spfa(condensed_graph.size() - 1, condensed_graph);

	ll max_val_sum = 0;
	for(auto& x: condensed_graph)
		max_val_sum = min(max_val_sum, x.dist);
	max_val_sum *= -1;

	cout << max_val_sum;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}