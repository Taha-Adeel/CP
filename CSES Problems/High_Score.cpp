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
#define INF 1e16
template <ll N> using arr = array<ll, N>;
 
struct Node{
	int val;
	bool visited = false;
	int parent = -1;
	ll dist = INF;
	V<pll> adj_list;
};
 
V<arr<3>> get_edge_list(const V<Node>& graph){
	V<arr<3>> edges; // List of all edges
	FOR(i, graph.size())
		for(auto& edge: graph[i].adj_list)
			edges.pb({i, edge.F, edge.S});
	
	return edges;
}
 
// Bellman-Ford algorithm to find shortest point from the root to all points in a weighted graph(with no negative cycles) in O(nm).
ll calc_dists_bf(int root, V<Node>& graph, V<Node>& graph_rev){
	auto edges = get_edge_list(graph);
 
	graph[root].dist = 0;
	FOR(i, graph.size()){
		for(auto& e: edges){
			if(graph[e[0]].dist + e[2] < graph[e[1]].dist){
				graph[e[1]].dist = graph[e[0]].dist + e[2];
				if(i == (int)graph.size()-1 && graph[e[1]].visited && graph_rev[e[1]].visited) return 1;
			}
		}
	}
 
	return graph.back().dist;
}

void dfs(int root, V<Node>& graph){
	graph[root].visited = true;
	for(auto&e : graph[root].adj_list){
		if(!graph[e.F].visited)
			dfs(e.F, graph);
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
 
	V<Node> graph(n), graph_rev(n);
	V<arr<3>> E(m);
	FOR(i, m){
		cin >> E[i][0] >> E[i][1] >> E[i][2]; E[i][0]--; E[i][1]--;
		graph[E[i][0]].adj_list.pb({E[i][1], -E[i][2]});
		graph_rev[E[i][1]].adj_list.pb({E[i][0], E[i][2]});
	}
	dfs(0, graph), dfs(n-1, graph_rev);

	cout << -calc_dists_bf(0, graph, graph_rev);
}

int main(){
	FAST;
	solve();
	cout << nl;
	
	return 0;
}