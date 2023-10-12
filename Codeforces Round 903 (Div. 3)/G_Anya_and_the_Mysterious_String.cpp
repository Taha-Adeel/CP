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
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
#define pY {cout << "YES"; return;}
#define pN {cout << "NO";  return;}
#define display(x) if(x) pY else pN

#define FOR(i, n)                for(int i = 0; i < (int)n; ++i)
#define FOR1(i, n)               for(int i = 1; i <= (int)n; ++i)
#define ROF(i, n)                for(int i = (int)n-1; i >= 0; --i)
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

    // Debug function to print the segment tree
    void print(){
        for(int i = 0; i < n; i++) cerr << query(i, i) << ' '; cerr << nl;
    }
};

class LazySegTreeCharAdd: public LazySegmentTreeBase<char, ll> {
    char f_query(char x, char y) override {return ((x-'a') + (y-'a'))%26 + 'a';}
    ll& f_combine_tag(ll& tag, ll new_update) override {return tag = (tag + new_update)%26;}
    void consume_tag(int node_id) override {tree[node_id].val = (tree[node_id].val-'a' + tree[node_id].tag)%26 + 'a';}
public:
    LazySegTreeCharAdd(V<char>& a): LazySegmentTreeBase<char, ll>(a) {
        identity_q = 'a';
        identity_u = 0;
        build(0, 0, n-1);
    }
};

template<typename T = int>
class SegmentTree{
    vector<T>& arr;            // The array which we update and query on.
    vector<Node<T>> tree;    // Internal array representing the segment tree;

    function<T(T, T)> func;     // The type of query to perform (Eg, min/max/sum/gcd)
    T IDENTITY_VAL;                // The identity value for the above function

    int parent(int cur_node)        {return (cur_node - 1)/2;}
    int left_child(int cur_node)    {return 2 * cur_node + 1;}
    int right_child(int cur_node)    {return 2 * cur_node + 2;}

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
        int height = 1;    // Height of segment tree
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
    int n, m; cin >> n >> m;
    V<char> s(n); cin >> s; 

    LazySegTreeCharAdd lazy_st(s);

    // Array to hold 2 length palindromes
    vi palin_2(n, 0);
    FOR(i, n-1) if(s[i] == s[i+1]) palin_2[i]++, palin_2[i+1]++;
    SegmentTree st_2(palin_2);

    // Array to hold 3 length palindromes
    vi palin_3(n, 0);
    FOR(i, n-2) if(s[i] == s[i+2]) palin_3[i]++, palin_3[i+2]++;
    SegmentTree st_3(palin_3);
    cerr << s << nl;
    cerr << palin_2 << nl;
    cerr << palin_3 << nl << nl;

    FOR(_, m){
        int t, l, r; cin >> t >> l >> r; l--, r--;
        if(t == 1){
            int x; cin >> x; x %= 26;

            char l_old = lazy_st.query(l, l), r_old = lazy_st.query(r, r), l1_old, r1_old;
            if(l != r) l1_old = lazy_st.query(l+1, l+1), r1_old = lazy_st.query(r-1, r-1);

            lazy_st.update(l, r, x);
            lazy_st.print();

            char l_new = lazy_st.query(l, l), r_new = lazy_st.query(r, r), l1_new, r1_new;
            if(l != r) l1_new = lazy_st.query(l+1, l+1), r1_new = lazy_st.query(r-1, r-1);

            if(l > 0){
                char l_pred = lazy_st.query(l-1, l-1);
                if(l_old == l_pred && l_new != l_pred) st_2.update(l-1, palin_2[l-1]-1), st_2.update(l, palin_2[l]-1);
                else if(l_old != l_pred && l_new == l_pred) st_2.update(l-1, palin_2[l-1]+1), st_2.update(l, palin_2[l]+1);

                if(l != r){
                    if(l1_old == l_pred && l1_new != l_pred) st_3.update(l-1, palin_3[l-1]-1), st_3.update(l+1, palin_3[l+1]-1);
                    else if(l1_old != l_pred && l1_new == l_pred) st_3.update(l-1, palin_3[l-1]+1), st_3.update(l+1, palin_3[l+1]+1);
                }
            }
            if(l > 1){
                char l_pred = lazy_st.query(l-2, l-2);
                if(l_old == l_pred && l_new != l_pred) st_3.update(l-2, palin_3[l-2]-1), st_3.update(l, palin_3[l]-1);
                else if(l_old != l_pred && l_new == l_pred) st_3.update(l-2, palin_3[l-2]+1), st_3.update(l, palin_3[l]+1);
            }

            if(r < n-1){
                char r_succ = lazy_st.query(r+1, r+1);
                if(r_old == r_succ && r_new != r_succ) st_2.update(r, palin_2[r]-1), st_2.update(r+1, palin_2[r+1]-1);
                else if(r_old != r_succ && r_new == r_succ) st_2.update(r, palin_2[r]+1), st_2.update(r+1, palin_2[r+1]+1);

                if(l != r){
                    if(r1_old == r_succ && r1_new != r_succ) st_3.update(r-1, palin_3[r-1]-1), st_3.update(r+1, palin_3[r+1]-1);
                    else if(r1_old != r_succ && r1_new == r_succ) st_3.update(r-1, palin_3[r-1]+1), st_3.update(r+1, palin_3[r+1]+1);
                }
            }
            if(r < n-2){
                char r_succ = lazy_st.query(r+2, r+2);
                if(r_old == r_succ && r_new != r_succ) st_3.update(r, palin_3[r]-1), st_3.update(r+2, palin_3[r+2]-1);
                else if(r_old != r_succ && r_new == r_succ) st_3.update(r, palin_3[r]+1), st_3.update(r+2, palin_3[r+2]+1);
            }
            cerr << palin_2 << nl;
            cerr << palin_3 << nl << nl;
        }
        else{
            string ans = "YES";
            if(r - l + 1 == 2 || r - l + 1 == 3)
                if(lazy_st.query(l, l) == lazy_st.query(r, r)) ans = "NO";
            
            if(r - l + 1 >= 3)
                if(st_2.query(l+1, r-1) > 0) ans = "NO";
            
            if(r - l + 1 == 4)
                if(lazy_st.query(l, l) == lazy_st.query(l+2, l+2) || lazy_st.query(l+1, l+1) == lazy_st.query(l+3, l+3)) ans = "NO";
            
            if(r - l + 1 == 5)
                if(lazy_st.query(l, l) == lazy_st.query(l+2, l+2) || lazy_st.query(l+1, l+1) == lazy_st.query(l+3, l+3) || lazy_st.query(l+2, l+2) == lazy_st.query(l+4, l+4)) ans = "NO";

            if(r - l + 1 >= 6)
                if(st_3.query(l+2, r-2) > 0) ans = "NO";

            cout << ans << nl;
            cerr << ans << nl;
        }
    }
}

int main(){
    FAST;
    int T;
    cin >> T;
    FOR(t, T){
        solve();
    }
    
    return 0;
}