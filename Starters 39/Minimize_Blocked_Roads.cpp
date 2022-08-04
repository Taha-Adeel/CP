#include <bits/stdc++.h>

using namespace std;

#define FOR(a,c)   for (int (a)=0; (a)<(c); ++(a))
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define nl '\n'
using ll = long long int;
using p_ii = pair<int,int>;
constexpr int MOD{1000000007};
constexpr ll INF{1000000000000000003};

struct Node{
	int id;
	int subtree_size = 1;
	bool safe = false;
	vector<pair<int, bool>> roads;
};
class Edge{
public:
	int id1;
	int id2;
	bool blockable;
	int subtree_size;

	Edge(){};
	Edge(int _id1, int _id2, bool _blockable){
		id1= _id1; id2 = _id2; blockable = _blockable;
	}
};
void set_safe_thru_dfs(int root, int parent, vector<Node>& nodes){
	nodes[root].safe = true;
	for(auto curr_node = nodes[root].roads.begin(); curr_node != nodes[root].roads.end(); curr_node++){
		if (curr_node->first == parent)
            continue;
		if(!nodes[curr_node->first].safe)
			set_safe_thru_dfs(curr_node->first, root, nodes);
	}
}

void size_of_subtree(int root, int parent, vector<Node>& nodes)
{
    for(auto curr_node = nodes[root].roads.begin(); curr_node != nodes[root].roads.end(); curr_node++){
        if (curr_node->first == parent)
            continue;

        size_of_subtree(curr_node->first, root, nodes);
        nodes[root].subtree_size += nodes[curr_node->first].subtree_size;
    }
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;

		vector<Node> nodes(N + 1);
		vector<Edge> blockable_roads;

		FOR(i, N - 1){
			int U, V, X;
			cin >> U >> V >> X;

			nodes[U].id = U;
			nodes[U].roads.push_back({V, X});
			nodes[V].id = V;
			nodes[V].roads.push_back({U, X});
			
			if(X)
				blockable_roads.push_back(Edge(U, V, X));
		}
		size_of_subtree(1, 0, nodes);

		for(auto& road: blockable_roads)
			road.subtree_size = min(nodes[road.id1].subtree_size, nodes[road.id2].subtree_size);
		
		sort(blockable_roads.begin(), blockable_roads.end(), [](const Edge& e1, const Edge& e2){return e1.subtree_size > e2.subtree_size;});
		
		int blocked_roads_count = 0;
		int safe_cities = 0;
		for(int i = 0; i < blockable_roads.size() && safe_cities < N - K; ++i){
			if(nodes[blockable_roads[i].id1].safe == false || nodes[blockable_roads[i].id2].safe == false){
				if(nodes[blockable_roads[i].id1].subtree_size > nodes[blockable_roads[i].id2].subtree_size)
					set_safe_thru_dfs(blockable_roads[i].id2, blockable_roads[i].id1, nodes);
				else
					set_safe_thru_dfs(blockable_roads[i].id1, blockable_roads[i].id1, nodes);
				safe_cities += blockable_roads[i].subtree_size;
				blocked_roads_count++;
			}
		}
		if(safe_cities < N - K)
			blocked_roads_count = -1;
		if(N==K)
			blocked_roads_count = 0;
		cout << blocked_roads_count << nl;
	}

	return 0;
}