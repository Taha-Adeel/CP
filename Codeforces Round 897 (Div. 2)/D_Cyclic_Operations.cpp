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
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

struct Node{
	int dfs_call = -1;
	int next;
};

int cycle_finder(int root, V<Node>& graph, int dfs_call){
	int cur = root;
	while(true){
		if(graph[cur].dfs_call == dfs_call) return cur;
		if(graph[cur].dfs_call != -1) return -1;
		graph[cur].dfs_call = dfs_call;
		cur = graph[cur].next;
	}
	return -1;
}

int get_cycle_size(int root, V<Node>& graph){
	int cur = root;
	int cycle_size = 0;
	while(true){
		cycle_size++;
		cur = graph[cur].next;
		if(cur == root) break;
	}
	return cycle_size;
}

void solve(){
	int n, k; cin >> n >> k;
	vi b(n); cin >> b;

	if(k == 1){
		vi a(n); iota(all(a), 1);
		display(b == a);
	}

	V<Node> graph(n);
	FOR(i, n){
		graph[i].next = b[i] - 1;
	}

	FOR(i, n){
		if(graph[i].dfs_call != -1) continue;
		int cycle_root = cycle_finder(i, graph, i);
		if(cycle_root == -1) continue;
		int cycle_size = get_cycle_size(cycle_root, graph);
		if(cycle_size != k) pN;
	}

	pY
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