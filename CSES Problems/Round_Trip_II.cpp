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

struct Node{
	int val;
	int index;
	bool visited = false;
	int parent = -1;
	vi adj_list;
};

bool cycle = false;
int cycle_start, cycle_end;
set<int> cur_path;

void dfs(int root, V<Node>& graph){
	if(cycle) return;
	cur_path.insert(root);
	for(auto& child: graph[root].adj_list){
		if(!graph[child].visited){
			graph[child].visited = true;
			graph[child].parent = root;
			dfs(child, graph);
		}
		else if(!cycle && cur_path.find(child) != cur_path.end()){
			cycle = true;
			cycle_start = child;
			cycle_end = root;
			cur_path.clear();
			return;
		}
	}
	cur_path.erase(root);
}

void solve(){
	int n, m;
	cin >> n >> m;

	V<Node> graph(n);
	FOR(i, n)
		graph[i].index = i;
	FOR(i, m){
		int a, b;
		cin >> a >> b; a--, b--;
		graph[a].adj_list.pb(b);
	}

	FOR(i, n)
		if(!graph[i].visited)
			dfs(i, graph);

	if(cycle){
		vi cycle;
		for(int i = cycle_end; i != cycle_start; i = graph[i].parent)
			cycle.pb(i+1);
		cycle.pb(cycle_start+1);
		reverse(all(cycle));
		cycle.pb(cycle_start+1);

		cout << cycle.size() << nl;
		cout << cycle << nl;
	}
	else
		cout << "IMPOSSIBLE";
}

int main(){
	FAST;
	solve();
	cout << nl;
	
	return 0;
}