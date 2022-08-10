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
	vector<Node<T>> tree;	// Internal array representing the segment tree;

	function<T(T, T)> func; 	// The type of query to perform (Eg, min/max/sum/gcd)
	T IDENTITY_VAL;				// The identity value for the above function

	int parent(int cur_node)		{return (cur_node - 1)/2;}
	int left_child(int cur_node)	{return 2 * cur_node + 1;}
	int right_child(int cur_node)	{return 2 * cur_node + 2;}

	// A recursive function that constructs Segment Tree for array[l..r].
	T constructSTUtil(int cur_node, int l, int r)
	{
		tree[cur_node].l = l;
		tree[cur_node].r = r;

		if (tree[cur_node].l == tree[cur_node].r)
			tree[cur_node].val = arr[tree[cur_node].l];
		else{
			int m = (tree[cur_node].l + tree[cur_node].r)/2;
			tree[cur_node].val = func(constructSTUtil(left_child(cur_node), l, m), constructSTUtil(right_child(cur_node), m + 1, r));
		}

		return tree[cur_node].val;
	}

	// A recursive function to update the nodes which have i within its range 
	T updateUtil(int cur_node, int i)
	{
		if(tree[cur_node].l == tree[cur_node].r && tree[cur_node].l == i)
			tree[cur_node].val = arr[tree[cur_node].l];
		else if(i >= tree[cur_node].l && i <= tree[cur_node].r)
			tree[cur_node].val = func(updateUtil(left_child(cur_node), i), updateUtil(right_child(cur_node), i));

		return tree[cur_node].val;
	}

	// A recursive function to get the query value between l and r.
	T queryUtil(int cur_node, int l, int r)
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
	SegmentTree(vector<T>& _arr, function<T(T, T)> _func = [](T a, T b){return a+b;}, T _IDENTITY_VAL = 0)
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
		return queryUtil(0, l, r);
	}

	// Update the value at index i
	void update(int i, T new_val){
		arr[i] = new_val;
		updateUtil(0, i);
	}
};

void solve(){
	int n, Q;
	cin >> n >> Q;
	vi x(n);
	cin >> x;

	SegmentTree<int> s(x, [](int a, int b){return min(a, b);}, INT_MAX);

	FOR(q, Q){
		int a, b, c;
		cin >> a >> b >> c;

		if(a == 1)
			s.update(b-1, c);
		else
			cout << s.query(b-1, c-1) << nl;
	}
}

int main(){
	FAST;
	solve();
	cout << nl;
	
	return 0;
}