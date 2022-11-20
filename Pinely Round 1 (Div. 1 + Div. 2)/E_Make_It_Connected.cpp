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
	friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i+1 << ' '; return out;}
	friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
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
	bool visited = false;
	vi adj_list;
	int component;
};

void solve(){
	int n;
	cin >> n;
	V<string> adj_matrix(n);
	cin >> adj_matrix;
	
	V<Node> graph(n);
	FOR(i, n) FOR(j, n)
		if(adj_matrix[i][j] == '1')
			graph[i].adj_list.pb(j);
	
	int connected_components = 0;
	FOR(i, n){
		if(graph[i].visited)
			continue;
		connected_components++;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int node = q.front();
			q.pop();
			if(graph[node].visited)
				continue;
			graph[node].visited = true;
			graph[node].component = connected_components;
			for(auto& adj: graph[node].adj_list) if(!graph[adj].visited)
				q.push(adj);
		}
	}

	if(connected_components == 1){
		cout << 0 << nl;
		return;
	}
	map<int, vi> components;
	FOR(i, n)
		components[graph[i].component].pb(i);
	
	for(auto& [num, component]: components){
		int min_degree = graph[component[0]].adj_list.size();
		for(auto& node: component)
			min_degree = min(min_degree, (int)graph[node].adj_list.size());
		for(auto& i: component){
			if(graph[i].adj_list.size() == min_degree && min_degree != component.size()-1){
				cout << 1 << nl;
				cout << i+1 << nl;
				return;
			}
		}
	}
	int min_component_size = INT_MAX;
	for(auto& [num, component]: components)
		min_component_size = min(min_component_size, (int)component.size());
	if(connected_components == 2 || min_component_size == 1){
		for(auto& [num, component]: components){
			if(component.size() == min_component_size){
				cout << min_component_size << nl;
				cout << component << nl;
				return;
			}
		}
	}
	else{
		cout << 2 << nl;
		cout << components[1][0]+1 << ' ' << components[2][0]+1 << nl;
	}
}

int main(){
	FAST;
	int T;
	cin >> T;
	FOR(t, T){
		solve();
	}
	
	return 0;
}