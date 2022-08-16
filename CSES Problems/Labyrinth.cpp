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
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;
using vb  = V<bool>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

struct Node{
	bool visited;
	char move;
	int path_len;
	pii parent;
	char val;
};

bool bfs(pii root, pii dest, V<V<Node>>& graph){
	queue<pii> discovered;
	graph[root.F+1][root.S+1] = {true, 'A', 0};
	discovered.push(root);
	while(!discovered.empty()){
		auto p = discovered.front(); discovered.pop();
		if(p == dest)
			return true;
		graph[p.F+1][p.S+1].visited = true;
		int len = graph[p.F+1][p.S+1].path_len + 1;
		if(!graph[p.F+1][p.S+2].visited){
			graph[p.F+1][p.S+2] = {true, 'R', len, p};
			discovered.push({p.F, p.S+1});
		}
		if(!graph[p.F+2][p.S+1].visited){
			graph[p.F+2][p.S+1] = {true, 'D', len, p};
			discovered.push({p.F+1, p.S});
		}
		if(!graph[p.F+1][p.S].visited){
			graph[p.F+1][p.S] = {true, 'L', len, p};
			discovered.push({p.F, p.S-1});
		}
		if(!graph[p.F][p.S+1].visited){
			graph[p.F][p.S+1] = {true, 'U', len, p};
			discovered.push({p.F-1, p.S});
		}
	}

	return false;
}

void solve(){
	int n, m;
	cin >> n >> m;
	V<string> labyrinth(n);
	cin >> labyrinth;

	V<V<Node>> graph(n+2, V<Node>(m+2, {true}));
	pii A, B;
	FOR(i, n){
		FOR(j, m){
			graph[i+1][j+1].val = labyrinth[i][j];
			if(graph[i+1][j+1].val != '#') graph[i+1][j+1].visited = false;
			if(graph[i+1][j+1].val == 'A') A = {i, j};
			if(graph[i+1][j+1].val == 'B') B = {i, j};
		}
	}

	if(bfs(A, B, graph)){
		string path = "";
		for(pii cur_node = B; cur_node != A; cur_node = graph[cur_node.F+1][cur_node.S+1].parent)
			path += graph[cur_node.F+1][cur_node.S+1].move;
		reverse(all(path));

		cout << "YES" << nl;
		cout << graph[B.F+1][B.S+1].path_len << nl;
		cout << path << nl;
	}
	else
		cout << "NO" << nl;
}

int main(){
	solve();
	
	return 0;
}