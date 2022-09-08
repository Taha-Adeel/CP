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
	vi adj_list;
	int children = 1;
	int parent = -1;
	int dist = 0;
};

void dfs(int root, V<Node>& tree){
	for(auto& child: tree[root].adj_list){
		if(child == tree[root].parent) continue;
		tree[child].dist = tree[root].dist + 1;
		tree[child].parent = root;
		dfs(child, tree);
		tree[root].children += tree[child].children;
	}
}

void solve(){
	int n;
	cin >> n;
	V<Node> tree(n); 
	FOR1(i, n-1){
		int a, b;
		cin >> a >> b; a--, b--;
		tree[a].adj_list.pb(b);
		tree[b].adj_list.pb(a);
	}

	dfs(0, tree);
	
	vll dist_sum(n, -1); dist_sum[0] = 0;
	FOR(i, n)
		dist_sum[0] += tree[i].dist;
	
	function<ll(int)> Dist_sum = [&](int i){
		int p = tree[i].parent;
		if(dist_sum[i] == -1) dist_sum[i] = Dist_sum(p) - tree[i].children + (n - tree[i].children); 
		return dist_sum[i];
	};

	FOR(i, n)
		cout << Dist_sum(i) << ' ';
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}