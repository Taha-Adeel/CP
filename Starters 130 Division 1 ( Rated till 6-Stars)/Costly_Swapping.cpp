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
    ll n, c, s, m; cin >> n >> c >> s >> m;
    vll a(n); cin >> a;

    vll dec = a, inc = a;
    dec.sort_dsc();
    inc.sort();

    vll idx(n), idx_dec(n), idx_inc(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) { return a[i] > a[j]; });
    for (int i = 0; i < n; i++) {
        idx_dec[idx[i]] = i;
    }
    sort(all(idx), [&](int i, int j) { return a[i] < a[j]; });
    for (int i = 0; i < n; i++) {
        idx_inc[idx[i]] = i;
    }
    inc = vll(n, 0);

    // Seg trees
    vll indicator_dec(n, 1), indicator_inc(n, 0);
    SegmentTree<ll> seg_dec(dec), seg_inc(inc);
    SegmentTree<ll> seg_count_dec(indicator_dec), seg_count_inc(indicator_inc);

    ll ans = c * n, cur_sum = 0;
    auto check = [&](int x, int y) { // Check if x ingredients with y swaps is valid or not
        // Find smallest i s.t. seg_count_dec.query(0, i) >= y using binary search
        if (y == 0) {
            return cur_sum > m;
        }
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (seg_count_dec.query(0, mid) >= y) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (seg_count_dec.query(0, l) < y) return false;
        ll dec_sum = seg_dec.query(0, l);

        // Find smallest j s.t. seg_count_inc.query(0, j) >= y using binary search
        l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (seg_count_inc.query(0, mid) >= y) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (seg_count_inc.query(0, l) < y) return false;
        ll inc_sum = seg_inc.query(0, l);

        ll max_sum = cur_sum + dec_sum - inc_sum;

        return (max_sum > m);
    };

    for (int x = 0; x < n; x++) { // Chef buys <= x ingredients and stops
        if (cur_sum + a[x] > m) {
            ans = min(ans, c * x);
            break;
        }

        cur_sum += a[x];
        seg_dec.update(idx_dec[x], 0);
        seg_inc.update(idx_inc[x], a[x]);
        seg_count_dec.update(idx_dec[x], 0);
        seg_count_inc.update(idx_inc[x], 1);

        // We use binary search to find min y (number of swaps) such that check(x, y) is true
        int l = 0, r = min(x + 1, int(n) - x - 1);
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(x, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (check(x, l)) {
            ans = min(ans, c * x + s * l);
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