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

// Lazy Segment Tree to perform operation u during range update and operation q during range query
class LazySegmentTree{
	int n;
	vi tree, lazy;
	int operation_u(int a, int b){return a^b;}
	int operation_q(int a, int b){return max(a,b);}
	int neutral_u = 0;
	int neutral_q = 0;

	void update(int node, int start, int end, int l, int r, int val){
		if(lazy[node] != neutral_u){
			tree[node] = operation_u(tree[node], lazy[node]);
			if(start != end){
				lazy[node*2] = operation_u(lazy[node*2], lazy[node]);
				lazy[node*2+1] = operation_u(lazy[node*2+1], lazy[node]);
			}
			lazy[node] = neutral_u;
		}
		if(r < start || end < l) return;
		if(l <= start && end <= r){
			tree[node] = operation_u(tree[node], val);
			if(start != end){
				lazy[node*2] = operation_u(lazy[node*2], val);
				lazy[node*2+1] = operation_u(lazy[node*2+1], val);
			}
			return;
		}
		int mid = (start+end)/2;
		update(node*2, start, mid, l, r, val);
		update(node*2+1, mid+1, end, l, r, val);
		tree[node] = operation_q(tree[node*2], tree[node*2+1]);
	}

	// Returns the maximum value in the range [l, r] of the array.
	int Query(int node, int start, int end, int l, int r) {
		if (l > end || r < start) {
			// The query range does not intersect with the range represented by this node.
			return -1;
		}
		if (l <= start && end <= r) {
			// The query range fully encloses the range represented by this node.
			return tree[node];
		}
		// The query range intersects with the range represented by this node.
		// Apply any pending updates and recursively query the left and right subtrees.
		int mid = (start + end) / 2;
		tree[node] ^= lazy[node];
		lazy[2 * node] ^= lazy[node];
		lazy[2 * node + 1] ^= lazy[node];
		lazy[node] = 0;
		int left = Query(2 * node, start, mid, l, r);
		int right = Query(2 * node + 1, mid + 1, end, l, r);
		// Update the current node with the maximum value from the left and right subtrees.
		tree[node] = max(tree[2 * node], tree[2 * node + 1]);
		return max(left, right);
	}

	int query(int node, int start, int end, int l, int r){
		if(lazy[node] != neutral_u){
			tree[node] = operation_u(tree[node], lazy[node]);
			if(start != end){
				lazy[node*2] = operation_u(lazy[node*2], lazy[node]);
				lazy[node*2+1] = operation_u(lazy[node*2+1], lazy[node]);
			}
			lazy[node] = neutral_u;
		}
		if(r < start || end < l) return neutral_q;
		if(l <= start && end <= r) return tree[node];
		int mid = (start+end)/2;
		return operation_q(query(node*2, start, mid, l, r), query(node*2+1, mid+1, end, l, r));
	}
	public:
	LazySegmentTree(vi& a){
		n = a.size();
		tree.resize(4*n, neutral_q);
		lazy.resize(4*n, neutral_u);
		build(a, 1, 0, n-1);
	}
	void build(vi& a, int node, int start, int end){
		if(start == end){
			tree[node] = a[start];
			return;
		}
		int mid = (start+end)/2;
		build(a, node*2, start, mid);
		build(a, node*2+1, mid+1, end);
		tree[node] = operation_q(tree[node*2], tree[node*2+1]);
	}
	void update(int l, int r, int val){update(1, 0, n-1, l, r, val);}
	int query(int l, int r){return query(1, 0, n-1, l, r);}

	void print_arr(){
		FOR(i, n) cout << query(i, i) << " ";
		cout << nl;
	}
};

void solve(){
	int n, q; 
	cin >> n >> q;
	vi a(n);
	cin >> a;

	vi suffix_xor;
	ROF(i, n){
		if(i == n-1) suffix_xor.pb(a[i]);
		else suffix_xor.pb(suffix_xor.back()^a[i]);
	}
	LazySegmentTree st(suffix_xor);

	FOR(_, q){
		int i, x;
		cin >> i >> x; i--;

		st.print_arr();
		st.update(n-i-1, n-1, x^a[i]);
		st.print_arr();
		cout << st.query(0, n-2) << nl;
		st.update(n-i-1, n-1, x^a[i]);
	}
}

int main(){
	solve();
	
	return 0;
}