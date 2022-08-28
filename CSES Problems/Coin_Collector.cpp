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

enum class STATE {UNVISITED, PROCESSING, PROCESSED};
struct Node{
	int coins;
	ll max_coins = 0;
	int parent = -1;
	STATE state = STATE::UNVISITED;
	vi out_adj_list;
	vi in_adj_list;
};

// Returns the elements of a directed graph in a topological ordering(a appears before b if there is an edge from a to b)
vi get_topological_ordering(V<Node>& graph){
	vi topological_ordering;
	function<void(int)> dfs = [&](int root){
		graph[root].state = STATE::PROCESSING;
		for(auto& child: graph[root].out_adj_list){
			if(graph[child].state == STATE::UNVISITED)
				dfs(child);
			else if(graph[child].state == STATE::PROCESSING) throw "Cycle found";
		}
		graph[root].state = STATE::PROCESSED;
		topological_ordering.pb(root);
	};

	FOR(i, graph.size())
		if(graph[i].state == STATE::UNVISITED)
			try{dfs(i);}
			catch(const char* e){return vi{};}

	reverse(all(topological_ordering));

	return topological_ordering;
}

void solve(){
	int n, m;
	cin >> n >> m;
	V<Node> graph(n);
	FOR(i, n) cin >> graph[i].coins, graph[i].max_coins = graph[i].coins;
	FOR(i, m){
		int u, v;
		cin >> u >> v; u--, v--;
		graph[u].out_adj_list.pb(v);
		graph[v].in_adj_list.pb(u);
	}

	ll ans = 0;
	for(auto& i: get_topological_ordering(graph)){
		ll max_child = 0;
		for(auto& e: graph[i].in_adj_list)
			max_child = max(max_child, graph[e].max_coins);
		graph[i].max_coins += max_child;
		ans = max(ans, graph[i].max_coins);
	}

	cout << ans;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}