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

#define INF 1e15
template <int N> using arr = array<int, N>;

struct Node{
	int val;
	bool visited = false;
	int parent = -1;
	ll dist = INF;
	V<pii> adj_list;
};

V<arr<3>> get_edge_list(const V<Node>& graph){
	V<arr<3>> edges; // List of all edges
	FOR(i, graph.size())
		for(auto& edge: graph[i].adj_list)
			edges.pb({i, edge.F, edge.S});
	
	return edges;
}

auto calc_dists_bf(int root, V<Node>& graph){
	auto edges = get_edge_list(graph);
	
	graph[root].dist = 0;
	set<arr<3>> cyclic_edges;
	FOR(i, graph.size()+1){
		for(auto& e: edges){
			if(graph[e[0]].dist + e[2] < graph[e[1]].dist){
				graph[e[1]].dist = graph[e[0]].dist + e[2];
				if(i >= (int)graph.size()-1) cyclic_edges.insert(e);
			}
		}
	}
	if(cyclic_edges.empty()) cout << "NO";
	return cyclic_edges;
}

// Prints a cycle in a directed/undirected graph;
void print_cycle(const V<Node>& graph){
	bool cycle = false;
	int cycle_start, cycle_end;
	set<int> cur_path;
	function<void(int, V<Node>&)> dfs = [&](int root, V<Node>& graph){
		if(cycle) return;
		cur_path.insert(root);
		for(auto& child: graph[root].adj_list){
			if(!graph[child.F].visited){
				graph[child.F].visited = true;
				graph[child.F].parent = root;
				dfs(child.F, graph);
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
	V<Node> graph_copy = graph;
	FOR(i, n)
		if(!graph_copy[i].visited)
			dfs(i, graph_copy);

	if(cycle){
		vi cycle;
		for(int i = cycle_end; i != cycle_start; i = graph_copy[i].parent)
			cycle.pb(i+1);
		cycle.pb(cycle_start+1);
		reverse(all(cycle));
		cycle.pb(cycle_start+1);

		for(auto& v: cycle) cout << v << ' ';
		cout << '\n';
	}
}


void solve(){
		int n, m;
	cin >> n >> m;

	V<Node> graph(n);
	FOR(i, m){
		int a, b, c;
		cin >> a >> b >> c; a--; b--;
		graph[a].adj_list.pb({b, c});
	}

	auto cyclic_edges = calc_dists_bf(0, graph);
	if(!cyclic_edges.empty()){
		V<Node> cyclic_graph(n);
		for(auto& e: cyclic_edges)
			{cyclic_graph[e[0]].adj_list.pb({e[1], e[2]});}
		
		cout << "YES" << nl;
		print_cycle(cyclic_graph);
	}
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}