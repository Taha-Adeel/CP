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
#define pN {cout << "IMPOSSIBLE";  return;}

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
	vi adj_list;
	bool visited = false;
	int component = -1;
};

// Get the "structure"(Nodes in increasing order of finished processing order) of the graph
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

// Get a solution for the 2SAT problem. Assumes graph is in topological order and reduced to DAG
V<char> get_solution(V<CondensedNode>& condensed_graph, int m){
	V<char> solution(m, '?');
	// Go over the components in reverse tropological order
	FOR_REV(i, condensed_graph.size())
		for(auto& x: condensed_graph[i].nodes)
			if(solution[x/2] == '?')
				solution[x/2] = (x%2 == 0) ? '+' : '-';

	return solution;
}

void solve(){
	int n, m;
	cin >> n >> m;

	// Generating the implication graph
	V<Node> implication_graph(2*m);
	auto neg = [](int i){return (i%2) ? i-1 : i+1;};
	FOR(i, n){
		char wish1, wish2; int wish1_topping, wish2_topping;
		cin >> wish1 >> wish1_topping >> wish2 >> wish2_topping; wish1_topping--, wish2_topping--;

		wish1_topping *= 2; wish2_topping *= 2;
		if(wish1 == '-') wish1_topping += 1;
		if(wish2 == '-') wish2_topping += 1;

		implication_graph[neg(wish1_topping)].adj_list.pb(wish2_topping);
		implication_graph[neg(wish2_topping)].adj_list.pb(wish1_topping);
	}

	// Get the SCC each node belongs to
	kosaraju_algo(implication_graph);

	// If both x and ~x belong to the same SCC, print impossible.
	FOR(i, m)
		if(implication_graph[2*i].component == implication_graph[2*i + 1].component) pN
	
	// Condense the implication graph
	auto condensed_graph = condense(implication_graph); // Condensed graph is in topological order

	auto solution = get_solution(condensed_graph, m);

	cout << solution;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}