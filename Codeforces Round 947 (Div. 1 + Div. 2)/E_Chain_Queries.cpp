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
    int color = 0;
    int parent = -1;
    int black_child_cnt = 0;
    vi adj_list;
};

void dfs(int u, int p, V<Node>& tree) {
    tree[u].parent = p;
    for (int v: tree[u].adj_list) {
        if (v == p) continue;
        tree[u].black_child_cnt += tree[v].color;
        dfs(v, u, tree);
    }
}

void solve() {
    int n, q; cin >> n >> q;
    V<Node> tree(n);
    FOR (i, n) {
        cin >> tree[i].color;
    }
    FOR (i, n - 1) {
        int u, v; cin >> u >> v; --u, --v;
        tree[u].adj_list.pb(v);
        tree[v].adj_list.pb(u);
    }

    dfs(0, -1, tree);

    vi cnt(4, 0); // cnt[i] = freq of black vertices with i black children (i = 3 means >= 3 black children)
    set<int> deg_2;
    int white_p_cnt = 0;
    FOR (i, n) {
        if (tree[i].color == 1) {
            cnt[min(3, tree[i].black_child_cnt)]++;
            if (tree[i].black_child_cnt == 2) {
                deg_2.insert(i);
            }
            if (tree[i].parent == -1 or tree[tree[i].parent].color == 0) {
                white_p_cnt++;
            }
        }
    }

    FOR (i, q) {
        int u; cin >> u; u--;

        if (tree[u].color == 1) {
            tree[u].color = 0;
            cnt[min(3, tree[u].black_child_cnt)]--;
            if (tree[u].black_child_cnt == 2) {
                deg_2.erase(u);
            }
            if (tree[u].parent == -1 or tree[tree[u].parent].color == 0) {
                white_p_cnt--;
            }
            white_p_cnt += tree[u].black_child_cnt;
            if (tree[u].parent != -1) {
                if (tree[tree[u].parent].color == 1) {
                    cnt[min(3, tree[tree[u].parent].black_child_cnt)]--;
                    if (tree[tree[u].parent].black_child_cnt == 2) {
                        deg_2.erase(tree[u].parent);
                    }
                }
                tree[tree[u].parent].black_child_cnt--;
                if (tree[tree[u].parent].color == 1) {
                    cnt[min(3, tree[tree[u].parent].black_child_cnt)]++;
                    if (tree[tree[u].parent].black_child_cnt == 2) {
                        deg_2.insert(tree[u].parent);
                    }
                }
            }
        } else {
            tree[u].color = 1;
            cnt[min(3, tree[u].black_child_cnt)]++;
            if (tree[u].black_child_cnt == 2) {
                deg_2.insert(u);
            }
            if (tree[u].parent == -1 or tree[tree[u].parent].color == 0) {
                white_p_cnt++;
            }
            white_p_cnt -= tree[u].black_child_cnt;
            if (tree[u].parent != -1) {
                if (tree[tree[u].parent].color == 1) {
                    cnt[min(3, tree[tree[u].parent].black_child_cnt)]--;
                    if (tree[tree[u].parent].black_child_cnt == 2) {
                        deg_2.erase(tree[u].parent);
                    }
                }
                tree[tree[u].parent].black_child_cnt++;
                if (tree[tree[u].parent].color == 1) {
                    cnt[min(3, tree[tree[u].parent].black_child_cnt)]++;
                    if (tree[tree[u].parent].black_child_cnt == 2) {
                        deg_2.insert(tree[u].parent);
                    }
                }
            }   
        }

        if (cnt[3] == 0 and cnt[2] <= 1 and white_p_cnt == 1) {
            if (cnt[2] == 0 or tree[*deg_2.begin()].parent == -1 or tree[tree[*deg_2.begin()].parent].color == 0) {
                cout << "Yes" << nl;
            } else {
                cout << "No" << nl;
            }
        } else {
            cout << "No" << nl;
        }
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