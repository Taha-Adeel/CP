#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

struct Node{
	int val;
	int l, r; // Starting and ending indexes of the segment represented by current node
};

class SegmentTree{
	vi& arr;  		// The array which we update and query on.
	vector<Node> tree; 	// Internal array representing the segment tree;
	int height;		// Height of segment tree

	function<int(int, int)> func; 	// The type of query to perform (Eg, min/max/sum/gcd)
	int IDENTITY_VAL;				// The identity value for the above function

	int parent(int cur_node) 		{return (cur_node - 1)/2;}
	int left_child(int cur_node) 	{return 2 * cur_node + 1;}
	int right_child(int cur_node)  	{return 2 * cur_node + 2;}

	// A recursive function that constructs Segment Tree for array[ss..se].
	int constructSTUtil(int cur_node, int ss, int se){
		tree[cur_node].l = ss;
		tree[cur_node].r = se;

		if (tree[cur_node].l == tree[cur_node].r){
			tree[cur_node].val = arr[tree[cur_node].l];
			return tree[cur_node].val;
		}

		// If there are more than one elements, then recur for left and right subtrees and store the result of two values in this node
		int m = (tree[cur_node].l + tree[cur_node].r)/2;
		tree[cur_node].val = func(constructSTUtil(left_child(cur_node), ss, m), constructSTUtil(right_child(cur_node), m + 1, se));

		return tree[cur_node].val;
	}

	// A recursive function to update the nodes which have i within its range 
	int updateValueUtil(int cur_node, int i, int new_val)
	{
		if (i < tree[cur_node].l || i > tree[cur_node].r)
			return IDENTITY_VAL;
		else if(tree[cur_node].l == tree[cur_node].r){
			tree[cur_node].val = new_val;
			return tree[cur_node].val;
		}
		else
			tree[cur_node].val = func(updateValueUtil(left_child(cur_node), i, new_val), updateValueUtil(right_child(cur_node), i, new_val));
	}

	// A recursive function to get the query value between l and r.
	int queryUtil(int cur_node, int l, int r){
		if(tree[cur_node].l >= l && tree[cur_node].r <= r) 
			return tree[cur_node].val;
		else if(tree[cur_node].r < l || tree[cur_node].l > r)
			return IDENTITY_VAL;
		else
			return func(queryUtil(left_child(cur_node), l, r), queryUtil(right_child(cur_node), l, r));
	}

public:
	// Constructor
	SegmentTree(vi& _arr, function<int(int, int)> _func = [](int a, int b){return a+b;}, int _IDENTITY_VAL = 0)
		:arr(_arr), func(_func), IDENTITY_VAL(_IDENTITY_VAL)
	{
		height = 1;
		for(int nodes = 1; nodes < arr.size(); nodes *= 2)
			height++;
		tree.reserve((1<<height) - 1);

		constructSTUtil(0, 0, arr.size() - 1);
	}

	// Return query value between l and r (inclusive).
	int query(int l, int r){ 
		return queryUtil(0, l, r);
	}

	// Update the value at index i
	void update(int new_val, int i){
		arr[i] = new_val;
		updateValueUtil(0, i, new_val);
	}
};