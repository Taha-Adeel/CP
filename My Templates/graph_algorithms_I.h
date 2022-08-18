#include <bits/stdc++.h>
using namespace std;

#define V vector
using vi = V<int>;
#define FOR(i, n) for(int i = 0; i < (int)n; ++i)
#define pb push_back

struct Node{
	int val;
	vi  adj_list;
	int parent = -1;
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