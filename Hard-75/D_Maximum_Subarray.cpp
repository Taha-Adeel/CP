#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()        { std::sort(this->begin(), this->end()); }
    void sort_dsc()    { std::sort(this->begin(), this->end(), greater<T>()); }
    auto sum()         { T sum = 0; for(auto& i: *this) sum += i; return sum; }
    auto freqs()       { map<T, int> freq; for(auto& i: *this) freq[i]++; return freq; }
    auto indices()     { int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii; }
    auto prefix_sums() { int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps; }
    friend ostream& operator<<(ostream& out, const V<T>& v) { for(auto& i: v) out << i << ' '; return out; }
    friend istream& operator>>(istream& in, V<T>& v)        { for(auto& i: v) in >> i; return in; }
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)     for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)    for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)     for(int i = (int)n-1; i >= 0; --i)
#define all(v)        v.begin(), v.end()
#define pb push_back

constexpr char nl = '\n';
constexpr int MOD = 1000000007;
using ll  = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = V<int>;
using vll = V<ll>;

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

template<typename T = int>
struct Node{
	T sum;
	T max_sum_l, max_sum_r;
	T max_sum;
	int l, r; // Starting and ending indexes of the segment represented by current node
};

template<typename T = int>
class SegmentTree{
	vector<T>& arr;			// The array which we update and query on.
	vector<Node<T>> tree;	// Internal array representing the segment tree;
 
	int parent(int cur_node)		{return (cur_node - 1)/2;}
	int left(int cur_node)	{return 2 * cur_node + 1;}
	int right(int cur_node)	{return 2 * cur_node + 2;}
 
	// A recursive function that constructs Segment Tree for array[l..r].
	void constructSTUtil(int cur_node, int l, int r)
	{
		tree[cur_node].l = l;
		tree[cur_node].r = r;
 
		if (tree[cur_node].l == tree[cur_node].r){
			tree[cur_node].sum = arr[tree[cur_node].l];
			tree[cur_node].max_sum_l = max(arr[tree[cur_node].l], 0LL);
			tree[cur_node].max_sum = tree[cur_node].max_sum_l;
			tree[cur_node].max_sum_r = max(arr[tree[cur_node].r], 0LL);
		}
		else{
			int m = (l+r)/2;
			constructSTUtil(left(cur_node), l, m);
			constructSTUtil(right(cur_node), m + 1, r);
 
			tree[cur_node].sum = tree[left(cur_node)].sum + tree[right(cur_node)].sum;
			tree[cur_node].max_sum_l = max(tree[left(cur_node)].max_sum_l, tree[left(cur_node)].sum + tree[right(cur_node)].max_sum_l);
			tree[cur_node].max_sum_r = max(tree[left(cur_node)].max_sum_r + tree[right(cur_node)].sum, tree[right(cur_node)].max_sum_r);
			tree[cur_node].max_sum = max({tree[left(cur_node)].max_sum, tree[right(cur_node)].max_sum, tree[left(cur_node)].max_sum_r + tree[right(cur_node)].max_sum_l});
		}
	}
 
	// A recursive function to update the nodes which have i within its range 
	void updateUtil(int cur_node, int i)
	{
		if(tree[cur_node].l == tree[cur_node].r && tree[cur_node].l == i){
			tree[cur_node].sum = arr[tree[cur_node].l];
			tree[cur_node].max_sum_l = max(arr[tree[cur_node].l], 0LL);
			tree[cur_node].max_sum = tree[cur_node].max_sum_l;
			tree[cur_node].max_sum_r = max(arr[tree[cur_node].r], 0LL);
		}
		else if(i >= tree[cur_node].l && i <= tree[cur_node].r){
			updateUtil(left(cur_node), i);
			updateUtil(right(cur_node), i);
			tree[cur_node].sum = tree[left(cur_node)].sum + tree[right(cur_node)].sum;
			tree[cur_node].max_sum_l = max(tree[left(cur_node)].max_sum_l, tree[left(cur_node)].sum + tree[right(cur_node)].max_sum_l);
			tree[cur_node].max_sum_r = max(tree[left(cur_node)].max_sum_r + tree[right(cur_node)].sum, tree[right(cur_node)].max_sum_r);
			tree[cur_node].max_sum = max({tree[left(cur_node)].max_sum, tree[right(cur_node)].max_sum, tree[left(cur_node)].max_sum_r + tree[right(cur_node)].max_sum_l});
		}
	}
 
public:
	// Constructor
	SegmentTree(vector<T>& _arr)
		:arr(_arr)
	{
		int height = 1;	// Height of segment tree
		for(int nodes = 1; nodes < (int)arr.size(); nodes *= 2)
			height++;
		tree.reserve((1<<height) - 1);
 
		constructSTUtil(0, 0, arr.size() - 1);
	}
 
	auto query(){
		return tree[0].max_sum;
	}
 
	// Update the value at index i
	void update(int i, T new_val){
		arr[i] = new_val;
		updateUtil(0, i);
	}
};

void solve() {
    ll n, k, x; cin >> n >> k >> x;
    vll a(n); cin >> a;

    if(x < 0) {
        k = n - k;
        x = -x;
    }

    FOR(i, n) a[i] -= x;
    x *= 2;

    FOR(i, k) a[i] += x;

    SegmentTree<ll> st(a);
    ll ans = 0;
    FOR(i, n - k + 1) {
        ans = max(ans, st.query());
        if(i + k < n) {
            st.update(i, a[i] - x);
            st.update(i + k, a[i + k] + x);
        }
    }

    cout << ans;
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
        cout << nl;
    }
    
    return 0;
}