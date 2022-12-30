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
constexpr int MOD = 998244353;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

struct Node{
	bool visited = false;
	vi adj_list;
};

void dfs(int root, V<Node>& graph, int& node_count, int& edge_count, int& self_edge){
	graph[root].visited = true;
	node_count++;
	edge_count += graph[root].adj_list.size();
	for(auto& i: graph[root].adj_list)
		if(!graph[i].visited)
			dfs(i, graph, node_count, edge_count, self_edge);
		else if(i == root)
			self_edge++;
}

void solve(){
	int n;
	cin >> n;
	vi a(n), b(n);
	cin >> a >> b;

	V<Node> graph(n);
	FOR(i, n)
		graph[--a[i]].adj_list.push_back(--b[i]),
		graph[b[i]].adj_list.push_back(a[i]);
	
	ll ans = 1;
	FOR(i, n){
		if(!graph[i].visited){
			int node_count = 0, edge_count = 0, self_edge = 0;
			dfs(i, graph, node_count, edge_count, self_edge);

			if(edge_count == 2 * node_count)
				if(self_edge)
					ans = (ans * n) % MOD;
				else
					ans = (ans * 2) % MOD;
			else
				ans = 0;
		}
	}

	cout << ans;
}

int main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve();
		cout << nl;
	}
	
	return 0;
}