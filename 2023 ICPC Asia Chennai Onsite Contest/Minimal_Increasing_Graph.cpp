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

struct Node{
	int depth = 0;
	vi superior;
	vi adj_list;
};

// O(n+m log n)
void dfs(int root, V<Node>& tree){
	for(auto& child: tree[root].adj_list){
		tree[child].depth = tree[root].depth + 1;
		tree[child].superior.pb(root);
		for(int k = 1; (1<<k) <= tree[child].depth; k++)
			tree[child].superior.pb(tree[tree[child].superior[k-1]].superior[k-1]);
		
		dfs(child, tree);
	}
}

// O(log k)
int get_kth_ancestor(int x, int k, V<Node>& tree){
	if(k == -1) return x;
	if(k >= tree[x].depth) return -1;
	int ancestor = tree[x].superior[0];
	for(int mask = 0; (1 << mask) <= k; mask++)
		if((1 << mask) & k)
			ancestor = tree[ancestor].superior[mask];
	
	return ancestor;
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    // Connect each node with the closest smaller element on the right of it
    stack<int> s;
    vi roots;
    V<Node> tree(n);
    for (int i = n - 1; i >= 0; i--) {
        while(!s.empty() && a[s.top()] > a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            tree[s.top()].adj_list.pb(i);
        } else {
            roots.pb(i);
        }
        s.push(i);
    }
    
    for (auto& root: roots) {
        dfs(root, tree);
    }

    ll ans = 0;
    s = stack<int>(); // Find the closest larger element on the right of it
    for (int i = n - 1; i >= 0; i--) {
        while(!s.empty() && a[s.top()] < a[i]) {
            s.pop();
        }

        if (!s.empty()) {
            int l = 0, r = tree[s.top()].depth;
            // Find largest m s.t. a[get_kth_ancestor(i, m - 1, tree)] > a[i]
            while(l < r){
                int m = (l+r)/2;
                cerr << m << ": " << a[get_kth_ancestor(s.top(), m - 1, tree)] << nl;
                if(a[get_kth_ancestor(s.top(), m - 1, tree)] < a[i])
                    r = m;
                else
                    l = m + 1;		
            }
            cerr << a[i] << ' ' << a[s.top()] << ' ' << l + 1 << nl;
            ans += l + 1;
        }

        s.push(i);
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