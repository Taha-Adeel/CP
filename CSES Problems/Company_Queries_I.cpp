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
	int depth = 0;
	vi superior;
	vi adj_list;
};

void dfs(int root, V<Node>& tree){
	for(auto& child: tree[root].adj_list){
		if(root != 0 && child == tree[root].superior[0]) continue;

		tree[child].depth = tree[root].depth + 1;
		tree[child].superior.pb(root);
		for(int k = 1; (1<<k) <= tree[child].depth; k++)
			tree[child].superior.pb(tree[tree[child].superior[k-1]].superior[k-1]);
		
		dfs(child, tree);
	}
}

int get_kth_ancestor(int x, int k, V<Node>& tree){
	if(k >= tree[x].depth) return -1;
	int ancestor = tree[x].superior[0];
	for(int mask = 0; (1<<mask) <= k; mask++)
		if((1<<mask) & k)
			ancestor = tree[ancestor].superior[mask];
	
	return ancestor;
}

void solve(){
	int n, q;
	cin >> n >> q;
	V<Node> tree(n);
	FOR1(e, n-1){
		int boss;
		cin >> boss; boss--;
		tree[boss].adj_list.pb(e);
	}

	dfs(0, tree);

	FOR(_, q){
		int x, k;
		cin >> x >> k; x--, k--;
		
		int kth_ancestor = get_kth_ancestor(x, k, tree);
		cout << ((kth_ancestor == -1) ? kth_ancestor : kth_ancestor + 1) << nl;
	}
}

int main(){
	FAST;
	solve();
	
	return 0;
}