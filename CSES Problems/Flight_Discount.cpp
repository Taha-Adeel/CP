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

struct Node{
	int val;
	bool visited = false;
	int parent = -1;
	ll dist = INF;
	V<pii> adj_list;
};

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
		for(auto& e: graph[u].adj_list){
			int v = e.F, w = e.S;
			if(graph[u].dist + w < graph[v].dist){
				graph[v].dist = graph[u].dist + w;
				q.push(v);
			}
		}
	}
}

void solve(){
	int n, m;
	cin >> n >> m;

	V<Node> graph_f(n), graph_r(n);
	FOR(i, m){
		int a, b, c;
		cin >> a >> b >> c; a--; b--;
		graph_f[a].adj_list.pb({b, c});
		graph_r[b].adj_list.pb({a, c});
	}
	calc_dists_dijkstra(0, graph_f);
	calc_dists_dijkstra(n-1, graph_r);

	ll ans = 1e17;
	FOR(i, n)
		for(auto& e: graph_f[i].adj_list)
			ans = min(ans, graph_f[i].dist + e.S/2 + graph_r[e.F].dist);
		
	cout << ans;
}

int main(){
	FAST;
	solve();
	cout << nl;
	
	return 0;
}