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

#define INF 1e15
template <int N> using arr = array<int, N>;

struct Node{
	int val;
	bool visited = false;
	int parent = -1;
	int set_size = 1;
	ll dist = INF;
	V<pii> adj_list;
};

V<tuple<int, int, int>> get_edge_list(const V<Node>& graph){
	V<tuple<int, int, int>> edges; // List of all edges
	FOR(i, graph.size())
		for(auto& edge: graph[i].adj_list)
			edges.pb({i, edge.F, edge.S});
	
	return edges;
}

// Bellman-Ford algorithm to find shortest point from the root to all points in a weighted graph(with no negative cycles) in O(nm).
void calc_dists_bf_unoptimized(int root, V<Node>& graph){
	auto edges = get_edge_list(graph);
	
	graph[root].dist = 0;
	FOR(i, graph.size()){
		for(auto& [u, v, w]: edges)
			graph[v].dist = min(graph[v].dist, graph[u].dist + w);
	}
}

// Optimized Bellman-Ford algorithm to find shortest point from the root to all points in a weighted graph(with no negative cycles) in O(nm).
void calc_dists_bf(int root, V<Node>& graph){
	auto edges = get_edge_list(graph);

	graph[root].dist = 0;
	FOR(i, graph.size()){
		bool final = true;
		for(auto& [u, v, w]: edges){
			if(graph[u].dist + w < graph[v].dist){
				graph[v].dist = graph[u].dist + w;
				final = false;
			}
		}
		if(final) break;
	}
}

// Shortest Path First Algorithm (SPFA), which is a further optimization of Bellman-Ford. Average case time is better. Worst case = O(nm)
void calc_dists_spfa(int root, V<Node>& graph){
	graph[root].dist = 0;
	deque<int> q; // Use priority queue for better time complexity(Almost similar to Dijkstra's)
	V<bool> in_q(graph.size(), false);
	q.push_back(root); in_q[root] = true;
	while(!q.empty()){
		int u = q.front(); q.pop_front(); in_q[u] = false;
		for(auto& e: graph[u].adj_list){
			int v = e.F, w = e.S;
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

// Dijkstra's algorithm to find shortest paths from the starting node to all nodes of a weighted graph with positive weights in O(n + m log(m))
void calc_dists_dijkstra(int root, V<Node>& graph){
	struct compNodeDist{ const V<Node>& graph; compNodeDist(const V<Node>& _graph): graph(_graph){}
		bool operator()(int u, int v){return graph[u].dist >= graph[v].dist;};
	};
	priority_queue<int, vi, compNodeDist> q(graph);
	graph[root].dist = 0;
	q.push(root);
	while(!q.empty()){
		int u = q.top(); q.pop();
		if(graph[u].visited) continue;
		graph[u].visited = true;
		for(auto& [v, w]: graph[u].adj_list){
			if(graph[u].dist + w < graph[v].dist){
				graph[v].dist = graph[u].dist + w;
				q.push(v);
			}
		}
	}
}

// Floyd-Warshall algorithm to find all-pairs shortest path algorithm(can have negative edges) using dynamic programming in O(n^3).
auto calc_all_dists_fw(const V<Node>& graph){
	int n = graph.size();
	V<vll> distance(n, vll(n, INF));
	FOR(i, n) distance[i][i] = 0;
	FOR(i, n) for(auto& e: graph[i].adj_list) distance[i][e.F] = min(distance[i][e.F], (ll)e.S);

	FOR(k, n)
		FOR(i, n)
			FOR(j, n)
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
	
	return distance;
}

// Prints a cycle in a directed/undirected graph;
bool print_cycle(const V<Node>& _graph){
	V<Node> graph = _graph;
	bool cycle = false;
	int cycle_start, cycle_end;
	set<int> cur_path;
	
	function<void(int)> dfs = [&](int root){
		if(cycle) return;
		cur_path.insert(root);
		for(auto& child: graph[root].adj_list){
			// if(child == graph[root].parent) continue; // For undirected graph
			if(!graph[child.F].visited){
				graph[child.F].visited = true;
				graph[child.F].parent = root;
				dfs(child.F);
			}
			else if(!cycle && cur_path.find(child.F) != cur_path.end()){
				cycle = true;
				cycle_start = child.F;
				cycle_end = root;
				cur_path.clear();
				return;
			}
		}
		cur_path.erase(root);
	};
	
	int n = graph.size();
	FOR(i, n)
		if(!graph[i].visited)
			dfs(i);

	if(cycle){
		vi cycle;
		for(int i = cycle_end; i != cycle_start; i = graph[i].parent)
			cycle.pb(i+1);
		cycle.pb(cycle_start+1);
		reverse(all(cycle));
		cycle.pb(cycle_start+1);

		for(auto& v: cycle) cout << v << ' ';
		cout << '\n';
	}
	return cycle;
}

void input(){
	int n, m;
	cin >> n >> m;

	V<Node> graph(n);
	FOR(i, m){
		int a, b, c;
		cin >> a >> b >> c; a--; b--;
		graph[a].adj_list.pb({b, c});
		// graph[b].adj_list.pb({a, c});
	}

	calc_dists_bf(0, graph);

	for(auto& city: graph)
		cout << city.dist << ' ';
}