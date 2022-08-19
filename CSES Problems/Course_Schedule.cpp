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
	vi  adj_list;
	STATE state = STATE::UNVISITED;
};

// Returns the elements of a directed graph in a topological ordering(a appears before b if there is an edge from a to b)
vi get_topological_ordering(V<Node>& graph){
	vi topological_ordering;
	function<void(int)> dfs = [&](int root){
		graph[root].state = STATE::PROCESSING;
		for(auto& child: graph[root].adj_list){
			if(graph[child].state == STATE::UNVISITED)
				dfs(child);
			else if(graph[child].state == STATE::PROCESSING) throw "Cycle found";
		}
		graph[root].state = STATE::PROCESSED;
		topological_ordering.pb(root+1);
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
	FOR(i, m){
		int a, b;
		cin >> a >> b; a--, b--;
		graph[a].adj_list.pb(b);
	}

	auto schedule = get_topological_ordering(graph);
	if(!schedule.empty())
		cout << schedule;
	else
		cout << "IMPOSSIBLE";
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}