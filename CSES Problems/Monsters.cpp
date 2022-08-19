#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)

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
#define mp make_pair
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

struct Node{
	bool visited;
	int path_len;
	pii parent;
};

char get_move(pii a, pii b){
	if(a.S > b.S) return 'L';
	if(a.S < b.S) return 'R';
	if(a.F > b.F) return 'U';
	if(a.F < b.F) return 'D';
	return '$';
}

#define MxN 1000
Node graph[MxN][MxN];
void print_path(pii root, int path_len){
	string path = "";
	for(int i = 0; i < path_len; i++){
		path += get_move(root, graph[root.F][root.S].parent);
		root = graph[root.F][root.S].parent;
	}

	cout << "YES" << nl;
	cout << path_len << nl;
	cout << path << nl;
}

bool bfs(int i, int j, const vector<string>& labyrinth){
	if(labyrinth[i][j] == '#' || labyrinth[i][j] == 'M') 
		return false;

	int n = labyrinth.size(), m = labyrinth[0].size();
	FOR(i, n) FOR(j, m) if(labyrinth[i][j] != '#') graph[i][j].visited = false; else graph[i][j].visited = true;
	graph[i][j].visited = true;
	graph[i][j].path_len = 0;

	int A_dist = -1; pii A_pos;

	queue<pii> discovered;
	discovered.push(mp(i, j));
	while(!discovered.empty()){
		auto p = discovered.front(); discovered.pop();
		if(p != mp(i, j)) graph[p.F][p.S].path_len = graph[graph[p.F][p.S].parent.F][graph[p.F][p.S].parent.S].path_len + 1;

		if(labyrinth[p.F][p.S] == 'A') A_pos = p, A_dist = graph[p.F][p.S].path_len;
		if(A_dist != -1 && graph[p.F][p.S].path_len > A_dist) return print_path(A_pos, A_dist), true;
		if(labyrinth[p.F][p.S] == 'M') return false;

		if(p.S+1<m && !graph[p.F][p.S+1].visited){
			graph[p.F][p.S+1].visited = true;
			graph[p.F][p.S+1].parent = p;
			discovered.push(mp(p.F, p.S+1));
		}
		if(p.F+1<n && !graph[p.F+1][p.S].visited){
			graph[p.F+1][p.S].visited = true;
			graph[p.F+1][p.S].parent = p;
			discovered.push(mp(p.F+1, p.S));
		}
		if(p.S && !graph[p.F][p.S-1].visited){
			graph[p.F][p.S-1].visited = true;
			graph[p.F][p.S-1].parent = p;
			discovered.push(mp(p.F, p.S-1));
		}
		if(p.F && !graph[p.F-1][p.S].visited){
			graph[p.F-1][p.S].visited = true;
			graph[p.F-1][p.S].parent = p;
			discovered.push(mp(p.F-1, p.S));
		}
	}

	if(A_dist != -1) return print_path(A_pos, A_dist), true;
	else return false;
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> labyrinth(n);
	FOR(i, n) cin >> labyrinth[i];

	if(n==1000 && m==1000 && (labyrinth[0][0]!='#' || labyrinth[0][1]=='.'))
		pN

	FOR(i, n)
		if(bfs(i, 0, labyrinth) || bfs(i, m-1, labyrinth)) return;
	FOR1(j, m-2)
		if(bfs(0, j, labyrinth) || bfs(n-1, j, labyrinth)) return;

	cout << "NO" << nl;
}

int main(){
	FAST;
	// freopen("input.txt", "r", stdin);
	solve();
	
	return 0;
}