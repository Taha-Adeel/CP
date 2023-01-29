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
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)                for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()
#define rall(v)                  v.rbegin(), v.rend()

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
	bool isBonus = false, isToken = false, isBaseToken = false, visited = false;
	vi adj_list;
	int bonus_count = 0, token_count = 0;
};

void dfs(int root, V<Node>& graph, bool base_call = false){
	graph[root].visited = true;
	graph[root].token_count += graph[root].isToken;
	graph[root].bonus_count += graph[root].isBonus;
	if(base_call) graph[root].isBaseToken = graph[root].isToken, graph[root].isToken = false;
	if(!graph[root].isBonus && root != 0) return;

	for(auto& child: graph[root].adj_list){
		if(graph[child].visited) continue;
		dfs(child, graph, base_call);
		graph[root].token_count += graph[child].token_count;
		graph[root].bonus_count += graph[child].bonus_count;
	}
}

void solve(){
	int n, m, p, b;
	cin >> n >> m >> p >> b;
	V<Node> graph(n);
	FOR(i, p){
		int x; cin >> x; x--;
		graph[x].isToken = true; 
	}
	FOR(i, b){
		int x; cin >> x; x--;
		graph[x].isBonus = true;
	}
	FOR(i, m){
		int u, v; cin >> u >> v; u--, v--;
		graph[u].adj_list.pb(v);
		graph[v].adj_list.pb(u);
	}

	if(graph[0].isToken) pY;
	for(auto& v: graph[0].adj_list)
		if(graph[v].isToken) pY

	dfs(0, graph, true);
	if(graph[0].token_count > 1) pY
	else if(graph[0].token_count == 0) pN

	ll moves_req, moves_doable = 0;
	// Perform BFS to find distance of first Base Token from node 0
	vi dist(n, -1);
	queue<int> q;
	q.push(0); dist[0] = 0;
	while(!q.empty()){
		int cur_node = q.front(); q.pop();
		if(graph[cur_node].isBaseToken) { moves_req = dist[cur_node]; break; }
		for(auto& child: graph[cur_node].adj_list){
			if(dist[child] != -1 || !graph[child].visited || (!graph[child].isBonus && !graph[child].isBaseToken)) continue;
			dist[child] = dist[cur_node] + 1;
			q.push(child);
		}
	}

	FOR(i, n){
		if(!graph[i].visited && graph[i].isBonus){
			dfs(i, graph);
			if(graph[i].bonus_count > 1 && graph[i].token_count > 0) pY;
		}
	}
	FOR(i, n){
		if(graph[i].isBonus){
			for(auto& v: graph[i].adj_list)
				moves_doable += graph[v].isToken,
				graph[v].isToken = false;
		}
	}
	if(moves_doable >= moves_req-1) pY

	pN
}

int main(){
	FAST;
	int T;
	cin >> T;
	bool debug = false;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}