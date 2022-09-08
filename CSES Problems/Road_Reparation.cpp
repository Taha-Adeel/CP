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
#define pN {cout << "IMPOSSIBLE";  return;}

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
	int parent = -1;
	int set_size = 1;
};

// Algorithm to get MST in O(mlogn)
ll kruskals_algo(V<Node>& graph, V<tuple<int, int, int>>& edges){
	auto ds = [&](int a){
		while(graph[a].parent != -1)
			a = graph[a].parent;
		return a;
	};
	auto merge = [&](int a, int b){
		int ds_a = ds(a), ds_b = ds(b);
		if(graph[ds_a].set_size < graph[ds_b].set_size) swap(a, b), swap(ds_a, ds_b);

		graph[ds_a].set_size += graph[ds_b].set_size;
		graph[ds_b].parent = ds_a;
	};


	edges.sort();
	ll min_cost = 0, edges_used = 0;
	for(auto& [c, a, b]: edges){
		if(ds(a) != ds(b)){
			min_cost += c;
			edges_used++;
			merge(a, b);
		}
	}
	if(edges_used != (int)graph.size()-1)
		return -1;

	return min_cost;
}

void solve(){
	int n, m;
	cin >> n >> m;
	
	V<Node> graph(n);
	V<tuple<int, int, int>> edges(m);
	FOR(i, m){
		int a, b, c;
		cin >> a >> b >> c; a--, b--;
		edges[i] = {c, a, b};
	}

	ll min_cost = kruskals_algo(graph, edges);
	if(min_cost == -1) pN
	else cout << min_cost;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}