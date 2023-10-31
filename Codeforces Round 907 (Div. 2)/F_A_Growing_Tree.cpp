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
#define rall(v)       v.rbegin(), v.rend()

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
};

V<pii> get_euler_ordering(V<Node>& tree){
    int n = tree.size();
    int timer = 0;
    V<pii> ranges(n);

    function<void(int, int)> dfs = [&](int root, int parent){
        ranges[root].F = timer++;
        for(auto& child: tree[root].adj_list) if(child != parent)
            dfs(child, root);
        ranges[root].S = timer++;
    };

    dfs(0, -1);

    return ranges;
}

template<typename T = int, typename U = int>
struct SegTreeNode{
    T val; // Value of the range represented by current node
    U tag; // Tag value that needs to be propagated lazily
    int l, r; // Starting and ending indexes of the segment represented by current node
};

template<typename T = int, typename U = int>
class LazySegmentTreeBase{
protected:
    int n; // Size of the array
    V<T>& a; // The array which we update and query on.
    V<SegTreeNode<T, U>> tree; // Internal array representing the segment tree;

    // Util functions
    int parent(int cur) {return (cur - 1)/2;}
    int left(int cur) {return 2 * cur + 1;}
    int right(int cur) {return 2 * cur + 2;}

    // Virtual functions that should be overridden by the child class
    T identity_q; // Identity element for the query function
    U identity_u; // Identity element for the update function
    virtual T f_query(T x, T y) = 0; // Function to query on the segment tree
    virtual U& f_combine_tag(U& tag, U new_update) = 0; // Function to combine tags
    virtual void consume_tag(int node_id) = 0; // Function to consume the tag

    // Propagate the tag to the children
    virtual void propagate(int cur){
        if(tree[cur].tag == identity_u) return;
        if(tree[cur].l != tree[cur].r){
            f_combine_tag(tree[left(cur)].tag, tree[cur].tag);
            f_combine_tag(tree[right(cur)].tag, tree[cur].tag);
        }
        consume_tag(cur);
        tree[cur].tag = identity_u;
    }

    // A recursive function to update the nodes which have i within its range 
    virtual void _update(int cur, int l, int r, U new_update){
        propagate(cur);
        if(tree[cur].r < l || tree[cur].l > r) return;
        if(tree[cur].l >= l && tree[cur].r <= r){
            f_combine_tag(tree[cur].tag, new_update);
            propagate(cur);
            return;
        }
        _update(left(cur), l, r, new_update);
        _update(right(cur), l, r, new_update);
        tree[cur].val = f_query(tree[left(cur)].val, tree[right(cur)].val);
    }

    // Build the segment tree
    void build(int cur, int l, int r){
        tree[cur].l = l;
        tree[cur].r = r;
        if(l == r){
            tree[cur].val = a[l];
            tree[cur].tag = identity_u;
            return;
        }
        int mid = (l + r)/2;
        build(left(cur), l, mid);
        build(right(cur), mid + 1, r);
        tree[cur].val = f_query(tree[left(cur)].val, tree[right(cur)].val);
        tree[cur].tag = identity_u;
    }
    
private:
    // A recursive function to get the query value between l and r.
    T query(int cur, int l, int r){
        propagate(cur);
        if(tree[cur].r < l || tree[cur].l > r) return identity_q;
        if(tree[cur].l >= l && tree[cur].r <= r) return tree[cur].val;
        return f_query(query(left(cur), l, r), query(right(cur), l, r));
    }

public:
    LazySegmentTreeBase(V<T>& a): a(a){
        n = a.size();
        tree.resize(4*n);
    }

    // Update the segment tree
    void update(int l, int r, U val){
        _update(0, l, r, val);
    }

    // Query the segment tree
    T query(int l, int r){
        return query(0, l, r);
    }
};

class AddLazySegTree: public LazySegmentTreeBase<ll, ll>{
    ll f_query(ll x, ll y) {return x + y;}
    ll& f_combine_tag(ll& tag, ll new_update) {tag += new_update; return tag;}
    void consume_tag(int node_id) {tree[node_id].val += tree[node_id].tag;}
public:
    AddLazySegTree(V<ll>& a): LazySegmentTreeBase<ll, ll>(a){
        identity_q = 0;
        identity_u = 0;
        build(0, 0, n-1);
    }
};

void solve(){
    int q; cin >> q;
    V<array<int, 3>> queries(q);

    // Build the tree
    V<Node> tree; tree.pb({}); // Root node
    for(auto& [type, u, x]: queries){
        cin >> type >> u; u--;
        if (type == 1){
            x = tree.size();
            tree.pb({});
            tree[x].adj_list.pb(u);
            tree[u].adj_list.pb(x);
        }
        else
            cin >> x;
    }
    int n = tree.size();

    // Get the euler ordering
    auto ranges = get_euler_ordering(tree);

    // Make the segment tree
    vll a(2*n, 0);
    AddLazySegTree seg_tree(a);

    // Process the queries
    reverse(all(queries));
    vll ans(n, -1);
    for(auto& [type, u, x]: queries){
        if (type == 1)
            ans[x] = seg_tree.query(ranges[x].F, ranges[x].F);
        else
            seg_tree.update(ranges[u].F, ranges[u].S, x);
    }

    // Display answer
    ans[0] = seg_tree.query(ranges[0].F, ranges[0].F);
    cout << ans;
}

int main(){
    FAST;
    int T; cin >> T;
    FOR(t, T){
        solve();
        cout << nl;
    }
    
    return 0;
}