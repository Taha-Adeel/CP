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
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)            for(int i = (int)n-1; i >= 0; --i)
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
	bool visited = false;
	ll subtree_sz = 1;
	vi adj_list;
	int parent = -1;
};

void dfs(int root, V<Node>& tree){
	tree[root].visited = true;
	for(auto& child: tree[root].adj_list){
		if(!tree[child].visited){
			tree[child].parent = root;
			dfs(child, tree);
			tree[root].subtree_sz += tree[child].subtree_sz;
		}
	}
}

void solve(){
	int n; cin >> n;
	V<Node> tree(n);
	FOR(i, n-1){
		int p; cin >> p; p--;
		tree[i+1].adj_list.pb(p);
		tree[p].adj_list.pb(i+1);
	}

	dfs(0, tree);

	ll ans = 0;
	for(auto& node: tree){
		ll max_pairs = 0, l_size = node.subtree_sz - 1, r_size = 0;
		for(auto& child: node.adj_list){
			if(child == node.parent) continue;
			l_size -= tree[child].subtree_sz;
			r_size += tree[child].subtree_sz;
			max_pairs = max(max_pairs, l_size * r_size);
		}
		ans += max_pairs;
	}

	cout << ans;
}

int main(){
	solve();
	cout << nl;
	
	return 0;
}