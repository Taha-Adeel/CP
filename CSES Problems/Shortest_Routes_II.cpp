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
	bool visited = false;
	int parent = -1;
	V<pll> adj_list;
};

// Floyd-Warshall algorithm to find all-pairs shortest path algorithm using dynamic programming.
auto calc_all_dists_fw(const V<Node>& graph){
	int n = graph.size();
	V<vll> distance(n, vll(n, INF));
	FOR(i, n) distance[i][i] = 0;
	FOR(i, n) for(auto& e: graph[i].adj_list) distance[i][e.F] = min(e.S, distance[i][e.F]);

	FOR(k, n)
		FOR(i, n)
			FOR(j, n)
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
	
	return distance;
}

void solve(){
	int n, m, q;
	cin >> n >> m >> q;

	V<Node> graph(n);

	FOR(i, m){
		int a, b, c;
		cin >> a >> b >> c; a--, b--;
		graph[a].adj_list.pb({b, c});
		graph[b].adj_list.pb({a, c});
	}

	auto distances = calc_all_dists_fw(graph);

	FOR(_, q){
		int a, b;
		cin >> a >> b; a--, b--;

		cout << ((distances[a][b] != INF) ? distances[a][b] : -1) << nl;
	}
}

int main(){
	FAST;
	solve();
	
	return 0;
}