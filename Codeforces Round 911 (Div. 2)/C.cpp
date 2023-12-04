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

struct Node {
    char dir;
    int l, r;
    int ans = MOD;
};

void dfs(int root, V<Node>& tree) {
    if(root == 0) return;
    
    dfs(tree[root].l, tree);
    dfs(tree[root].r, tree);

    if(tree[root].l == 0 && tree[root].r == 0) {
        tree[root].ans = 0;
        return;
    }
    
    int min_ans = min(tree[tree[root].l].ans, tree[tree[root].r].ans);
    if(tree[root].dir == 'U') tree[root].ans = min_ans + 1;
    else if(tree[root].dir == 'L') tree[root].ans = min_ans + (tree[tree[root].l].ans != min_ans);
    else tree[root].ans = min_ans + (tree[tree[root].r].ans != min_ans);
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    V<Node> tree(n+1);
    FOR(i, n) {
        int l, r; cin >> l >> r;
        tree[i+1] = {s[i], l, r};
    }

    dfs(1, tree);

    cout << tree[1].ans;
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