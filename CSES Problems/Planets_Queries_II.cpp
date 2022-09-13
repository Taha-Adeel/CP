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
#define pN {cout << "-1\n";  continue;}

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

#define MxN 200005
#define logkMx 31
 
int t[MxN], kth_next[MxN][logkMx], cycle_size[MxN], component[MxN], dist[MxN];
bool cycle[MxN];
 
pii cycle_start[MxN];

void dfs(int root){
	int cur_node = root, next_node = t[root];
	dist[root] = 0;
	while(dist[next_node] == -1){
		component[cur_node] = root;
		dist[next_node] = dist[cur_node] + 1;
		cur_node = next_node;
		next_node = t[cur_node];
	}
	component[cur_node] = root;
	int cycle_sz = dist[cur_node] - dist[next_node] + 1;
	if(cycle[next_node])
		cycle_start[root] = {next_node, dist[cur_node] + 1};
	else if(component[next_node] != root)
		cycle_start[root] = {cycle_start[component[next_node]].F
			, dist[cur_node] + 1 + cycle_start[component[next_node]].S - dist[next_node]};
	else{
		cycle_start[root] = {next_node, dist[cur_node] - cycle_sz + 1};
		cur_node = next_node;
		do{
			cycle[cur_node] = true;
			cycle_size[cur_node] = cycle_sz;
			cur_node = t[cur_node];
		} while (cur_node != cycle_start[root].F);
	}
}

void dfs(int root, int k, V<bool>& visited){
	visited[root] = true;
	int c = t[root];
	if(k == 0) 
		kth_next[root][k] = c;
	else
		kth_next[root][k] = kth_next[kth_next[root][k-1]][k-1];
	
	if(!visited[c])
		dfs(c, k, visited);
}

int get_kth_successor(int x, int k){
	if(k == -1) return x;
	int next = kth_next[x][0];
	for(int mask = 0; (1<<mask) <= k; mask++)
		if((1<<mask) & k)
			next = kth_next[next][mask];
	
	return next;
}

 
void solve(){
	int n, q;
	cin >> n >> q;
	V<bool> start_node(n, true);
	FOR(i, n){
		cin >> t[i]; t[i]--;
		start_node[t[i]] = false;
	}
 
	FOR(i, n) dist[i] = -1;
	FOR(i, n)
		if(start_node[i])
			dfs(i);
 
	FOR(i, n)
		if(dist[i] == -1)
			dfs(i);

	FOR(k, logkMx){
		V<bool> visited(n, false);
		FOR(i, n)
			if(!visited[i])
				dfs(i, k, visited);
	}
 
	FOR(_, q){
		int a, b;
		cin >> a >> b; a--, b--;
		if(a == b) {cout << 0 << nl; continue;}

		if(component[a] == component[b]){
			int d = dist[b] - dist[a];
			if(cycle[a] && cycle[b])
				cout << (d > 0 ? d : cycle_size[a] + d) << nl;
			else if(!cycle[a] && !cycle[b])
				cout << (d > 0 ? d : -1) << nl;
			else if (cycle[a])
				pN
			else
				cout << d << nl;
		}
		else{
			if(component[cycle_start[component[b]].F] != component[cycle_start[component[a]].F])
				pN
			
			if(cycle[a] && !cycle[b]) pN
			if(cycle[b]) 
				cout << cycle_start[component[a]].S - dist[a] + dist[b] - dist[cycle_start[component[a]].F] << nl;
			else{
				if(cycle_start[component[b]].F != cycle_start[component[a]].F)
					pN
				int d1 = cycle_start[component[a]].S - dist[a];
				int d2 = cycle_start[component[b]].S - dist[b];
				if(d2 >= d1) pN
				if(get_kth_successor(a, d1 - d2 - 1) != b)
					pN
				else
					cout << d1 - d2 << nl;
			}	
		}
	}
}

int main(){
	FAST;
	solve();
	
	return 0;
}