#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i < (int)n; ++i)
#define FOR_RANGE(i, start, end) for(int i = start; i != end; i += (start<end) ? 1 : -1)
#define FOR_REV(i, n)            for(int i = (int)n-1; i >= 0; --i)
#define all(v)                   v.begin(), v.end()

#define F  first
#define S  second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define V vector
constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

#define nMx 200000 
#define logkMx 31

struct Node{
	array<int, logkMx> kth_next;
	int next;
};
Node graph[nMx];

void dfs(int root, int k, V<bool>& visited){
	visited[root] = true;
	int c = graph[root].next;
	if(k == 0) 
		graph[root].kth_next[k] = c;
	else
		graph[root].kth_next[k] = graph[graph[root].kth_next[k-1]].kth_next[k-1];
	
	if(!visited[c])
		dfs(c, k, visited);
}

int get_kth_successor(int x, int k){
	if(k == -1) return x;
	int next = graph[x].kth_next[0];
	for(int mask = 0; (1<<mask) <= k; mask++)
		if((1<<mask) & k)
			next = graph[next].kth_next[mask];
	
	return next;
}

void solve(){
	int n, q;
	cin >> n >> q;
	int t;
	FOR(i, n){
		cin >> t; t--;
		graph[i].next = t;
	}

	FOR(k, logkMx){
		V<bool> visited(n, false);
		FOR(i, n)
			if(!visited[i])
				dfs(i, k, visited);
	}

	int x, k;
	FOR(i, q){
		cin >> x >> k; x--;

		cout << get_kth_successor(x, k-1) + 1 << nl;
	}
}

int main(){
	FAST;
	solve();
	
	return 0;
}