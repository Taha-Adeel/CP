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

int M = -1;
class Z {
    int val;
public:
    Z(ll v = 0) : val(v%M) { if(val < 0) val += M;}

    Z pow(ll e) const { Z res = 1; for(Z b = val; e > 0; b = b*b, e /= 2) if(e & 1) res = res*b; return res; }
    Z inv() const { return pow(M-2); }

    Z operator+(const Z& o) const { return Z(val + o.val); }
    Z operator-(const Z& o) const { return Z(val - o.val); }
    Z operator*(const Z& o) const { return Z((ll)val * o.val); }
    Z operator/(const Z& o) const { return *this * o.inv(); }
    Z operator-() const { return Z(-val); }
    Z operator+=(const Z& o) { return *this = *this + o; }
    Z operator-=(const Z& o) { return *this = *this - o; }
    Z operator*=(const Z& o) { return *this = *this * o; }
    Z operator/=(const Z& o) { return *this = *this / o; }
    bool operator==(const Z& o) const { return val == o.val; }
    bool operator!=(const Z& o) const { return val != o.val; }

    friend istream& operator>>(istream& in, Z& z) { ll v; in >> v; z = Z(v); return in; }
    friend ostream& operator<<(ostream& out, const Z& z) { return out << z.val; }
};

template<typename T = int>
struct Node {
    T val;
    int l, r; // Starting and ending indexes of the segment represented by current node
};

template<typename T = int>
class SegmentTree {
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
    SegmentTree(vector<T>& _arr, function<T(T, T)> _func = [](T a, T b){return a*b;}, T _IDENTITY_VAL = 1)
        :arr(_arr), func(_func), IDENTITY_VAL(_IDENTITY_VAL)
    {
        int height = 1;    // Height of segment tree
        for(int nodes = 1; nodes < (int)arr.size(); nodes *= 2)
            height++;
        tree.reserve((1<<height) - 1);

        constructSTUtil(0, 0, arr.size() - 1);
    }

    // Return query value between l and r (inclusive).
    T query(int l, int r) {
        if(l > r)
            swap(l, r);
        return queryUtil(0, l, r);
    }

    // Update the value at index i
    void update(int i, T new_val) {
        arr[i] = new_val;
        updateUtil(0, i);
    }
};

void solve() {
    int n, k; cin >> n >> k >> M;
    V<Z> a(n); cin >> a;

    Z ans = 0, res = 0, prod = 1, prev_sum = 0;
    for (int i = k - 1; i >= 0; i--) {
        res = a[i] * (res + 1);
        ans += res;

        prod *= a[i];
        prev_sum += prod;
    }

    SegmentTree<Z> st(a);

    for (int i = k; i < n; i++) {
        prod = st.query(i - k, i - 1);
        prev_sum = a[i] * (prev_sum - prod + 1);
        ans += prev_sum;
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