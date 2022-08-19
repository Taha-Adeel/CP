#include <bits/stdc++.h>
using namespace std;

#define V vector
using vi = V<int>;
#define FOR(i, n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define all(v) v.begin(), v.end()

enum class STATE {UNVISITED, PROCESSING, PROCESSED};
struct Node{
	int val;
	vi  adj_list;
	int parent = -1;
	STATE state = STATE::UNVISITED;
	bool visited = false;
};

void dfs(int root, V<Node>& graph){
	graph[root].visited = true;
	for(auto& child: graph[root].adj_list){
		if(!graph[child].visited){
			graph[child].parent = root;
			dfs(child, graph);
		}
	}
}

bool bfs(int start, int dest, V<Node>& graph){
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		auto cur_node = q.front(); q.pop();
		graph[cur_node].visited = true;

		if(cur_node == dest)
			return true;
			
		for(auto& child: graph[cur_node].adj_list){
			if(!graph[child].visited){
				graph[child].visited = true;
				graph[child].parent = cur_node;
				q.push(child);
			}
		}
	}

	return false;
}

// Returns the elements of a directed graph in a topological ordering(a appears before b if there is an edge from a to b)
vi get_topological_ordering(V<Node>& graph){
	vi topological_ordering;
	function<void(int)> dfs = [&](int root){
		graph[root].state = STATE::PROCESSING;
		for(auto& child: graph[root].adj_list){
			if(graph[child].state == STATE::UNVISITED)
				dfs(child);
			else if(graph[child].state == STATE::PROCESSING) throw "Cycle found";
		}
		graph[root].state = STATE::PROCESSED;
		topological_ordering.pb(root+1);
	};

	FOR(i, graph.size()) 
		if(graph[i].state == STATE::UNVISITED)
			try{dfs(i);}
			catch(const char* e){return vi{};}

	reverse(all(topological_ordering));

	return topological_ordering;
}

void input(){
	int n, m;
	cin >> n >> m;

	V<Node> graph(n);
	FOR(i, m){
		int a, b;
		cin >> a >> b; a--, b--;
		graph[a].adj_list.pb(b);
		graph[b].adj_list.pb(a);
	}
}