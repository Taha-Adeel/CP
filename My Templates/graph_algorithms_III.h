#include <bits/stdc++.h>
using namespace std;

#define V vector
#define F first
#define S second
using ll = long long;
using vi = V<int>;
using vll = V<ll>;
using pii = pair<int, int>;
#define FOR(i, n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define all(v) v.begin(), v.end()

struct Node{
	bool visited = false;
	int component = -1;
	int parent = -1;
	int set_size = 1;
	vi adj_list;
};

// Kruskals algorithm to get MST in O(mlogn)
ll kruskals_algo(V<Node>& graph, V<tuple<int, int, int>>& edges){
	auto ds = [&](int a){
		while(graph[a].parent != -1)
			a = graph[a].parent;
		return a;
	};
	auto merge = [&](int a, int b){
		int ds_a = ds(a), ds_b = ds(b);
		if(graph[ds_a].set_size < graph[ds_b].set_size) swap(a, b), swap(ds_a, ds_b);

		graph[ds_a].set_size += graph[ds_b].set_size;
		graph[ds_b].parent = ds_a;
	};

	sort(all(edges));
	ll min_cost = 0, edges_used = 0;
	for(auto& [c, a, b]: edges){
		if(ds(a) != ds(b)){
			min_cost += c;
			edges_used++;
			merge(a, b);
		}
	}
	if(edges_used != (int)graph.size()-1)
		return -1;

	return min_cost;
}


// Kosaraju's algorithm to find strongly connected components in O(n+m);
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

struct CondensedNode{
	vi nodes;
	set<int> adj_list;
};

// Replaces the SCCs with a single condensed node.
V<CondensedNode> condense(V<Node>& graph){
	kosaraju_algo(graph); // Get the SCCs
	
	int num_of_scc = 0;
	for(auto& node: graph) 
		num_of_scc = max(num_of_scc, node.component);

	V<CondensedNode> condensed_graph(num_of_scc);
	FOR(i, graph.size()){
		condensed_graph[graph[i].component - 1].nodes.pb(i);
		for(auto& v: graph[i].adj_list)
			if(graph[v].component != graph[i].component)
				condensed_graph[graph[i].component-1].adj_list.insert(graph[v].component-1);
	}

	return condensed_graph;
}