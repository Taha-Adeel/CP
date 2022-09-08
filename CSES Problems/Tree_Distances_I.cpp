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
#define FOR1(i, n)               for(int i = 1; i < (int)n; ++i)
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
	vi adj_list;
	pii mxlen1 = {0, -1}; // Max len thru x
	pii mxlen2 = {0, -1}; // 2nd max len thru x
	int mx_parent_d = 0;
};

void dfs(int root, V<Node>& tree){
	int p = tree[root].parent;
	for(auto& child: tree[root].adj_list){
		if(child == p) continue;
		tree[child].parent = root;
		dfs(child, tree);
		if(tree[child].mxlen1.F + 1 > tree[root].mxlen1.F)
			tree[root].mxlen1 = {tree[child].mxlen1.F + 1, child};
	}
	for(auto& child: tree[root].adj_list){
		if(child == p || child == tree[root].mxlen1.S) continue;
		if(tree[child].mxlen1.F + 1 > tree[root].mxlen2.F)
			tree[root].mxlen2 = {tree[child].mxlen1.F + 1, child};
	}
	if(root != 0)
		tree[root].mx_parent_d = max(tree[p].mx_parent_d, ((tree[p].mxlen1.S != root) ? tree[p].mxlen1.F : tree[p].mxlen2.F)) + 1;
}

int D(int i, vi& d, V<Node>& tree){
	int p = tree[i].parent;
	if(d[i] == -1) d[i] = max({D(p, d, tree), ((tree[p].mxlen1.S != i) ? tree[p].mxlen1.F : tree[p].mxlen2.F)}) + 1;

	return d[i];
}

void solve(){
	int n;
	cin >> n;
	V<Node> tree(n); 
	FOR(i, n-1){
		int a, b;
		cin >> a >> b; a--, b--;
		tree[a].adj_list.pb(b);
		tree[b].adj_list.pb(a);
	}

	dfs(0, tree);
	vi d(n, -1);
	d[0] = 0;
	FOR(i, n)
		cout << max(D(i, d, tree), tree[i].mxlen1.F) << ' ';
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}