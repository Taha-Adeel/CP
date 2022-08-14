#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
	void sort() {sort(this->begin(), this->end());}
	void sort_dsc() {sort(this->begin(), this->end(), greater<T>());}
	long long sum() {long long sum = 0; for(auto& i: *this) sum += i; return sum;}
	map<T, int> freqs() {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
	map<T, vector<int>> indices() {map<T, vector<int>> index; for(int i=0; i<(int)this->size(); i++) index[this->at(i)].push_back(i); return index;}
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

/*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*/

template<typename T = int>
struct Node{
	T val;
	int l, r; // Starting and ending indexes of the segment represented by current node
};

template<typename T = int>
class SegmentTree{
	vector<T>& arr;			// The array which we update and query on.
	vector<Node<set<T>>> tree;	// Internal array representing the segment tree;

	function<set<T>(const set<T>&, const set<T>&)> func; 	// The type of query to perform (Eg, min/max/sum/gcd)
	set<T> IDENTITY_VAL;				// The identity value for the above function

	int parent(int cur_node)		{return (cur_node - 1)/2;}
	int left_child(int cur_node)	{return 2 * cur_node + 1;}
	int right_child(int cur_node)	{return 2 * cur_node + 2;}

	// A recursive function that constructs Segment Tree for array[l..r].
	set<T> constructSTUtil(int cur_node, int l, int r)
	{
		tree[cur_node].l = l;
		tree[cur_node].r = r;

		if (tree[cur_node].l == tree[cur_node].r)
			tree[cur_node].val = set<T>({arr[tree[cur_node].l]});
		else{
			int m = (tree[cur_node].l + tree[cur_node].r)/2;
			tree[cur_node].val = func(constructSTUtil(left_child(cur_node), l, m), constructSTUtil(right_child(cur_node), m + 1, r));
		}

		return tree[cur_node].val;
	}

	// A recursive function to get the query value between l and r.
	set<T> queryUtil(int cur_node, int l, int r)
	{
		if(tree[cur_node].l >= l && tree[cur_node].r <= r) 
			return tree[cur_node].val;
		else if(tree[cur_node].r < l || tree[cur_node].l > r)
			return IDENTITY_VAL;
		else
			return func(queryUtil(left_child(cur_node), l, r), queryUtil(right_child(cur_node), l, r));
	}

public:
	// Constructor
	SegmentTree(vector<T>& _arr, function<set<T>(const set<T>&, const set<T>&)> _func, set<T> _IDENTITY_VAL = 0)
		:arr(_arr), func(_func), IDENTITY_VAL(_IDENTITY_VAL)
	{
		int height = 1;	// Height of segment tree
		for(int nodes = 1; nodes < (int)arr.size(); nodes *= 2)
			height++;
		tree.reserve((1<<height) - 1);

		constructSTUtil(0, 0, arr.size() - 1);
	}

	// Return query value between l and r (inclusive).
	T query(int l, int r){
		if(l > r)
			swap(l, r);
		return queryUtil(0, l, r).size();
	}
};

void solve(){
	int n, Q;
	cin >> n >> Q;
	vi x(n);
	cin >> x;

	SegmentTree<int> s(x, [](const set<int>& a, const set<int>& b){set<int> c; set_union(all(a), all(b), inserter(c, c.begin())); return c;}, set<int>({}));

	FOR(q, Q){
		int a, b;
		cin >> a >> b;

		cout << s.query(a-1, b-1) << nl;
	}
}

int main(){
	FAST;
	solve();
	cout << nl;
	
	return 0;
}