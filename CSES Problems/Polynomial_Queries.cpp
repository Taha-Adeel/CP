#include <bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0)
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()            {std::sort(this->begin(), this->end());}
    void sort_dsc()     {std::sort(this->begin(), this->end(), greater<T>());}
    auto sum()             {T sum = 0; for(auto& i: *this) sum += i; return sum;}
    auto freqs()         {map<T, int> freq; for(auto& i: *this) freq[i]++; return freq;}
    auto indices()        {int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
    auto prefix_sums()     {int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
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

template<typename T = int, typename U = int>
struct Node{
    T val; // Value of the range represented by current node
    U tag; // Tag value that needs to be propagated lazily
    int l, r; // Starting and ending indexes of the segment represented by current node
};

template<typename T = int, typename U = int>
class LazySegmentTreeBase{
protected:
    int n; // Size of the array
    V<T>& a; // The array which we update and query on.
    V<Node<T, U>> tree; // Internal array representing the segment tree;

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

// Update tag consists of (a, d) where a is the first term and d is the common difference
class LazySegmentTreeAP: public LazySegmentTreeBase<ll, pll> {
private:
    ll f_query(ll x, ll y) override {return x + y;}
    pll& f_combine_tag(pll& tag, pll new_update) override {tag.F += new_update.F; tag.S += new_update.S; return tag;}

    // Add the AP summation to the node using the n/2 * (2a + (n-1)d) formula
    void consume_tag(int node_id) override {
        tree[node_id].val += (tree[node_id].r - tree[node_id].l + 1) * (2 * tree[node_id].tag.F + (tree[node_id].r - tree[node_id].l) * tree[node_id].tag.S) / 2;
    }

    void propagate(int cur) override {
        if(tree[cur].tag == identity_u) return;
        if(tree[cur].l != tree[cur].r){
            f_combine_tag(tree[left(cur)].tag, tree[cur].tag);
            f_combine_tag(tree[right(cur)].tag, {tree[cur].tag.F + (tree[left(cur)].r - tree[left(cur)].l + 1) * tree[cur].tag.S, tree[cur].tag.S});
        }
        consume_tag(cur);
        tree[cur].tag = identity_u;
    }

    void _update(int cur, int l, int r, pll new_update) override {
        propagate(cur);
        if(tree[cur].r < l || tree[cur].l > r) return;
        if(tree[cur].l >= l && tree[cur].r <= r){
            f_combine_tag(tree[cur].tag, {new_update.F + (tree[cur].l - l) * new_update.S, new_update.S});
            propagate(cur);
            return;
        }
        _update(left(cur), l, r, new_update);
        _update(right(cur), l, r, new_update);
        tree[cur].val = f_query(tree[left(cur)].val, tree[right(cur)].val);
    }

public:
    LazySegmentTreeAP(V<ll>& a): LazySegmentTreeBase<ll, pll>(a){
        identity_q = 0;
        identity_u = {0, 0};
        build(0, 0, n-1);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vll a(n); cin >> a;

    LazySegmentTreeAP st(a);
    FOR(_, q){
        int t, l, r; cin >> t >> l >> r; l--; r--;
        if(t == 1)
            st.update(l, r, {1, 1});
        else
            cout << st.query(l, r) << nl;
    }
}

int main(){
    solve();
    cout << nl;
    
    return 0;
}