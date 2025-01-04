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
struct Node {
    T prefix_min;  // Minimum value in the segment
    T max_diff;    // Maximum value of (a[i] - min(a[0..i])) in the segment
    T max_val;     // Maximum value in the segment (needed for merging max_diff)
    int l, r;      // Starting and ending indexes of the segment
};

template<typename T = int>
class SegmentTree1 {
    vector<T>& arr;              // The array to update and query on
    vector<Node<T>> tree;        // Internal array representing the segment tree

    int left_child(int cur_node) { return 2 * cur_node + 1; }
    int right_child(int cur_node) { return 2 * cur_node + 2; }

    // Merge function to combine two nodes
    Node<T> merge(const Node<T>& left, const Node<T>& right) {
        Node<T> result;
        result.prefix_min = min(left.prefix_min, right.prefix_min);
        result.max_val = max(left.max_val, right.max_val);
        result.max_diff = max({
            left.max_diff, 
            right.max_diff,
            right.max_val - left.prefix_min
        });
        result.l = left.l;
        result.r = right.r;
        return result;
    }

    // Construct the segment tree
    Node<T> constructSTUtil(int cur_node, int l, int r) {
        tree[cur_node].l = l;
        tree[cur_node].r = r;

        if (l == r) {
            tree[cur_node].prefix_min = arr[l];
            tree[cur_node].max_val = arr[l];
            tree[cur_node].max_diff = 0;  // Single element: no valid difference
        } else {
            int m = (l + r) / 2;
            auto left = constructSTUtil(left_child(cur_node), l, m);
            auto right = constructSTUtil(right_child(cur_node), m + 1, r);
            tree[cur_node] = merge(left, right);
        }

        return tree[cur_node];
    }

    // Update the segment tree after a point update
    Node<T> updateUtil(int cur_node, int i) {
        if (tree[cur_node].l == tree[cur_node].r && tree[cur_node].l == i) {
            tree[cur_node].prefix_min = arr[i];
            tree[cur_node].max_val = arr[i];
            tree[cur_node].max_diff = 0;  // Single element
        } else if (i >= tree[cur_node].l && i <= tree[cur_node].r) {
            auto left = updateUtil(left_child(cur_node), i);
            auto right = updateUtil(right_child(cur_node), i);
            tree[cur_node] = merge(left, right);
        }

        return tree[cur_node];
    }

    // Query the maximum difference over a range
    Node<T> queryUtil(int cur_node, int l, int r) {
        if (tree[cur_node].l >= l && tree[cur_node].r <= r) 
            return tree[cur_node];
        if (tree[cur_node].r < l || tree[cur_node].l > r) 
            return {numeric_limits<T>::max(), numeric_limits<T>::min(), numeric_limits<T>::min(), -1, -1};

        auto left = queryUtil(left_child(cur_node), l, r);
        auto right = queryUtil(right_child(cur_node), l, r);
        return merge(left, right);
    }

public:
    // Constructor
    SegmentTree1(vector<T>& _arr) : arr(_arr) {
        int height = 1;
        for (int nodes = 1; nodes < (int)arr.size(); nodes *= 2)
            height++;
        tree.resize((1 << height) - 1);

        constructSTUtil(0, 0, arr.size() - 1);
    }

    // Return the maximum difference across the entire array
    T query() {
        return tree[0].max_diff;
    }

    // Update the value at index i
    void update(int i, T new_val) {
        arr[i] = new_val;
        updateUtil(0, i);
    }
};

template<typename T = int>
class SegmentTree2 {
    vector<T>& arr;              // The array to update and query on
    vector<Node<T>> tree;        // Internal array representing the segment tree

    int left_child(int cur_node) { return 2 * cur_node + 1; }
    int right_child(int cur_node) { return 2 * cur_node + 2; }

    // Merge function to combine two nodes
    Node<T> merge(const Node<T>& left, const Node<T>& right) {
        Node<T> result;
        result.prefix_min = min(left.prefix_min, right.prefix_min);
        result.max_val = max(left.max_val, right.max_val);
        result.max_diff = max({
            left.max_diff, 
            right.max_diff,
            left.max_val - right.prefix_min
        });
        result.l = left.l;
        result.r = right.r;
        return result;
    }

    // Construct the segment tree
    Node<T> constructSTUtil(int cur_node, int l, int r) {
        tree[cur_node].l = l;
        tree[cur_node].r = r;

        if (l == r) {
            tree[cur_node].prefix_min = arr[l];
            tree[cur_node].max_val = arr[l];
            tree[cur_node].max_diff = 0;  // Single element: no valid difference
        } else {
            int m = (l + r) / 2;
            auto left = constructSTUtil(left_child(cur_node), l, m);
            auto right = constructSTUtil(right_child(cur_node), m + 1, r);
            tree[cur_node] = merge(left, right);
        }

        return tree[cur_node];
    }

    // Update the segment tree after a point update
    Node<T> updateUtil(int cur_node, int i) {
        if (tree[cur_node].l == tree[cur_node].r && tree[cur_node].l == i) {
            tree[cur_node].prefix_min = arr[i];
            tree[cur_node].max_val = arr[i];
            tree[cur_node].max_diff = 0;  // Single element
        } else if (i >= tree[cur_node].l && i <= tree[cur_node].r) {
            auto left = updateUtil(left_child(cur_node), i);
            auto right = updateUtil(right_child(cur_node), i);
            tree[cur_node] = merge(left, right);
        }

        return tree[cur_node];
    }

    // Query the maximum difference over a range
    Node<T> queryUtil(int cur_node, int l, int r) {
        if (tree[cur_node].l >= l && tree[cur_node].r <= r) 
            return tree[cur_node];
        if (tree[cur_node].r < l || tree[cur_node].l > r) 
            return {numeric_limits<T>::max(), numeric_limits<T>::min(), numeric_limits<T>::min(), -1, -1};

        auto left = queryUtil(left_child(cur_node), l, r);
        auto right = queryUtil(right_child(cur_node), l, r);
        return merge(left, right);
    }

public:
    // Constructor
    SegmentTree2(vector<T>& _arr) : arr(_arr) {
        int height = 1;
        for (int nodes = 1; nodes < (int)arr.size(); nodes *= 2)
            height++;
        tree.resize((1 << height) - 1);

        constructSTUtil(0, 0, arr.size() - 1);
    }

    // Return the maximum difference across the entire array
    T query() {
        return tree[0].max_diff;
    }

    // Update the value at index i
    void update(int i, T new_val) {
        arr[i] = new_val;
        updateUtil(0, i);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;

    vi b = a, c = a;
    for (int i = 0; i < n; i++) {
        b[i] -= i;
        c[i] += i;
    }

    SegmentTree1<int> st_b(b);
    SegmentTree2<int> st_c(c);
    cout << max(st_b.query(), st_c.query()) << nl;

    while (q--) {
        int i, x; cin >> i >> x; i--;

        st_b.update(i, x - i);
        st_c.update(i, x + i);
        cout << max(st_b.query(), st_c.query()) << nl;
    }
}

int main() {
    FAST;
    int T; cin >> T;
    FOR(t, T) {
        solve();
    }
    
    return 0;
}