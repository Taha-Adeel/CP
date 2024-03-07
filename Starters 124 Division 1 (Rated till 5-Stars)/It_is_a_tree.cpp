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
    int person = 0;
    int depth = 0;
    map<int, int> depths;
    int score;
    vi adj_list;
};

void dfs(int root, int parent, V<Node>& tree) {
    for(int child: tree[root].adj_list) {
        if(child == parent) continue;
        tree[child].depth = tree[root].depth + 1;
        dfs(child, root, tree);
    }
}

void dfs2(int root, int parent, V<Node>& tree) {
    for (int child: tree[root].adj_list) {
        if (child == parent) continue;
        dfs2(child, root, tree);
        tree[root].depths[tree[child].depth] += tree[child].person;
        if (tree[child].depths.size() > tree[root].depths.size()) {
            swap(tree[child].depths, tree[root].depths);
        }
        for (auto& [d, f]: tree[child].depths) {
            tree[root].depths[d] += f;
        }
    }

    for (auto& [d, f]: tree[root].depths) {
        if (f == 1) {
            tree[root].score++;
        }
    }
}

void solve() {
    int n, q; cin >> n >> q;
    V<Node> tree(n);
    FOR (i, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].adj_list.pb(v);
        tree[v].adj_list.pb(u);
    }
    vi type(q), u(q);
    FOR(i, q) {
        cin >> type[i] >> u[i]; u[i]--;
    }

    dfs(0, -1, tree);

    auto subtask1 = [&]() {
        int score = 0;
        map<int, int> depth_cnt;
        FOR (i, q) {
            if (type[i] == 1) {
                cout << score << nl;
            } else {
                if (u[i] == 0) continue;
                if (tree[u[i]].person == 0) {
                    tree[u[i]].person = 1;
                    if (depth_cnt[tree[u[i]].depth] == 1) { score--; }
                    depth_cnt[tree[u[i]].depth]++;
                    if (depth_cnt[tree[u[i]].depth] == 1) { score++; }
                } else {
                    tree[u[i]].person = 0;
                    if (depth_cnt[tree[u[i]].depth] == 1) { score--; }
                    depth_cnt[tree[u[i]].depth]--;
                    if (depth_cnt[tree[u[i]].depth] == 1) { score++; }
                }
            }
        }
    };

    auto subtask2 = [&]() {
        int i = 0;
        for (; i < q; i++) {
            if (type[i] == 1) {
                dfs2(0, -1, tree);
                cout << tree[u[i]].score << nl;
                i++;
                break;
            } else {
                tree[u[i]].person ^= 1;
            }
        }

        for(; i < q; i++) {
            cout << tree[u[i]].score << nl;
        }
    };

    bool type1 = true;
    FOR (i, q) {
        if (type[i] == 1 && u[i] != 0) {
            type1 = false;
            break;
        }
    }

    if (type1) {
        subtask1();
    } else {
        subtask2();
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